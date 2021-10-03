// Assignment 2 20T2 COMP1511: Castle Defense
//
// This program was written by William Zheng (z5313015)
// on 08-08-2020
//
// Version 1.0.0 (2020-07-20): Assignment released.
// Version 1.0.1 (2020-07-21): Add return value to main.
// Version 1.1.0 (2020-07-23): Add test_apply_buff to main.

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "realm.h"
#include "test_realm.h"
#include "capture.h"

////////////////////////////////////////////////////////////////////
//                        Function Protoypes                      //
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
//                         Helper Functions                       //
////////////////////////////////////////////////////////////////////

// Find the string 'needle' in 'haystack'
int string_contains(char *haystack, char *needle) {
    return strstr(haystack, needle) != NULL;
}

// NOTE: You should not declare any structs from realm.c here.
// Declaring structs from realm.c in this function is against the
// rules of the assignment. 

// Main function: this function will not be used in testing, you do not
// need to change it.
// If you want to write your own tests, add them in `extra_tests`.
int main(int argc, char *argv[]) {
    printf("\n================== Castle Defense Tests ==================\n");

    test_add_location();
    test_print_realm();
    test_new_enemy();
    test_new_tower();
    test_apply_damage();
    test_apply_buff();
    extra_tests();

    return 0;
}

// NOTE: These tests are explained in `test_realm.h`

void test_add_location(void) {
    printf("Test whether this add_location follows the spec: ");

    // Test 1: Does add_location's return value count the Castle & Lair?

    Realm test_realm = new_realm();

    int num_locations = add_location(test_realm, "Location3");
    if (num_locations != 3) {
        printf(DOES_NOT_FOLLOW_SPEC);
        // since we don't want to print FOLLOWS_SPEC at the end,
        // we just return to the main function here.
        return;
    }

    // Test 2: Does add_location return the correct amount for lots of locations?
    num_locations = add_location(test_realm, "Location4");
    num_locations = add_location(test_realm, "Location5");
    num_locations = add_location(test_realm, "Location6");
    num_locations = add_location(test_realm, "Location7");
    num_locations = add_location(test_realm, "Location8");
    num_locations = add_location(test_realm, "Location9");
    if (num_locations != 9) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    
    // Test 3: Add your own test, and explain it below:
    // Testing weather add_location returns the correct amount when 
    // different amounts of locations are added.
    num_locations = add_location(test_realm, "Location10");
    if (num_locations != 10) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    } 
    num_locations = add_location(test_realm, "Location11");
    num_locations = add_location(test_realm, "Location12");
    if (num_locations != 12) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    } 
    num_locations = add_location(test_realm, "Location13");
    num_locations = add_location(test_realm, "Location14");
    num_locations = add_location(test_realm, "Location15");
    if (num_locations != 15) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    } 
    num_locations = add_location(test_realm, "Location16");
    num_locations = add_location(test_realm, "Location17");
    num_locations = add_location(test_realm, "Location18");
    num_locations = add_location(test_realm, "Location19");
    if (num_locations != 19) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    } 
    num_locations = add_location(test_realm, "Location20");
    num_locations = add_location(test_realm, "Location21");
    num_locations = add_location(test_realm, "Location22");
    num_locations = add_location(test_realm, "Location23");
    num_locations = add_location(test_realm, "Location24");
    if (num_locations != 24) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    printf(FOLLOWS_SPEC);
    
}

