#include "unity.h"
#include "rogue.h"

static void setupCombatTest(void) {
    // Combat-specific setup if needed
    monsters[0] = (Entity){
        .pos = {6, 6},
        .st = 10,
        .dx = 8,
        .hits = 20,
        .ch = 'M'
    };
    num_monsters = 1;
}

static void tearDownCombatTest(void) {
    // Combat-specific cleanup if needed
}


void test_attack_success(void) {
    setupCombatTest();
    TEST_ASSERT_TRUE(attack(15));
    tearDownCombatTest();
}

void test_attack_failure(void) {
    // Test attack with low dexterity
    TEST_ASSERT_FALSE(attack(1));
}

void test_combat_damage(void) {
    Entity test_monster = {
        .pos = {1, 1},
        .hits = 20,
        .st = 5
    };
    
    int initial_hp = test_monster.hits;
    combatPhase(player, &test_monster);
    TEST_ASSERT_NOT_EQUAL(initial_hp, test_monster.hits);
}