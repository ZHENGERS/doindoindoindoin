// z5313015, William Zheng 

#include <stdio.h>

int main(void) {
    
    int numOne;
    int numTwo;
    printf("Please enter two integers: ");
    scanf("%d %d", &numOne, &numTwo);
    
    int add = numOne + numTwo;
    printf("%d + %d = %d\n", numOne, numTwo, add);
    
    return 0;
}
