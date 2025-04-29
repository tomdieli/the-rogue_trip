#include <rogue.h>

Treasure* treasures = NULL;

Room createRoom(int y, int x, int height, int width)
{
  Room newRoom;

  newRoom.pos.y = y;
  newRoom.pos.x = x;
  newRoom.height = height;
  newRoom.width = width;
  newRoom.center.y = y + (int)(height / 2);
  newRoom.center.x = x + (int)(width / 2);

  return newRoom;
}

void connectRoomCenters(Position centerOne, Position centerTwo)
{ 
  Position temp;
  temp.x = centerOne.x;
  temp.y = centerOne.y;

  while (true)
  { 
    if (abs((temp.x - 1) - centerTwo.x) < abs(temp.x - centerTwo.x))
      temp.x--;
    else if (abs((temp.x + 1) - centerTwo.x) < abs(temp.x - centerTwo.x))
      temp.x++;
    else if (abs((temp.y + 1) - centerTwo.y) < abs(temp.y - centerTwo.y))
      temp.y++;
    else if (abs((temp.y - 1) - centerTwo.y) < abs(temp.y - centerTwo.y))
      temp.y--;
    else
      break;

    map[temp.y][temp.x].ch = '.';
    map[temp.y][temp.x].walkable = true;
    map[temp.y][temp.x].transparent = true;
  }
}

void addRoomToMap(Room room)
{
  for (int y = room.pos.y; y < room.pos.y + room.height; y++)
  {
    for (int x = room.pos.x; x < room.pos.x + room.width; x++)
    {
      map[y][x].ch = '.';
      map[y][x].walkable = true;
      map[y][x].transparent = true;
    }
  }
}

void placeTreasures(int num_treasures) {
  for (int i = 0; i < num_treasures; i++) {
      // Generate random positions within the map boundaries
      int y = rand() % MAP_HEIGHT;
      int x = rand() % MAP_WIDTH;

      // Ensure the position is walkable and not already occupied
      while (!map[y][x].walkable || map[y][x].ch != '.') {
          y = rand() % MAP_HEIGHT;
          x = rand() % MAP_WIDTH;
      }

      // Place the treasure
      map[y][x].ch = '$'; // Use '$' to represent treasure
      map[y][x].color = COLOR_PAIR(VISIBLE_COLOR);
      map[y][x].walkable = true; // Treasures should not block movement

      // Add the treasure to the treasures array
      Treasure* new_treasures = realloc(treasures, (i + 1) * sizeof(Treasure));
      if (new_treasures == NULL) {
          fprintf(stderr, "Memory allocation failed for treasures\n");
          exit(1);
      }
      treasures = new_treasures;
      treasures[i].pos.y = y;
      treasures[i].pos.x = x;
      treasures[i].gp = rand() % 100 + 1; // Random gold value between 1 and 100
  }
}