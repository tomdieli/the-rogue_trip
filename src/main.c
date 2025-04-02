#include <ncurses.h>
#include <rogue.h>

const int MAP_HEIGHT = 43;
const int MAP_WIDTH = 132;

Entity* player;
Tile** map;
Entity* monsters;
int num_monsters = 0;
WINDOW* player_info;

int main(void)
{
  Position start_pos;
  bool compatibleTerminal;

  compatibleTerminal = cursesSetup();

  if (compatibleTerminal)
  {
    srand(time(NULL));

    map = createMapTiles();
    start_pos = setupMap();
    player = createPlayer(start_pos);

    player_info = subwin(stdscr, 8, 38, 0, 0);

    gameLoop();

    closeGame();
  }
  else
  {
    endwin();
  }

  return 0;
}
