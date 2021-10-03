// COMP1511 Week 4 Lab: Calculator
//
// This program was written by William Zheng (z5313015)
//
// This program will scan in commands and prints the output as specified 
//

#include <stdio.h>
#include <math.h>
g
int powerOfNext(int b, int c);
int squareNum(int b);

int main(void) {

    int a,b,c,result, result1;
    printf("Enter instruction: ");
    while (scanf("%d",&a)!=EOF){
        if (a==1)
        {
            scanf("%d", &b);
            result = squareNum(b);
            printf("%d\n", result);
        }
        else if (a==2)
        {
            scanf("%d %d", &b, &c);
            result1 = powerOfNext(b,c);
            printf("%d\n", result1);
        }
        printf("Enter instruction: ");

    }
    return 0;
}

int powerOfNext(int b, int c) {
    int power = pow(b, c);
    return power;
}

int squareNum(int b) {
    int square = b*b;
    return square;
}


