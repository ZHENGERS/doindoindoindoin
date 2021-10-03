// William Zheng (z5313015)

#include <stdio.h>

int swapUpperLower(int ch);

int main(void) {
    int ch = getchar();
    while (ch != EOF) {
        int newCharacter = swapUpperLower(ch);
        putchar(newCharacter);
        ch = getchar();
    }
}

int swapUpperLower(int ch) {
    int position;
    if (ch>='a' && ch<='z') {
        position = ch - 32;
        return position;
    }
    else if (ch>='A' && ch<='Z') {
        position = ch + 32;
        return position;
    }
    else {
        return ch;
    }
}

