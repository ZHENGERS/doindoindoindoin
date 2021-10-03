// This program will reverse integers inputted by user
// William Zheng (z5313015)

#include<stdio.h>
#define MAX_SIZE 100

void reverse_array(int arrayNums[MAX_SIZE], int i);

int main(void) {
    int i = 0; 
    int arrayNums[MAX_SIZE] = {0};
    printf("Enter numbers forwards:\n");
    while(scanf("%d\n", &arrayNums[i]) != EOF) {
        i++;
    }
    
    reverse_array(arrayNums, i);
      
    return 0;
}

void reverse_array(int arrayNums[MAX_SIZE],int i) {
    printf("Reversed:\n");
    i = i-1;
    while (i>=0) {
        printf("%d\n", arrayNums[i]);
        i--;
    }
}
