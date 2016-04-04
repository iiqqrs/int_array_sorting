#include <iostream>
using namespace std;

//Quick sort
void quick_sort(int* a, int left, int right){
    int i = left;
    int j = right;
    int middle = *(a + (left + right)/2);
    
    while(i <= j){
        while(*(a+i) < middle){
            i++;
        }
        while(*(a+j) > middle){
            j--;
        }
        if(i <= j){
            swap(*(a+i), *(a+j));
            i++;
            j--;
        }
    }
    
    if(i < right){
        quick_sort(a, i, right);
    }
    if(left < j){
        quick_sort(a, left, j);
    }    
}