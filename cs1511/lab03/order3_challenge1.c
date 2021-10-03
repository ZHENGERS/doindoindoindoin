// z5313015, William Zheng

#include <stdio.h>

 int main (void) {
    int a,b,c;
    printf("Enter integer: ");
    scanf("%d",&a);
    printf("Enter integer: ");
    scanf("%d",&b);
    printf("Enter integer: ");
    scanf("%d",&c);
    
    int max = (a > b && a >= c) * a + (b >= a && b > c) * 
               b + (c > a && c >= b) * c + (a == b &&  b == c)*a;
               
    int mid = (a >= b && a < c) * a + (a > c && a <= b) * a + (b > a && b <= c) * 
               b + (b >= c && b < a) * b + (c >= a && c < b) * c + (c > b && c <= a) * c
               + (b == a &&  a == c) * b;
               
    int min = (a <= b && a < c) * a + (b < a && b <= c) * 
               b + (c < a && c < b) * c + (a == b &&  b == c)*c;
               
    printf("The integers in order are: %d %d %d\n", min, mid, max);


}
