#include <ncurses.h>
#include <rogue.h>

const int MAP_HEIGHT = 43;
const int MAP_WIDTH = 132;

Entity* player;
Tile** map;
Entity* monsters;
int num_monsters = 0;
WINDOW* player_info;
WINDOW* status_box;

int main(void)
{
  Position start_pos;
  bool compatibleTerminal;

  initscr();
  compatibleTerminal = cursesSetup();

  if (compatibleTerminal)
  {
    srand(time(NULL));

    map = createMapTiles();
    start_pos = setupMap();
    player = createPlayer(start_pos);
    placeTreasures(10);
    

    // Create the player_info box as a subwindow
    player_info = subwin(stdscr, 8, 20, MAP_HEIGHT + 1, 0);

    // Create the status_box as a subwindow to the right of player_info
    status_box = subwin(stdscr, 8, MAP_WIDTH - 20, MAP_HEIGHT + 1, 21); 

    gameLoop();

    closeGame();
  }
  else {
    delwin(player_info);
    delwin(status_box);
    endwin();
    endwin();
  }

  return 0;
}
