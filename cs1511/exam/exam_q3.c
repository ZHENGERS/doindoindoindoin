#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 1000

int check_counterpart(int num_array[MAX_SIZE], int index, int num);

int main(void) {
    int num_array[MAX_SIZE] = {0};
    int num = 0;
    int i = 0;
    while (scanf("%d", &num) != EOF) {
        num_array[i] = num;
        i++;
    }
    i = 0;
    int temp = 0;
    int count_negative = 0;
    while (i < MAX_SIZE) {
        if (num_array[i] > 0) {
            temp = num_array[i];
            if (check_counterpart(num_array, i, temp) == 0) {
                count_negative++;
            }
        }
        i++;
    }
    printf("%d\n", count_negative);
    return 0;
}

int check_counterpart(int num_array[MAX_SIZE], int index, int num) {
    int i = index;
    while (i < MAX_SIZE) {
        if (num_array[i] == -num) {
            return 1;
        }
        i++;
    }
    return 0;
}




