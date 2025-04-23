
#include "unity.h"
#include "rogue.h"


void test_getDistance(void) {
    Position p1 = {0, 0};
    Position p2 = {3, 4};
    int distance = getDistance(p1, p2);
    TEST_ASSERT_EQUAL_INT(5, distance); // 3-4-5 triangle
}

void test_isInMap(void) {
    const int MAP_HEIGHT = 20;
    const int MAP_WIDTH = 40;
    TEST_ASSERT_TRUE(isInMap(10, 10));
    TEST_ASSERT_FALSE(isInMap(-1, 10));
    TEST_ASSERT_FALSE(isInMap(10, 41));
}

void test_getSign(void) {
    TEST_ASSERT_EQUAL_INT(1, getSign(5));
    TEST_ASSERT_EQUAL_INT(-1, getSign(-5));
    TEST_ASSERT_EQUAL_INT(1, getSign(0));
}

