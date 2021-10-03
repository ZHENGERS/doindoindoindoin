// William Zheng (z5313015)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {
    int ch = getchar();
    while (ch != EOF) {
        printf("%d\n", ch);
        ch = getchar();
    }
    return 0;
}
