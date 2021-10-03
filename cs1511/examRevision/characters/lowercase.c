// Print out characters in lower case.
// Created by
// William Zheng (z5313015)

#include <stdio.h>

int lowercase(int c);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {

    // Scan in the first character.
    int c = getchar();

    // Loop until there are no more characters to scan.
    while (c != EOF) {
        // Print the character, in lowercase.
        putchar(lowercase(c));

        // Get the next character.
        c = getchar();
    }

    return 0;
}

// Returns the specified character `c`, in lowercase.
int lowercase(int c) {
    int new_c = 0;
    if (c >= 'A' && c <= 'Z') {
        new_c = c + 32;
    }
    else {
        new_c = c;
    }
    return new_c;
}
