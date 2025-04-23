#include <stdio.h>
#include "rogue.h"

const int MAP_HEIGHT = 20;
const int MAP_WIDTH = 40;

Tile** map = NULL;
Entity* player = NULL;
Entity* monsters = NULL;
int num_monsters = 0;
WINDOW* player_info = NULL;
WINDOW* game_status = NULL;