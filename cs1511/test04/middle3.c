// William Zheng (z5313015)
// Prints middle integer from 3 inputted

#include <stdio.h>

void middle_num (int a,int b,int c);

int main(void) {
    int num1, num2, num3;
    printf("Enter integer: ");
    scanf("%d", &num1);
    printf("Enter integer: ");
    scanf("%d", &num2);
    printf("Enter integer: ");
    scanf("%d", &num3);  
    middle_num (num1, num2, num3);
    return 0;
}

void middle_num (int a,int b, int c) {
    if ((a<b && b<c) || (c<b && b<a)) {
        printf("Middle: %d\n", b);
    } 
    else if ((b<a && a<c) || (c<a && a<b)) {
        printf("Middle: %d\n", a);
    }
    else if ((b<c && c<a) || (a<c && c<b)) {
        printf("Middle: %d\n", c);   
    }
    else if (a==b && b==c) {
        printf("Middle: %d\n", a);
    }
    else if ((a>b && a==c) || (a==b && a>c)) {
        printf("Middle: %d\n", a);
    }
    else if ((b>c && b==a) || (b==c && b>a)) {
        printf("Middle: %d\n", b);
    }
    else if ((c>a && c==b) || (c==a && c>b)) {
        printf("Middle: %d\n", c);
    }
    else if ((a==b && a<c) || (a==c && a<b)) {
        printf("Middle: %d\n",a);
    }        
    else if (b==c && b<a) {
        printf("Middle: %d\n",b);
    }
}