void test_print_realm(void) {
    printf("Test whether this print_realm follows the spec: ");

    // Test 1: Does print_realm show the Castle?

    Realm test_realm = new_realm();

    char print_text[10000];
    CAPTURE(print_realm(test_realm), print_text, 10000);

    if (!string_contains(print_text, "Castle")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        // since we don't want to print FOLLOWS_SPEC at the end,
        // we just return to the main function here.
        return;
    }

    // Test 2: Does print_realm show the correct HP of the castle?
    char castle_starting_hp[MAX_NAME_LENGTH] = "100";
    if (!string_contains(print_text, castle_starting_hp)) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    // Test 3: Add your own test, and explain it below: 
    // Testing if print_realm shows the lair and added land locations.
    if (!string_contains(print_text, "Lair")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    // Adding new land to test_realm.
    add_location(test_realm, "Location");
    CAPTURE(print_realm(test_realm), print_text, 10000);
    if (!string_contains(print_text, "Location")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    printf(FOLLOWS_SPEC);
}

// Stage 2

void test_new_enemy(void) {
    printf("Test whether this new_enemy follows the spec: ");

    // Test 1: Does new_enemy work if you're adding to the Lair?
    Realm test_realm = new_realm();
    int add_new_enemy = new_enemy(test_realm, "Lair", "enemy1", 4);
    if (add_new_enemy != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    
    // Test 2: Add your own test, and explain it below:
    // Testing whether new_enemy works when adding multiple 
    // enemies to an added location.
    add_location(test_realm, "Location");
    add_new_enemy = new_enemy(test_realm, "Location", "enemy2", 4);
    if (add_new_enemy != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    add_new_enemy = new_enemy(test_realm, "Location", "enemy3", 4);
    if (add_new_enemy != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }    
    add_new_enemy = new_enemy(test_realm, "Location", "enemy4", 4);
    if (add_new_enemy != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    add_new_enemy = new_enemy(test_realm, "Location", "enemy5", 4);
    if (add_new_enemy != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    printf(FOLLOWS_SPEC);
}

void test_new_tower(void) {
    printf("Test whether this new_tower follows the spec: ");

    // Test 1: Does new_tower work if you're adding after another tower?
    Realm test_realm = new_realm();
    int add_new_tower = new_tower(test_realm, "Castle", "Tower1", 2, 2);
    if (add_new_tower != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    else {
        add_new_tower = new_tower(test_realm, "Tower1", "Tower2", 2, 2);
        if (add_new_tower != SUCCESS) {
            printf(DOES_NOT_FOLLOW_SPEC);
            return;
        }
    }
    // Test 2: Add your own test, and explain it below:
    // Does new_tower work when adding a tower after an added land location, or
    // when adding multiple/different amounts of towers?
    add_location(test_realm, "Location");
    add_new_tower = new_tower(test_realm, "Location", "Tower3", 2, 2);
    if (add_new_tower != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    add_new_tower = new_tower(test_realm, "Location", "Tower4", 2, 2);
    add_new_tower = new_tower(test_realm, "Location", "Tower5", 2, 2);
    if (add_new_tower != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    add_new_tower = new_tower(test_realm, "Location", "Tower6", 2, 2);
    add_new_tower = new_tower(test_realm, "Location", "Tower7", 2, 2);
    add_new_tower = new_tower(test_realm, "Location", "Tower8", 2, 2);
    if (add_new_tower != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    printf(FOLLOWS_SPEC);
}

// Stage 3 (2 marks)

void test_apply_damage(void) {
    printf("Test whether this apply_damage follows the spec: ");
    
    // Test 1: Does apply_damage actually destroy enemies?
    Realm test_realm = new_realm();
    new_tower(test_realm, "Castle", "Tower1", 4, 100);
    new_enemy(test_realm, "Tower1", "enemy1", 4);
    int damage_enemies = apply_damage(test_realm);
    if (damage_enemies != 1) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    char print_text[10000];
    CAPTURE(print_realm(test_realm), print_text, 10000);
    if (string_contains(print_text, "enemy1")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    } 
    // Test 2: Add your own test, and explain it below:
    // Does apply_damage destroy enemies at various positions in the enemy 
    // list, and reconnect the list if one is destroyed? 
    // Already checked start of list (above test).
    // Testing removing enemy from the middle of list.
    new_enemy(test_realm, "Tower1", "enemy2", 20);
    new_enemy(test_realm, "Tower1", "enemy3", 4);
    new_enemy(test_realm, "Tower1", "enemy4", 8);
    damage_enemies = apply_damage(test_realm);
    // Does apply_damage return the correct number of enemeis hit?
    if (damage_enemies != 3) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    CAPTURE(print_realm(test_realm), print_text, 10000);
    // Has the correct enemy been destroyed?
    if (string_contains(print_text, "enemy3")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    // Have the other enemies been printed?
    if (!string_contains(print_text, "enemy2")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    if (!string_contains(print_text, "enemy4")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    // Testing removing enemy from the end of list.
    damage_enemies = apply_damage(test_realm);
    if (damage_enemies != 2) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    CAPTURE(print_realm(test_realm), print_text, 10000);
    if (string_contains(print_text, "enemy4")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    if (!string_contains(print_text, "enemy2")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    printf(FOLLOWS_SPEC);
}

// Stage 4 (1 marks)

void test_apply_buff(void) {
    printf("Test whether this apply_buff follows the spec: ");
    // Test 1: Add your own test, and explain it below:
    // ........

    // TODO: Change Here

    // Test 2: Add your own test, and explain it below:
    // ........

    // TODO: Change Here

    printf(FOLLOWS_SPEC);
}

// Extra Tests (not worth marks, but fun!)

void extra_tests(void) {
    // TODO: add extra tests, if you'd like to.
}
