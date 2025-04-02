#include <rogue.h>

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
    mvaddch(monster.pos.y, monster.pos.x, monster.ch | monster.color);
  }
}

void draw_info_box(WINDOW* player_info)
{
  box(player_info, 0, 0);
  wmove(player_info, 1, 1);
  wprintw(player_info, "This is a subwindow");
}

void drawEverything(void)
{
  clear();
  drawMap();
  drawEntity(player);
  draw_others(monsters);
  draw_info_box(player_info);
}
