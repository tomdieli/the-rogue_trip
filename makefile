CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lncurses -lm
INCLUDES = -I./include/ -I./libs/unity/

SOURCES = $(wildcard ./src/*.c)
OBJECTS = $(SOURCES:.c=.o)

TEST_SOURCES = $(filter-out ./src/main.c, $(SOURCES))
TEST_FILES = tests/test_runner.c \
            tests/test_room.c \
            tests/test_combat.c \
            tests/test_map.c \
            tests/test_helpers.c
TEST_OBJECTS = $(TEST_SOURCES:.c=.o) $(TEST_FILES:.c=.o)
UNITY_SRC = libs/unity/unity.c

.PHONY: all clean test debug run

all: rogue

%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

rogue: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

test: $(TEST_OBJECTS) $(UNITY_SRC)
	$(CC) $(TEST_OBJECTS) $(UNITY_SRC) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o test_runner
	./test_runner

debug: CFLAGS += -g
debug: clean rogue
	gdb rogue

run: rogue
	./rogue

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) rogue test_runner