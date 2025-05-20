#include <rogue.h>

void combatPhase(Entity* player, Entity* monster)
{
    // Display combat message
    snprintf(status_message, 100, "You encountered a monster!");
    char ch = ' ';
    // Simple turn-based combat loop
    while (player->hits > 0 && monster->hits > 0 && ch != 'q')
    {
        // Draw the current state of the game
        drawEverything();

        // Display player and monster stats
        snprintf(status_message, 100, "Your HP: %d | Monster HP: %d", player->hits, monster->hits);
        //drawEverything();
        ch = getch(); // Wait for player input

        if (ch == 'q') break; // Exit combat if 'q' is pressed

        // Player attacks monster
        if (attack(player->dx))
        {
            // Calculate damage and apply it to the monster
            int damage = attack(player->st);
            monster->hits -= damage;
            snprintf(status_message, 100, "You hit the monster! Damage dealt: %d", damage);
        }
        else
        {
            snprintf(status_message, 100, "Your attack missed!");
        }

        if (monster->hits <= 0)
        {
            snprintf(status_message, 100, "You defeated the monster!");
            map[monster->pos.y][monster->pos.x].ch = '.';
            map[monster->pos.y][monster->pos.x].walkable = true;
            break;
        }
        draw_status_box(status_box);
        draw_info_box(player_info);

        getch();

        // Monster attacks player
        if (attack(monster->dx))
        {
            // Calculate damage and apply it to the player
            int damage = attack(monster->st);
            player->hits -= damage;
            snprintf(status_message, 100, "The monster hit you! Damage taken: %d", damage);
        }
        else
        {
            snprintf(status_message, 100, "The monster's attack missed!");
        }
        

        if (player->hits <= 0)
        {
            snprintf(status_message, 100, "You were defeated by the monster!");
            break;
        }
        draw_status_box(status_box);
        draw_info_box(player_info);
    }
}

int attack(int attack_dx){
    // Calculate the attack rolls
    int attack_rolls[3];
    int attack_roll = 0;
    int damage = 0;

    for (int i = 0; i < 3; i++)
    {
        attack_rolls[i] = rand() % 6 + 1; // Roll a d6
        attack_roll += attack_rolls[i];
    }
    

    // Determine if the attack hits
    if (attack_roll <= attack_dx)
    {
        // Calculate the damage
        damage = rand() % 6 + 1;

        // Display the result
        snprintf(status_message, 100, "Attack hits! Damage dealt: %d", damage);
        if (attack_roll == 3)
        {
            int crit_dmg = rand() % 6 + 1;
            snprintf(status_message, 100, "Attack is a critical hit! Another %d damage dealt!", crit_dmg);
            damage += crit_dmg;
        }
    }
    
    else if (attack_roll >= attack_dx)
    {
        snprintf(status_message, 100, "Attack is a miss!");
    }
    return damage;
}