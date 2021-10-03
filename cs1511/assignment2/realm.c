// Assignment 2 20T2 COMP1511: Castle Defense
//
// This program was written by William Zheng (z5313015)
// on 08-08-2020
//
// Version 1.0.0 (2020-07-20): Assignment released.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "realm.h"
///////////////////////////////////////////////////////////////////////

// `struct realm` represents a realm, which represents the state of the
// entire program. It is mainly used to point to a linked list of 
// locations, though you may want to add other fields to it.
//
// You may need to add fields to struct realm.
struct realm {
    struct location *castle;
    struct location *lair;
};

// `struct location` represents a location, which could be a land,
// a tower, or a castle. Each of those places has a different type
// of information that this struct will need to store.
//
// You will need to add fields to struct location.
struct location {
    char name[MAX_NAME_LENGTH];
    int defense;
    int power;
    int uses;
    struct enemy *enemies;
    struct location *next;

};

// `struct enemy` represents an enemy, which will move through the
// realm (to each location). Towers can deal damage to it, and
// it can deal damage to the Castle.
//
// You will need to add fields to struct enemy.
struct enemy {
    int max_hp;
    int enemy_hp;
    char name[MAX_NAME_LENGTH];
    struct enemy *next;
};

// Add any other structs you define here.

///////////////////////////////////////////////////////////////////////

// Function prototypes for helper functions
static Location new_location(char *name);
static void print_tower(char *name, int power, int uses, Effect effect);
static void print_land(char *name);
static void print_castle(char *name, int defense);
static void print_enemy(char *name, int cur_hp, int max_hp);

// Add prototypes for any extra functions you create here.

void add_enemy(struct enemy *new_enemy, struct enemy *curr_enemies);
void remove_enemy(struct location *curr_location, struct enemy *enemy_removed);

// You need to implement the following 9 functions.
// In other words, write code to make the function work as described 
// in realm.h.

// Create a new realm, and return a pointer to it.
// You may need to change this function in later stages.
Realm new_realm(void) {
    struct realm *realm = malloc(sizeof(struct realm));
    realm->castle = new_location("Castle");
    realm->lair = new_location("Lair");

    if (realm->castle != NULL && realm->lair != NULL) {
        realm->castle->next = realm->lair;
    }

    return realm;
}


// Return a new location created with malloc.
static Location new_location(char *name) {
    struct location *new_location = malloc(sizeof(struct location));
    strcpy(new_location->name, name);
    new_location->power = 0;
    new_location->uses = 0;
    new_location->next = NULL;
    new_location->enemies = NULL;
    new_location->defense = STARTING_CASTLE_HP;
    return new_location;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add a new location to the realm, and return the total number of
// locations in the realm.
int add_location(Realm realm, char *name) {
    int location_counter = 0;
    struct location *add_location = new_location(name);
    struct location *curr_location = realm->castle;
    realm->lair->next = NULL;
    realm->castle->enemies = NULL;
    realm->lair->enemies = NULL;
    // Traversing through locations and if location->next is Lair, insert 
    // location in that position.
    while (curr_location != NULL) {
        if (curr_location->next == realm->lair) {
            curr_location->next = add_location;
            add_location->next = realm->lair;
        }
        location_counter++;
        curr_location = curr_location->next;
    }
    return location_counter;    
}

// Print out the realm.
void print_realm(Realm realm) {
    struct location *curr = realm->castle;
    struct enemy *curr_enemies = NULL;
    while (curr != NULL) {
        // Print out castle.
        if (curr == realm->castle) {
            print_castle(curr->name, curr->defense);
        }
        // Print either land or tower location.
        else {
            if (curr->power == 0 || curr->uses == 0) {
                print_land(curr->name);
            }
            else {
                print_tower(curr->name, curr->power, curr->uses, EFFECT_NONE);
            }
        }
        // Traverse through and print all enemies at curr.
        curr_enemies = curr->enemies;
        while (curr_enemies != NULL) {
            print_enemy(curr_enemies->name, curr_enemies->enemy_hp, 
                        curr_enemies->max_hp);
            curr_enemies = curr_enemies->next;
        }
        curr = curr->next;
    }
}
////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add an enemy to the realm.
int new_enemy(Realm realm, char *location_name, char *name, int hp) {
    struct location *curr = realm->castle;
    struct enemy *new_enemy = malloc(sizeof(struct enemy));
    new_enemy->next = NULL;
    strcpy(new_enemy->name, name);
    new_enemy->enemy_hp = hp;
    new_enemy->max_hp = hp;
    if (new_enemy->enemy_hp < 1) {
        return ERROR_INVALID_STAT;
    }
    // Tracking weather the location inputted was found in the realm.
    int location_exists = 0;
    // Traverse through all locations in the realm. If its name matches the
    // inputted name, insert enemy at that location using add_enemy function.
    while (curr != NULL) { 
        if (strcmp(location_name, curr->name) == 0) { 
            // Inserting at beginning of enemy list.
            if (curr->enemies == NULL) {
                curr->enemies = new_enemy;
                new_enemy->next = NULL;
            } 
            // Inserting after the beginning.
            else {
                struct enemy *curr_enemies = curr->enemies;
                add_enemy(new_enemy, curr_enemies);
            } 
            location_exists++;
        }
        curr = curr->next;
    }
    if (location_exists == 0) {
        return ERROR_NO_LOCATION;
    }
    return SUCCESS;
}

// Traverses through the enemy list at a specific location, then 
// inserts new_enemy at the end of this list.
void add_enemy(struct enemy *new_enemy, struct enemy *curr_enemies) {
    while (curr_enemies != NULL) {
        if (curr_enemies->next == NULL) { 
            curr_enemies->next = new_enemy;
            curr_enemies = new_enemy;
            new_enemy->next = NULL;
        }
        curr_enemies = curr_enemies->next;
    } 
}

// Add a new tower to the realm.
int new_tower(Realm realm, char *prev_name, char *name, int power, int uses) {
    struct location *new_tower = malloc(sizeof(struct location));
    strcpy(new_tower->name, name);
    new_tower->power = power;
    new_tower->uses = uses;
    new_tower->enemies = NULL;
    if (power < 1 || uses < 1) {
        return ERROR_INVALID_STAT;
    }
    // Tracking whether the location inputted was found in the realm.
    int location_exists = 0;
    struct location *curr = realm->castle;
    struct location *prev = NULL;
    // Traverse through locations in realm, keeping track of the location
    // before curr. Then inserting new_tower after inputed location name.
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
        if (strcmp(prev_name, prev->name) == 0) {
            prev->next = new_tower;
            new_tower->next = curr;
            location_exists++;
        }
    }
    if (location_exists == 0) {
        return ERROR_NO_LOCATION;
    }
    return SUCCESS;
}


