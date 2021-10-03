#include <stdio.h>

// Return the number of increasing pairs in the array.
int count_increasing(int size, int array[size][2]) {
    int num_increasing = 0;
    int i = 0;
    int j = 0;
    int temp = 0;
    while (i < size) {
        j = 0;
        while (j < 2) {
            if (j == 0) {
                temp = array[i][j];
            } else if (temp < array[i][j]) {
                num_increasing++;            
            }
            j++;        
        }
        i++;
    }
    return num_increasing;
}

// This is a simple main function which could be used
// to test your count_increasing function.
// It will not be marked.
// Only your count_increasing function will be marked.

#define TEST_ARRAY_SIZE 5

int main(void) {
    int test_array[TEST_ARRAY_SIZE][2] = {{16, 7}, {8, 12}, {13, -9}, {-3, 12}, {1, 1}};

    int result = count_increasing(TEST_ARRAY_SIZE, test_array);
    printf("%d\n", result);

    return 0;
}
