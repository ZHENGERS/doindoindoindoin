// William Zheng (z5313015)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {
    int i = 32;
    char ch_i = i;
    while (i <= 126) {
        ch_i = i;
        printf("%d 0x%x %c\n", i, ch_i, ch_i);
        i++;
    }
    return 0;
}
