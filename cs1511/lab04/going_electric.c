// William Zheng (z5313015)

#include <stdio.h>

#define MAX_SIZE 10000 

void check_charge(int chargeArray[MAX_SIZE], int i, int positiveNum);

int main(void) {
    
    int chargeArray[MAX_SIZE] = {0};
    int positiveArray[MAX_SIZE] = {0};
    int i = 0;
    int positiveNum = 0;
    int j = 0;
    
    while (i < MAX_SIZE) {
        scanf("%d", &chargeArray[i]);
        if (chargeArray[i] > 0) {
            positiveNum++;
            chargeArray[i] = positiveArray[j];
            j++;
        }
        i++;   
    }

    check_charge(chargeArray[MAX_SIZE], i, positiveNum);    
    
//    printf("%d\n", chargeArray[1]);
    
    return 0;
}

void check_charge(int chargeArray[MAX_SIZE], int i, int positiveNum) {
    if (positiveNum > 1)    
}
