#include "unity.h"
#include "rogue.h"

static void setupMapTest(void) {
    // Map-specific setup if needed
}

static void tearDownMapTest(void) {
    // Map-specific cleanup if needed
}

void test_createMapTiles(void) {
    setupMapTest();
    TEST_ASSERT_NOT_NULL(map);
    TEST_ASSERT_NOT_NULL(map[0]);
    tearDownMapTest();
}

void test_map_boundaries(void) {
    Position pos = {MAP_HEIGHT-1, MAP_WIDTH-1};
    TEST_ASSERT_TRUE(isInMap(pos.y, pos.x));
    
    pos.x = MAP_WIDTH;
    TEST_ASSERT_FALSE(isInMap(pos.y, pos.x));
    
    pos.x = -1;
    TEST_ASSERT_FALSE(isInMap(pos.y, pos.x));
}

void test_map_walkable_tiles(void) {
    Position pos = {5, 5};
    map[pos.y][pos.x].walkable = true;
    TEST_ASSERT_TRUE(map[pos.y][pos.x].walkable);
}