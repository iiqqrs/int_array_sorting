#include <iostream>
#include "shell_sort.cpp"
#include <ctime>
using namespace std;

//Randomly populates array with size elements for sorting.
//Called before each sort so array is random
void populate(int *a, int size){
    for(int i = 0; i < size; i++){
        *(a + i) = rand() % 2147483647;
    }
}

int main(){
    //Set up time stuff
    clock_t start;
    double duration;
    int input_array_size;
    
    cout << "Enter an array size for shell sort." <<endl;
    cin >> input_array_size;
    int array_to_sort[input_array_size];
    int* p;
    p = array_to_sort;
    populate(p, input_array_size);
    
    /*for(int i : array_to_sort){
        cout << " " << i <<endl;
    }*/
    
    //Shell Sort test.
    start = clock();
    shell_sort(p, input_array_size);
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "It took " << duration << " seconds to shell sort an array of ints of size " << input_array_size <<endl;
}