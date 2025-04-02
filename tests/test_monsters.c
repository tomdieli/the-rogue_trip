#include <rogue.h>
#include <stdio.h>

int main(void)
{
    Position start = {
        .x = 5,
        .y = 5
    };
    Position rdims = {
        .x = 20,
        .y = 40
    };
    //createMonster(start, rdims);
    print_monsters();

}

void print_monster(Entity* m)
{
    printf("ST: %d, Age: %d\n", m->st, 30);
}

void print_monsters()
{
    for (size_t i = 0; i < sizeof(monsters); i++)
    {
        //Entity* monster = monsters[i];
        //print_monster(monster);
    }
}

// Function to print all monsters
// void printMonsters()
// {
//     for (size_t i = 0; i < monsters_size; i++) {
//         Entity* monster = monsters[i];
//         printf("Monster %zu: Pos (%d, %d), HP: %d, Gold: %d\n",
//                i, monster->pos.y, monster->pos.x, monster->hits, monster->gold);
//     }
// }