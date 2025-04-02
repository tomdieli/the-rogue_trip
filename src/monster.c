#include <rogue.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createMonster(Position room_dims)
{

    // Allocate memory for the new monster
    Entity* newMonster = calloc(1, sizeof(Entity));
    if (newMonster == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Generate random values for the monster's attributes
    int st_mod = rand() % 8;
    int dx_mod = 8 - st_mod;

    // Set the monster's attributes
    newMonster->pos.y = room_dims.y;
    newMonster->pos.x = room_dims.x;
    newMonster->ch = 'M';
    newMonster->color = COLOR_PAIR(VISIBLE_COLOR);
    newMonster->st = 8 + st_mod;
    newMonster->dx = 8 + dx_mod;
    newMonster->hits = newMonster->st;
    newMonster->gold = rand() % 3;

    // Allocate more memory for the monsters array
    Entity* new_monsters = realloc(monsters, (num_monsters + 1) * sizeof(Entity));
    if (new_monsters == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        free(newMonster);
        exit(1);
    }
    monsters = new_monsters;

    // Add the new monster to the array
    monsters[num_monsters] = *newMonster;
    map[newMonster->pos.y][newMonster->pos.x].walkable = false;
    num_monsters++;
}

// Function to free the allocated memory
// void freeMonsters()
// {
//     free(monsters);
//     monsters = NULL;
//     num_monsters = 0;
// }
