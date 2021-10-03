// Rotate a character by one -- i.e. turn 'a' to 'b', 'b' to 'c', ...
// 'z' to 'a'.
// William Zheng (z5313015)

#include <stdio.h>
#include <stdlib.h>

int rotateOne(int c);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {

    // Scan in the first character.
    int c = getchar();

    // Loop until there are no more characters to scan.
    while (c != EOF) {
        // Print the character, "rotated" once.
        putchar(rotateOne(c));

        // Get the next character.
        c = getchar();
    }

    return 0;
}
// END OF MAIN FUNCTION

// "Rotate" the letter by one, i.e. change 'a' to 'b', 'b' to 'c',
// 'z' to 'a'.
int rotateOne(int c) {
    int new_c = 0;
    if (c >= 'a' && c <= 'z') {
        new_c = 'a' + ((c - 'a') + 1) % 26;
    }
    else if (c >= 'A' && c <= 'z') {
        new_c = 'A' + ((c - 'A') + 1) % 26;
    }
    else {
        new_c = c;
    }
    return new_c;
}
