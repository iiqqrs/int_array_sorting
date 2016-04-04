#include <iostream>
using namespace std;

// Gnome sort
void gnome_sort(int* a, int size){
    int i;
    while(i < size){
        if(i==0 or *(a+(i-1)) <= *(a+i)){
            i++;
        }else{
            swap(*(a+i), *(a+(i-1)));
            i--;
        }
    }
}