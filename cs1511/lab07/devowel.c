// William Zheng (z5313015)

#include <stdio.h>

int checkVowel(int ch);

int main(void) {
    int ch = getchar();
    while (ch != EOF) {
        if (checkVowel(ch)==0) {
            printf("%c", ch);
        }
        ch = getchar();
    }
    return 0;
}

int checkVowel(int ch) {
    if (ch=='a' ||ch=='e' || ch== 'i' || ch=='o' || ch=='u') {
        return 1;
    }
    else {
        return 0;
    }
}
