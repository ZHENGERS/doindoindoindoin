// William Zheng (z5313015)
// A program to track statistics of pets

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_TYPE_LENGTH 50

struct pet {
    char name[MAX_NAME_LENGTH];
    char type[MAX_TYPE_LENGTH];
    int age;
    int weight;
};

// function declarations, do not change these
void setup_pet(
    struct pet *my_pet,
    char *name, 
    char *type, 
    char *age, 
    char *weight
);
void print_pet(struct pet *my_pet);

// do not change any code in the main function
int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("%s should receive four extra command line arguments.\n", argv[0]);
        return 1;
    }
    struct pet new_pet;
    setup_pet(&new_pet, argv[1], argv[2], argv[3], argv[4]);
    print_pet(&new_pet);
    return 0;
}

// A function that takes in four strings
// (given from the command line arguments in the main function)
// and stores their data in the pet struct.
//
// Note: you will need to convert the 'age' and 'weight' strings 
// to an integer before storing them in the struct.
void setup_pet(
    struct pet *my_pet, 
    char *name, 
    char *type, 
    char *age, 
    char *weight
) {
    int newAge = atoi(age);
    my_pet->age = newAge;
    int newWeight = atoi(weight);
    my_pet->weight = newWeight;
    strcpy(my_pet->name, name);
    strcpy(my_pet->type, type);
}

// A function that prints out a human readable
// description of the pet:
// "<name> is a <type> that is <age> years old and weighs <weight>kg\n"
void print_pet(struct pet *my_pet) {
    printf("%s is a %s who is %d years old and weighs %dkg\n", my_pet->name, 
            my_pet->type, my_pet->age, my_pet->weight);
}






