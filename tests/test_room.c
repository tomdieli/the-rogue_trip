#include "unity.h"
#include "rogue.h"

void test_createRoom(void) {
    Room room = createRoom(5, 10, 6, 8);

    TEST_ASSERT_EQUAL_INT(5, room.pos.y);
    TEST_ASSERT_EQUAL_INT(10, room.pos.x);
    TEST_ASSERT_EQUAL_INT(6, room.height);
    TEST_ASSERT_EQUAL_INT(8, room.width);
    TEST_ASSERT_EQUAL_INT(5 + 6 / 2, room.center.y);
    TEST_ASSERT_EQUAL_INT(10 + 8 / 2, room.center.x);
}

void test_addRoomToMap(void) {
    Room room = createRoom(2, 3, 4, 5);
    addRoomToMap(room);

    for (int y = room.pos.y; y < room.pos.y + room.height; y++) {
        for (int x = room.pos.x; x < room.pos.x + room.width; x++) {
            TEST_ASSERT_EQUAL_CHAR('.', map[y][x].ch);
            TEST_ASSERT_TRUE(map[y][x].walkable);
            TEST_ASSERT_TRUE(map[y][x].transparent);
        }
    }
}

void test_connectRoomCenters(void) {
    Position centerOne = {5, 5};
    Position centerTwo = {10, 10};

    connectRoomCenters(centerOne, centerTwo);

    Position temp = centerOne;
    while (temp.x != centerTwo.x || temp.y != centerTwo.y) {
        TEST_ASSERT_EQUAL_CHAR('.', map[temp.y][temp.x].ch);
        TEST_ASSERT_TRUE(map[temp.y][temp.x].walkable);
        TEST_ASSERT_TRUE(map[temp.y][temp.x].transparent);

        if (temp.x < centerTwo.x) temp.x++;
        else if (temp.x > centerTwo.x) temp.x--;
        else if (temp.y < centerTwo.y) temp.y++;
        else if (temp.y > centerTwo.y) temp.y--;
    }
}

