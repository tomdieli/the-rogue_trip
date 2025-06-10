#include "unity.h"
#include "rogue.h"

// Declare all test functions
void test_createRoom(void);
void test_addRoomToMap(void);
void test_connectRoomCenters(void);
void test_attack_success(void);
void test_attack_failure(void);
void test_combat_damage(void);
void test_createMapTiles(void);
void test_map_boundaries(void);
void test_map_walkable_tiles(void);

void setUp(void) {
    map = createMapTiles();
    player = createPlayer((Position){5, 5});
    monsters = malloc(sizeof(Entity));
}

void tearDown(void) {
    freeMap();
    free(player);
    free(monsters);
}

int main(void) {
    UNITY_BEGIN();
    
    // Room tests
    RUN_TEST(test_createRoom);
    RUN_TEST(test_addRoomToMap);
    RUN_TEST(test_connectRoomCenters);
    
    // Combat tests
    RUN_TEST(test_attack_success);
    RUN_TEST(test_attack_failure);
    RUN_TEST(test_combat_damage);
    
    // Map tests
    RUN_TEST(test_createMapTiles);
    RUN_TEST(test_map_boundaries);
    RUN_TEST(test_map_walkable_tiles);
    
    return UNITY_END();
}