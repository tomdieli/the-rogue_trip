#include <rogue.h>

void combatPhase(Entity* player, Entity* monster)
{
    // Display combat message
    snprintf(status_message, 100, "You encountered a monster!");

    // Simple turn-based combat loop
    while (player->hits > 0 && monster->hits > 0)
    {
        // Player attacks monster
        monster->hits -= player->st;
        snprintf(status_message, 100, "You hit the monster! Monster HP: %d", monster->hits);
        drawEverything();
        getch(); // Wait for player input

        if (monster->hits <= 0)
        {
            snprintf(status_message, 100, "You defeated the monster!");
            break;
        }

        // Monster attacks player
        player->hits -= monster->st;
        snprintf(status_message, 100, "The monster hit you! Your HP: %d", player->hits);
        drawEverything();
        getch(); // Wait for player input

        if (player->hits <= 0)
        {
            snprintf(status_message, 100, "You were defeated by the monster!");
            break;
        }
    }

    // If the monster is defeated, remove it from the map
    if (monster->hits <= 0)
    {
        map[monster->pos.y][monster->pos.x].ch = '.';
        map[monster->pos.y][monster->pos.x].walkable = true;
    }
}