#include <iostream>
using namespace std;

// Merge sort
void merge_sort(int* a, int size){
    if(size < 2){
        return;
    }
    int middle = (size/2);
    // create 2 arrays
    // left size (middle)
    int left[middle];
    int* p2left;
    p2left = left;
    // right size (size - middle)
    int right[size-middle];
    int* p2right;
    p2right = right;
    for(int i = 0; i < middle; i++){
        //*(p2left + i) = *(a + i);
        left[i] = *(a+i);
    }
    for(int i = middle; i < size; i++){
        //*(p2right + (i-middle)) = *(a + i);
        right[i-middle] = *(a + i);
    }
    
    merge_sort(p2left, middle);
    merge_sort(p2right, (size-middle));
    //merge(p2left, middle, p2right, (size-middle), a, size);
    
    // Possibly move merge into the native function
    int i = 0; // left
    int j = 0; // right
    int k = 0; // a
    while((i < middle) && (j < (size-middle))){
        //if(*(left + i) <= *(right + j)){
        if(left[i] <= right[i]){
            //*(a + k) = *(left + i);
            *(a+k) = left[i];
            k++;
            i++;
        }else{
            //*(a + k) = *(right + j);
            *(a+k) = right[j];
            k++;
            j++;
        }
        while(i < middle){
            //*(a + k) = *(left + i);
            *(a+k) = left[i];
            k++;
            i++;
        }
        while(j < (size-middle)){
            //*(a + k) = *(right + j);
            *(a+k) = right[j];
            k++;
            j++;
        }        
    }
}

/*
void merge(int* left, int l_size, int* right, int r_size, int* a, int size){
    int i = 0; // left
    int j = 0; // right
    int k = 0; // a
    while((i < l_size) && (j < r_size)){
        if(*(left + i) <= *(right + j)){
            *(a + k) = *(left + i);
            k++;
            i++;
        }else{
            *(a + k) = *(right + j);
            k++;
            j++;
        }
        while(i < l_size){
            *(a + k) = *(left + i);
            k++;
            i++;
        }
        while(j < r_size){
            *(a + k) = *(right + j);
            k++;
            j++;
        }        
    }
}
*/