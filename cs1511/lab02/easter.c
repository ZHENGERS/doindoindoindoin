//z5313015, William Zheng

#include <stdio.h>

int main(void) {

    int year;
    printf("Enter Year: ");
    scanf("%d", &year);
    
    int a,b,c,d,e,f,g,h,i,k,l,m,p;   
    a=year%19;
    b=year/100;
    c=year%100;
    d=b/4;
    e=b%4;
    f=(b+8)/25;
    g=(b-f+1)/3;
    h=(19*a+b-d-g+15)%30;
    i=c/4;
    k=c%4;
    l=(32+2*e+2*i-h-k)%7;
    m=(a+11*h+22*l)/451;
    p=(h+l-7*m+114)%31;
    
    int month = (h+l-7*m+114)/31;
    int date = p+1;
    char * month1;
    if (month == 3) {
        month1 = "March";
        printf("Easter is %s %d in %d.\n", month1, date, year);
    }   else if (month == 4) {
        month1 = "April";
        printf("Easter is %s %d in %d.\n", month1, date, year);   
    }

    
    return 0;

}
