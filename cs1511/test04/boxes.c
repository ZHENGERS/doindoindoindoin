// William Zheng (z5313015)
// Reads in a number and then draws that many square boxes 
// inside each other using the integer 1.

#include <stdio.h> 

int main(void) {
    
    int numBoxes;
    printf("How many boxes: ");
    scanf("%d", &numBoxes);
    int arraySize = (4*numBoxes)-1;
    int boxArray[arraySize][arraySize];
    int a, b;
    for (a=0; a<arraySize; a++) {
        for (b=0; b<arraySize; b++) {
            boxArray[a][b] = 1;
        }
    }
    int i = 0;
    while (i<arraySize) {
        int j = 0;
        int centre = arraySize/2;
        while (j<arraySize) {
            if ((centre-i)%2==0 && (centre-j)%2==0){
                boxArray[i][j] = 0;
            }
            printf("%d", boxArray[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
    return 0;
}

