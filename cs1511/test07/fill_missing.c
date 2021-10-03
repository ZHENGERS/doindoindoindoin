// William Zheng (z5313015)

#include<stdio.h>

#define SIZE 10000

int findLargest(int numArr[SIZE]);
void storeMissing(int numArr[SIZE], int largest, int numOfNums, int missingArr[SIZE]);
void printMissing(int missingArr[SIZE]);

int main(void) {
    int numArr[SIZE] = {0};
    int missingArr[SIZE] = {0};
    int i = 0;
    int numCounter = 0;
    while (scanf("%d\n",&numArr[i]) == 1) {
        numCounter++;
        i++;
    }
    int largestNum = findLargest(numArr);
    storeMissing(numArr, largestNum, numCounter, missingArr);
    printMissing(missingArr);
    printf("\n");
    return 0;
}

int findLargest(int numArr[SIZE]) {
    int i = 0;
    int largest = 0;
    while (i < SIZE) {
        if (i > 0 && numArr[i] > numArr[i-1]) { 
            largest = numArr[i];
        }
        i++;
    }
    if (numArr[0] >= largest) {
        largest = numArr[0];
    }
    return largest;
}

void storeMissing(int numArr[SIZE], int largest, int numOfNums, int missingArr[SIZE]) {
    int i = largest;
    int missCount = 0;
    while (i > 0) {
        int j = 0;
        while (j < numOfNums) {
            if (numArr[j] == i) {
                break;
            }
            else {
                if (j == numOfNums-1 && numArr[j] != i) {
                    missingArr[missCount] = i;
                    missCount++;
                }
            }
            j++;
        }
        i--;
    }
}

void printMissing(int missingArr[SIZE]) {
    int i = 0;
    int numElements = 0;
    while (i < SIZE) {
        if(missingArr[i] != 0) {
            numElements++;
        }
        i++;
    }
    i = 0;
    int temp = 0;
    while (i < numElements) {
        int j = i + 1;
        while (j < numElements) {
            if (missingArr[i] > missingArr[j]) {
                temp = missingArr[i];
                missingArr[i] = missingArr[j];
                missingArr[j] = temp;
            }
            j++;
        }
        i++;    
    }
    i = 0;
    while (i < numElements) {
        printf("%d ", missingArr[i]);
        i++;
    }
}
