#include <iostream>
using namespace std;

//Shell sort
void shell_sort(int* a, int size){
    int increment;
    int i;
    int j;
    int buffer;
    for(increment = size/2; increment > 0; increment /= 2){
        for(i = increment; i<size; i++){
            buffer = *(a + i);
            for(j = i; j >= increment; j-=increment){
                if(buffer < *(a + (j-increment))){
                    *(a + j) = *(a + (j-increment));
                }else{
                    break;
                }
            }
            *(a + j) = buffer;
        }
    }
}