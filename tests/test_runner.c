// filepath: /home/tom/projects/the_rogue_trip/tests/test_runner.c
#include "unity.h"
#include "rogue.h"

// Declare test functions from other test files
void test_createRoom(void);
void test_addRoomToMap(void);
void test_connectRoomCenters(void);
void test_getDistance(void);
void test_isInMap(void);
void test_getSign(void);

void setUp(void) {
    // Example: Initialize a mock map
    map = malloc(MAP_HEIGHT * sizeof(Tile*));
    for (int i = 0; i < MAP_HEIGHT; i++) {
        map[i] = malloc(MAP_WIDTH * sizeof(Tile));
    }
}

void tearDown(void) {
    // Example: Free the mock map
    for (int i = 0; i < MAP_HEIGHT; i++) {
        free(map[i]);
    }
    free(map);
}

int main(void) {
    UNITY_BEGIN();

    // Add tests from test_room.c
    RUN_TEST(test_createRoom);
    RUN_TEST(test_addRoomToMap);
    RUN_TEST(test_connectRoomCenters);

    // Add tests from test_utils.c
    RUN_TEST(test_getDistance);
    RUN_TEST(test_isInMap);
    RUN_TEST(test_getSign);


    return UNITY_END();
}