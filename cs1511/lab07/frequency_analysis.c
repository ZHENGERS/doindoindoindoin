// William Zheng (z5313015)

#include <stdio.h>
#include <string.h>

#define ALPHA_SIZE 27

void storeFrequency(char alpha[ALPHA_SIZE], char message, int freqArr[ALPHA_SIZE]);
void storeFreqPerc (int freqArr[ALPHA_SIZE], double freqPercArr[ALPHA_SIZE], int charCounter);

int main(void) {
    char alpha[ALPHA_SIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                              'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int freqArr[ALPHA_SIZE] = {0};
    double freqPercArr[ALPHA_SIZE] = {0};
    int charCounter = 0;
    int message = getchar();
    int j = 0;
    while (message != EOF) {
        if ((message >= 'a' && message <= 'z') || (message >= 'A' && message <= 'Z')) {
            charCounter++;
        } 
        storeFrequency(alpha, message, freqArr);
        message = getchar();
        j++;
    }
    storeFreqPerc(freqArr, freqPercArr, charCounter);
    int i = 0;
    while(i < ALPHA_SIZE-1) {
        printf("'%c' %lf  %d\n", alpha[i], freqPercArr[i], freqArr[i]);
        i++;
    }
}

void storeFrequency(char alpha[ALPHA_SIZE], char message, int freqArr[ALPHA_SIZE]) {
    int i = 0;
    while (i < ALPHA_SIZE) {
        if (alpha[i] == message || alpha[i] - 32 == message) {
            freqArr[i] = freqArr[i] + 1;
        }
        i++;
    }
}


void storeFreqPerc (int freqArr[ALPHA_SIZE], double freqPercArr[ALPHA_SIZE], int charCounter) {
    int i = 0;
    while (i < ALPHA_SIZE) {
        if (charCounter != 0) {
            freqPercArr[i] = (freqArr[i]*1.0)/(charCounter*1.0);
        }
        else {
            freqPercArr[i] = 0;
        }
        i++;
    }
}

