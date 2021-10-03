// William Zheng (z5313015)

#include <stdio.h>
#include <string.h>

#define SIZE 256

int main(void) {
    char lineChar[SIZE] = {0};
    fgets(lineChar, SIZE, stdin);
    int position = 0;
    scanf("%d", &position);
    int len = strlen(lineChar);
    int i = 0;
    while (i < len) {
        if (i == position) {
            printf("The character in position %d is '%c'\n", position, lineChar[i]);
        }
        i++;
    }
    return 0;
}
