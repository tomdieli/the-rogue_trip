CC = gcc
CFLAGS = -lncurses -lm -I./include/ -I./libs/unity/
SOURCES = $(wildcard ./src/*.c)
TEST_SOURCES = $(filter-out ./src/main.c, $(SOURCES)) # Exclude main.c for tests
TEST_SRC = tests/test_runner.c tests/test_utils.c tests/test_room.c tests/test_mocks.c
UNITY_SRC = libs/unity/unity.c

all: rogue run clean

rogue: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o rogue

test: $(TEST_SRC) $(UNITY_SRC) $(TEST_SOURCES)
	$(CC) $(TEST_SRC) $(UNITY_SRC) $(TEST_SOURCES) $(CFLAGS) -o test_runner
	./test_runner

debug:
	$(CC) $(SOURCES) $(CFLAGS) -g -o rogue
	gdb rogue

run:
	./rogue

clean:
	rm -f rogue test_runner