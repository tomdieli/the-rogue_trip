#include <rogue.h>

Tile** createMapTiles(void)
{ 
  Tile** tiles = calloc(MAP_HEIGHT, sizeof(Tile*));

  for (int y = 0; y < MAP_HEIGHT; y++)
  { 
    tiles[y] = calloc(MAP_WIDTH, sizeof(Tile));
    for (int x = 0; x < MAP_WIDTH; x++)
    { 
      tiles[y][x].ch = '#';
      tiles[y][x].color = COLOR_PAIR(VISIBLE_COLOR);
      tiles[y][x].walkable = false;
      tiles[y][x].transparent = false;
      tiles[y][x].visible = false;
      tiles[y][x].seen = false;
    }
  } 

  return tiles;
}

Position setupMap(void)
{
  int y, x, height, width, n_rooms;
  n_rooms =  (rand() % 11) + 5;
  Room* rooms = calloc(n_rooms, sizeof(Room));
  Position start_pos;

  int rooms_counter = 0;

  while (rooms_counter < n_rooms)
  {
    y = (rand() % (MAP_HEIGHT - 10)) + 1;
    x = (rand() % (MAP_WIDTH - 20)) + 1;
    height = (rand() % 7) + 3;
    width = (rand() % 15) + 5;
    // rooms[i] = createRoom(y, x, height, width);
    if (!room_overlaps(rooms, rooms_counter, y, x, height, width))
    {
      rooms[rooms_counter] = createRoom(y, x, height, width);
      addRoomToMap(rooms[rooms_counter]);
      if (rooms_counter > 0)
      {
        connectRoomCenters(rooms[rooms_counter-1].center, rooms[rooms_counter].center);
      }
      ++rooms_counter;
      // let's say %25 for the monster
      int monster_roll = (rand() % 100) + 1;
      if( monster_roll <= 25 ) {
        // create the monster
        Position monster_pos;
        monster_pos.x = x + (width/2);
        monster_pos.y = y + (height/2);
        createMonster(monster_pos);
        //map[monster_pos.x][monster_pos.y].walkable = false;
      }
    }

    
    // if treasure
    
    // add treasure
  }

  start_pos.y = rooms[0].center.y;
  start_pos.x = rooms[0].center.x;

  free(rooms);

  return start_pos;
}

bool room_overlaps(Room* rooms, int rooms_counter, int y, int x, int height, int width)
{
  for (int i = 0; i < rooms_counter; i++)
  {
    if (x >= rooms[i].pos.x + rooms[i].width || rooms[i].pos.x >= x + width)
    {
      continue;
    }
    if (y + height <= rooms[i].pos.y || rooms[i].pos.y + rooms[i].height <= y)
    {
      continue;
    }

    return true;
  }

  return false;
}

void freeMap(void)
{ 
  for (int y = 0; y < MAP_HEIGHT; y++)
  { 
    free(map[y]);
  } 
  free(map);
} 