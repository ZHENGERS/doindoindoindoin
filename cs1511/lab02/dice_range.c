//z5313015, William Zheng

#include <stdio.h>

int main(void) {

    float diceSides;
    printf("Enter the number of sides on your dice: ");
    scanf("%f", &diceSides);
    
    float diceNum;
    printf("Enter the number of dice being rolled: ");
    scanf("%f", &diceNum);
    
    int diceRangeLow = diceNum;
    int diceRangeHigh = diceNum * diceSides;
    float diceAverage = (diceNum + (diceNum * diceSides)) / 2;
    
    if (diceSides <= 0) {
        printf("These dice will not produce a range.\n");
    }   else if (diceNum <= 0) {
        printf("These dice will not produce a range.\n");
    } else {
        printf("Your dice range is %d to %d.\n", diceRangeLow, diceRangeHigh);
    }
   
    if (diceSides > 0 && diceNum > 0) {
        printf("The average value is %f\n", diceAverage);
    }

    return 0;

}