////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

// Destroy the realm, and free any associated memory.
void destroy_realm(Realm realm) {
    struct location *curr = realm->castle;
    struct location *next = NULL;
    struct enemy *curr_enemy = NULL;
    struct enemy *next_enemy = NULL;
    // Traverse through and free all locations in realm.
    while (curr != NULL) {
        next = curr->next;
        curr_enemy = curr->enemies;
        // Traverse through and freeing all enemies within each location.
        while (curr_enemy != NULL) {
            next_enemy = curr_enemy->next;
            //printf("Freeing %s\n", curr_enemy->name);
            free(curr_enemy);
            curr_enemy = next_enemy;
        }
        //printf("Freeing %s\n", curr->name);
        free(curr);
        curr = next;
    }
    free(realm);
}

// Advance enemies towards the castle, returning the number of enemies 
// that advanced pasted the castle.
int advance_enemies(Realm realm) {
    int enemies_removed = 0;
    struct location *curr = realm->castle;
    struct location *prev = NULL;
    struct enemy *curr_enemy = NULL;
    struct enemy *next_enemy = NULL;
    // Traverse through each location in the realm, keeping track of each
    // previous location so that enemies are able to advance.
    while (curr != NULL) {
        curr_enemy = curr->enemies;
        // Traverse through all enemies at each location then advancing them
        // to the next location, removing them from the realm if 
        // they advance from castle.
        while (curr_enemy != NULL) {
            next_enemy = curr_enemy->next;
            if (curr == realm->castle) {
                free(curr_enemy);
                curr->enemies = NULL;
                enemies_removed++;
            }
            else {
                if (prev->enemies == NULL) {
                    prev->enemies = curr_enemy;
                }
                else { 
                    prev->enemies->next = curr_enemy;
                } 
                curr->enemies = NULL;      
            }
            curr_enemy = next_enemy;
        }
        prev = curr;
        curr = curr->next;
    }
    return enemies_removed;
}

// Apply damage from the enemies at each tower to that tower, returning
// the number of enemeis hit.
int apply_damage(Realm realm) {
    int enemies_hit = 0;
    struct location *curr = realm->castle;
    struct enemy *curr_enemy = NULL;
    struct enemy *temp = NULL;
    // Traverse through all locations in Realm.
    while (curr != NULL) {
        // Deal damage from enemies to Castle defenses if curr is pointing
        // at castle, and there are enemies there.
        if (curr == realm->castle) {
            curr_enemy = curr->enemies;
            while (curr_enemy != NULL) {
                curr->defense -= curr_enemy->enemy_hp;
                curr_enemy = curr_enemy->next;
            }
        }
        // If curr is a tower location, check if there are enemies at this
        // location and reduce hp of enemies by the power value of the tower.
        else if (curr->power > 0 && curr->uses > 0) {
            curr_enemy = curr->enemies;
            while (curr_enemy != NULL) {
                temp = curr_enemy->next;
                curr_enemy->enemy_hp = curr_enemy->enemy_hp-(curr->power);
                // Remove an enemy from the realm using the remove_enemy 
                // function if its hp is less than or equal to 0.
                if (curr_enemy->enemy_hp <= 0) {
                    remove_enemy(curr, curr_enemy);
                }
                curr_enemy = temp;
                enemies_hit++;
                curr->uses--;
            }
        }
        curr = curr->next;
    }
    return enemies_hit;
}

