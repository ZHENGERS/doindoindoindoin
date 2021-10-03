//z5313015, William Zheng

#include <stdio.h>

int main(void){
    int number1;
    int number2;
    char * sum;
    int sum1;

    printf("Please enter two integers: ");
    scanf("%d",&number1);
    scanf("%d",&number2);
    sum1 = number1 + number2;

    if(number1<0){
        printf("negative ");
        number1 = -number1;
    }
    
    if (number1 == 0) {
        printf("zero");
    }   else if (number1 == 1) {
        printf("one");
    }   else if (number1 == 2) {
        printf("two");
    }   else if (number1 == 3) {
        printf("three");
    }   else if (number1 == 4) {
        printf("four");
    }   else if (number1 == 5) {
        printf("five");
    }   else if (number1 == 6) {
        printf("six");
    }   else if (number1 == 7) {
        printf("seven");
    }   else if (number1 == 8) {
        printf("eight");
    }   else if (number1 == 9) {
        printf("nine");
    }   else if (number1 == 10) {
        printf("ten");
    }   else {
        printf("%d", number1);
    }
    
    printf(" + ");

    if(number2<0){
        printf("negative ");
        number2=-number2;
    }
     
    if (number2 == 0) {
        printf("zero");
    }   else if (number2 == 1) {
        printf("one");
    }   else if (number2 == 2) {
        printf("two");
    }   else if (number2 == 3) {
        printf("three");
    }   else if (number2 == 4) {
        printf("four");
    }   else if (number2 == 5) {
        printf("five");
    }   else if (number2 == 6) {
        printf("six");
    }   else if (number2 == 7) {
        printf("seven");
    }   else if (number2 == 8) {
        printf("eight");
    }   else if (number2 == 9) {
        printf("nine");
    }   else if (number2 == 10) {
        printf("ten");
    }   else {
        printf("%d", number2);
    }
    
    printf(" = ");
    
    if(sum1 < 0){
        printf("negative ");
        sum1 = -sum1;
    }
      
    if (sum1 == 0) {
        sum = "zero";
        printf("%s\n", sum);
    }   else if (sum1 == 1) {
        sum = "one";
        printf("%s\n", sum);
    }   else if (sum1 == 2) {
        sum = "two";
        printf("%s\n", sum);
    }   else if (sum1 == 3) {
        sum = "three";
        printf("%s\n", sum);
    }   else if (sum1 == 4) {
        sum = "four";
        printf("%s\n", sum);
    }   else if (sum1 == 5) {
        sum = "five";
        printf("%s\n", sum);
    }   else if (sum1 == 6) {
        sum = "six";
        printf("%s\n", sum);
    }   else if (sum1 == 7) {
        sum = "seven";
        printf("%s\n", sum);
    }   else if (sum1 == 8) {
        sum = "eight";
        printf("%s\n", sum);
    }   else if (sum1 == 9) {
        sum = "nine";
        printf("%s\n", sum);
    }   else if (sum1 == 10) {
        sum = "ten";
        printf("%s\n", sum);
    }   else {
        printf("%d\n", sum1);
    }
    
    return 0;
}
