# The Rogue Trip
A roguelike game written in C using the ncurses library.

## Overview
The Rogue Trip is a traditional roguelike game featuring procedurally generated dungeons, turn-based combat, and ASCII graphics. Players explore randomly generated rooms, battle monsters, and collect treasures.

## Features
- Turn-based gameplay
- Procedurally generated dungeons
- Field of View (FOV) and exploration mechanics
- Combat system
- Treasure collection
- Status and player information display

## Prerequisites
- GCC compiler
- ncurses library
- Make build system

### Installation on Ubuntu/Debian
```bash
sudo apt update
sudo apt install gcc make libncurses5-dev
```

## Building
Clone the repository and build the game:
```bash
git clone https://github.com/yourusername/the_rogue_trip.git
cd the_rogue_trip
make
```

## Running the Game
```bash
./rogue
```

## Controls
- `w` - Move up
- `s` - Move down
- `a` - Move left
- `d` - Move right
- `q` - Quit game

## Game Elements
- `@` - Player
- `M` - Monster
- `$` - Treasure
- `.` - Floor
- `#` - Wall
- ` ` - Unexplored area

## Project Structure
```
the_rogue_trip/
├── include/
│   └── rogue.h
├── src/
│   ├── combat.c
│   ├── draw.c
│   ├── engine.c
│   ├── fov.c
│   ├── main.c
│   ├── map.c
│   ├── monster.c
│   ├── player.c
│   └── room.c
├── tests/
│   └── test_room.c
├── makefile
└── README.md
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)