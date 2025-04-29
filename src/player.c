#include <rogue.h>

Entity* createPlayer(Position start_pos)
{
  Entity* newPlayer = calloc(1, sizeof(Entity));

  newPlayer->pos.y = start_pos.y;
  newPlayer->pos.x = start_pos.x;
  newPlayer->ch = '@';
  newPlayer->color = COLOR_PAIR(VISIBLE_COLOR);
  newPlayer->st = 12;
  newPlayer->dx = 12;
  newPlayer->hits = newPlayer->st;
  newPlayer->gold = 0;

  return newPlayer;
}

void handleInput(int input)
{
  Position newPos = { player->pos.y, player->pos.x };

  switch(input)
  {
    //move up
    case 'w':
      newPos.y--;
      break;
    //move down
    case 's':
      newPos.y++;
      break;
    //move left
    case 'a':
      newPos.x--;
      break;
    //move right
    case 'd':
      newPos.x++;
      break;
    default:
      break;
  }

  movePlayer(newPos);
}

void movePlayer(Position newPos)
{
  // Check if the player encounters a monster
  for (int i = 0; i < num_monsters; i++)
  {
      if (monsters[i].pos.y == newPos.y && monsters[i].pos.x == newPos.x)
      {
          combatPhase(player, &monsters[i]);
          return; // Exit the function after combat
      }
  }
  
  if (map[newPos.y][newPos.x].ch == '$') {
    // Collect the treasure
    for (int i = 0; i < 10; i++) {
        if (treasures[i].pos.y == newPos.y && treasures[i].pos.x == newPos.x) {
            player->gold += treasures[i].gp;    // Add gold to the player
            map[newPos.y][newPos.x].ch = '.';   // Remove the treasure from the map
            snprintf(status_message, 100, "You collected %d gold!", treasures[i].gp);
            break;
        }
    }
  }
  if (map[newPos.y][newPos.x].walkable)
  {
    clearFOV(player);
    player->pos = newPos;
    makeFOV(player);
  }
  
}

