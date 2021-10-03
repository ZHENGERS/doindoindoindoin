// z5313015, William Zheng

#include <stdio.h>

int main(void) {
    
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    int i = 1;
    int sum = 0;
    
    printf("The factors of %d are:\n", num);
    while (i <= num)
    {   

        if (num % i == 0)
        {
            printf("%d\n", i);
            sum = sum + i;
        }
        i++;
    }
    
    printf("Sum of factors = %d\n", sum);
    
    if ((sum - num) == num )
    {
        printf("%d is a perfect number\n", num);
    } 
    else
    {
        printf("%d is not a perfect number\n", num);
    }
    
    return 0;
}
