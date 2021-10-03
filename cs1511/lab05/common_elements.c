// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination
// William Zheng (z5313015)
#include<stdio.h>
int common_elements(int length, int source1[length], int source2[length], int destination[length]) {
   int commonCounter = 0;
   int i = 0;
   while(i < length) {
        int j = 0;
        while(j < length) {
            if(source1[i] == source2[j]) {
                destination[commonCounter] = source1[i];
                commonCounter++;
                break;
            } else {
                j++;
            }
      }  
       i++;
   }
    return commonCounter;
}
