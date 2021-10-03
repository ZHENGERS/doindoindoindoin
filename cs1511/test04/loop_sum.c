// William Zheng (z5313015)
// Reads an integer from std input, scans that amount of integers
// Then adds them togethor

#include<stdio.h>

#define MAX_SIZE 100

//scans however many numbers user decides to input
void scan_num(int numOfinputs, int arrayNums[MAX_SIZE]);
//adds these numbers togethor
int find_sum(int arrayNums[MAX_SIZE], int numOfinputs);

int main(void) {
    int arrayNums[MAX_SIZE] = {0};
    int numOfinputs;
    printf("How many numbers: ");
    scanf("%d", &numOfinputs);  
    scan_num(numOfinputs, arrayNums);
    int result = find_sum(arrayNums, numOfinputs);
    printf("The sum is: %d\n", result);
    return 0;
}

void scan_num(int numOfinputs, int arrayNums[MAX_SIZE]) {
    int i = 0;
    while (i < numOfinputs) {
        scanf("%d", &arrayNums[i]);
        i++;
    }
}

int find_sum(int arrayNums[MAX_SIZE], int numOfinputs) {
    int i = 0;
    int sum = 0;
    while (i<numOfinputs) {
        sum = sum + arrayNums[i];
        i++;
    }
    return sum;
}
