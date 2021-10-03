#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_INPUT 10
#define MAX_CHARACTERS 256

void find_common(char input_array[MAX_INPUT][MAX_CHARACTERS], char
comp_array[MAX_CHARACTERS], int common_array[MAX_INPUT]);

void print_common(int index, char input_array[MAX_INPUT][MAX_CHARACTERS]);

int main(int argc, char *argv[]) {
    // you can always assume you will have exactly one command line argument.
    assert(argc == 2);
    char comp_array[MAX_CHARACTERS] = {0};
    char input_array[MAX_INPUT][MAX_CHARACTERS] = {0};
    strcpy(comp_array, argv[1]);
    int i = 0;
    while (scanf("%s\n", input_array[i]) != EOF && i < MAX_INPUT) {    
        i++;
    }
    int common_array[MAX_INPUT] = {0};
    find_common(input_array,comp_array,common_array);
    // Finding row with most common characters
    int most_common = common_array[0];
    int index = 0;
    i = 1;
    while (i < MAX_INPUT) {
        if (common_array[i] > most_common) {
            most_common = common_array[i];
            index = i; 
        }
        i++;
    }
    ////////////////////////////////////////
    int len = strlen(argv[1]);
    int uncommon = len - most_common;
    printf("%d ", uncommon);            
    print_common(index, input_array);
    printf("\n");
    return 0;
}

void find_common(char input_array[MAX_INPUT][MAX_CHARACTERS], char
comp_array[MAX_CHARACTERS], int common_array[MAX_INPUT]) {
    int i = 0;
    int j = 0;
    int common_count = 0;
    while (i < MAX_INPUT) {
        j = 0;
        common_count = 0;
        while (j < MAX_CHARACTERS && input_array[i][j] != 0) {
            if (input_array[i][j] == comp_array[j] + 32 
               || input_array[i][j] == comp_array[j] - 32 ) {
                common_count++;
            } else if (input_array[i][j] == comp_array[j]) {
                common_count++;
            } 
            j++;
        }
        common_array[i] = common_count;
        i++;
    }
}

void print_common(int index, char input_array[MAX_INPUT][MAX_CHARACTERS]) {
    int i = 0;
    int j = 0;
    while (i < MAX_INPUT) {
        if (i == index) {
            j = 0;
            while (j < MAX_CHARACTERS) {
                if (input_array[i][j] != '\0') {
                    printf("%c", input_array[i][j]); 
                }              
                j++;
            }
        }
        i++;    
    }  
}











