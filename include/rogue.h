#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// color pairs
#define VISIBLE_COLOR 1
#define SEEN_COLOR 2

typedef struct
{
  int y;
  int x;
} Position;

typedef struct
{
  char ch;
  int color;
  bool walkable;
  bool transparent;
  bool visible;
  bool seen;
} Tile;

typedef struct
{
  int height; 
  int width;
  Position pos;
  Position center;
} Room;

typedef struct
{
  Position pos;
  int st;
  int dx;
  int hits;
  int gold;
  char ch;
  int color;
} Entity;

typedef struct 
{
  Position pos;
  int hp;
} Potion;

typedef struct
{
  Position pos;
  int gp;
} Treasure;


//draw.c functions
void drawMap(void);
void drawEntity(Entity* entity);
void drawEverything(void);

//engine.c functions
bool cursesSetup(void);
void gameLoop(void);
void closeGame(void);

//map.c functions
Tile** createMapTiles(void);
void freeMap(void);
Position setupMap(void);
bool room_overlaps(Room*, int, int, int, int, int);

// player.c functions
Entity* createPlayer(Position start_pos);
void handleInput(int input);
void movePlayer(Position newPos);

// monster.c functions
void createMonster(Position room_dims);
//void freeMonsters(void);

// room.c functions
Room createRoom(int y, int x, int height, int width);
void addRoomToMap(Room room);
void connectRoomCenters(Position centerOne, Position centerTwo);

// fov.c functions
void makeFOV(Entity* player);
void clearFOV(Entity* player);
int getDistance(Position origin, Position target);
bool isInMap(int y, int x);
bool lineOfSight(Position origin, Position target);
int getSign(int a);

// externs
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Entity* player;
extern Tile** map;
extern Potion* potions;
extern Treasure* treasures;
extern Entity* monsters;
extern int num_monsters;
extern WINDOW* player_info;
extern WINDOW* game_status;

#endif
