// Find the index of a character in a given string.
// Created by
// William Zheng (z5313015)
// Created on 2019-??-??

#include <stdio.h>

#define BUFFER_LENGTH 1024
#define NOT_IN_STRING -1

void read_line(int buffer_len, char *buffer);
int char_index(int c, char *string);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // Declare a buffer
    char buffer[BUFFER_LENGTH] = {0};

    // Read in a line...
    printf("Enter a line: ");
    read_line(BUFFER_LENGTH, buffer);

    // Get a character
    printf("Enter a character: ");
    int ch;
    ch = getchar();

    // Find and print character index or "not in string"
    int index = char_index(ch, buffer);
    if (index == NOT_IN_STRING) {
        printf("Character '%c' is not in the string.\n", ch);
    } else {
        printf("Index of character '%c': %d\n", ch, index);
    }

    return 0;
}


// Read a line of input into `buffer`, excluding the newline;
// ensures that `buffer` is a null-terminated string.
void read_line(int buffer_len, char *buffer) {
    int i = 0;
    int ch = getchar();
    while (i < buffer_len - 1 && ch != EOF && ch != '\n') {
        buffer[i] = ch;
        i = i + 1;
        ch = getchar();
    }
    buffer[i] = '\0';
}

// Return the index of the first occurrence of
// character `c` in the string, or `NOT_IN_STRING`
int char_index(int c, char *string) {
    int i = 0;
    int index = 0;
    while (string[i] != '\0') {
        if (string[i] == c) {
            index = i;
            break;
        }
        i++;
    }
    if (index == 0 && string[0] != c) {
        index = NOT_IN_STRING;
    }
    return index;
}








