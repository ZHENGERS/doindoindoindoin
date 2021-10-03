// William Zheng (z5313015)

#include <stdio.h>

// swap the values in two integers, given as pointers
void swap_pointers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int first = 1;
    int second = 2;
    
    swap_pointers(&first, &second);
    
    printf("%d, %d\n", first, second);
    return 0;
}

