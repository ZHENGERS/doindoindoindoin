//Prints the first n digits of pi, where n is specified 
// by the user
// z5313015, William Zheng

#include <stdio.h>

#define MAX_DIGITS 10

int main(void) {
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int digits;
    printf("How many digits of pi would you like to print? ");
    scanf("%d", &digits);

    int i = 0;
   
    while (i<digits)
    {
       printf("%d", pi[i]);
       if (i==0 && digits!=1)
       {
          printf(".");
       }
       i++; 
    }
    printf("\n");

    return 0;
}
