#include "rogue.h"

// Define global variables needed for tests
const int MAP_HEIGHT = 43;
const int MAP_WIDTH = 132;

Entity* player = NULL;
Tile** map = NULL;
Entity* monsters = NULL;
int num_monsters = 0;
WINDOW* player_info = NULL;
WINDOW* status_box = NULL;
extern char status_message[100];