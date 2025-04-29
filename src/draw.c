#include <rogue.h>

char status_message[100] = "Welcome to the Rogue-like game!";

void drawMap(void)
{ 
  for (int y = 0; y < MAP_HEIGHT; y++)
  { 
    for (int x = 0; x < MAP_WIDTH; x++)
    { 
      if (map[y][x].visible)
      {
        mvaddch(y, x, map[y][x].ch | map[y][x].color);
      }
      else if (map[y][x].seen)
      {
        mvaddch(y, x, map[y][x].ch | COLOR_PAIR(SEEN_COLOR));
      }
      else
      {
        mvaddch(y, x, ' ');
      }
    } 
  } 
} 

void drawEntity(Entity* entity)
{ 
  mvaddch(entity->pos.y, entity->pos.x, entity->ch | entity->color);
}

void draw_others(Entity* others)
{
  for (size_t i = 0; i < num_monsters; i++)
  {
    Entity monster = others[i];
    // Only draw the monster if its tile is visible
    if (map[monster.pos.y][monster.pos.x].visible)
    {
      mvaddch(monster.pos.y, monster.pos.x, monster.ch | monster.color);
    }
  }
}

void draw_info_box(WINDOW* player_info)
{
  box(player_info, 0, 0);
  // Display player stats inside the subwindow
  wmove(player_info, 1, 1);
  wprintw(player_info, "Player Info:");

  wmove(player_info, 2, 1);
  wprintw(player_info, "STR: %d", player->st);

  wmove(player_info, 3, 1);
  wprintw(player_info, "DEX: %d", player->dx);

  wmove(player_info, 4, 1);
  wprintw(player_info, "Gold: %d", player->gold);
}

void draw_status_box(WINDOW* status_box, const char* message)
{
    box(status_box, 0, 0);
    // Display the status message inside the subwindow
    wmove(status_box, 1, 1);
    wprintw(status_box, "Status:");

    wmove(status_box, 2, 1);
    wprintw(status_box, "%s", message);

    // Refresh the subwindow to display the changes
    wrefresh(status_box);
}

void drawEverything(void)
{
  clear();
  drawMap();
  drawEntity(player);
  draw_others(monsters);
  draw_info_box(player_info);
  draw_status_box(status_box, status_message);
}