// Given a pointer to an enemy that should be removed, this function traverses
// through the enemy list at that location and removes the enemy from the realm.
void remove_enemy(struct location *curr_location, struct enemy *enemy_removed) {
    struct enemy *curr_enemy = curr_location->enemies;
    struct enemy *prev = NULL;
    struct enemy *temp = NULL;
    // Freeing/removing enemy from start of the list.
    if (strcmp(curr_enemy->name, enemy_removed->name) == 0) {
        temp = curr_enemy->next;
        free(curr_enemy);
        curr_location->enemies = temp;
        return;
    }
    else {
        prev = curr_enemy;
        curr_enemy = curr_enemy->next;
        while (curr_enemy != NULL) {
            if (strcmp(curr_enemy->name, enemy_removed->name) == 0) {
                prev->next = curr_enemy->next;
                free(curr_enemy);
                return;
            }
            prev = curr_enemy;
            curr_enemy = curr_enemy->next;
        }
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

// Apply the specified buff to the relevant towers or enemies.
// NOTE: Below function does not follow the spec. Instead of prefix
// matching, the function uses an exact match to locate a given tower or enemy
// and apply a buff (Did not have enough time to complete).
int apply_buff(Realm realm, char *search_term, Buff buff, int amount){
    int matches = 0;
    struct location *curr = realm->castle;
    struct enemy *curr_enemy = NULL;
    struct enemy *temp = NULL;
    // Traverse through all locations and buffs a matching tower.
    if (buff == BUFF_TOWER_POWER || buff == BUFF_TOWER_USES) {
        while (curr != NULL) {
            if (strcmp(search_term, curr->name) == 0) {
                if (buff == BUFF_TOWER_USES) {
                    curr->uses += amount;
                }
                else {
                    curr->power += amount;
                }
                matches++;    
            }
            curr = curr->next;
        }
    }
    // Traverse through all enemies at each location and buffs a matching enemy.
    // Removing enemies if the buff results in hp being less than or equal to 0.
    else if (buff == BUFF_ENEMY_HP) {
        while (curr != NULL) {
            curr_enemy = curr->enemies;
            while (curr_enemy != NULL) {
                temp = curr_enemy->next;
                if (strcmp(search_term, curr_enemy->name) == 0) {
                    curr_enemy->enemy_hp += amount;
                    curr_enemy->max_hp += amount;
                    if (curr_enemy->enemy_hp <= 0) {
                        remove_enemy(curr, curr_enemy);
                    }
                    matches++;
                }
                curr_enemy = temp;
            }
            curr = curr->next;
        }
    }
    return matches;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

// Apply the specified effect to each tower whose name matches the
// specified search term.
int apply_effect(Realm realm, char *search_term, Effect effect) {
    return 0;
}

////////////////////////////////////////////////////////////////////////

// Add definitions for your own functions below.
// Make them static to limit their scope to this file.




////////////////////////////////////////////////////////////////////////
//                    Provided print functions                        //
//         NOTE: YOU SHOULD NOT MODIFY THE FOLLOWING FUNCTIONS        //
////////////////////////////////////////////////////////////////////////

void print_tower(char *name, int power, int uses, int effect) {
    printf(" ^ %32s [pow: %3d | uses: %3d]", name, power, uses);
    if (effect == EFFECT_NONE) printf(" {%c}", EFFECT_NONE_CHAR);
    if (effect == EFFECT_PORTAL) printf(" {%c}", EFFECT_PORTAL_CHAR);
    if (effect == EFFECT_ICE) printf(" {%c}", EFFECT_ICE_CHAR);
    printf("\n");
}

void print_land(char *name) {
    printf(" ^ %32s [____________________]\n", name);
}

void print_castle(char *name, int defense) {
    printf(" ^ %32s [Castle Defenses: %3d]\n", name, defense);
}

void print_enemy(char *name, int cur_hp, int max_hp) {
    printf(" ^ %40s [hp: %d/%d]\n", name, cur_hp, max_hp);
}

////////////////////////////////////////////////////////////////////////
//               End of provided print functions                      //
////////////////////////////////////////////////////////////////////////

