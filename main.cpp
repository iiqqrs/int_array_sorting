#include <iostream>
#include "shell_sort.cpp"
#include "merge_sort.cpp"
#include "quick_sort.cpp"
#include "gnome_sort.cpp"
#include <ctime>
#include <cstdlib>
using namespace std;

//Randomly populates array with size elements for sorting.
//Called before each sort so array is random
void populate(int *a, int size){
    for(int i = 0; i < size; i++){
        *(a + i) = rand() % 100;
    }
}

int main(){
    srand(time(NULL));
    //Set up time stuff
    clock_t start;
    double duration;
    int input_array_size;
    
    cout << "Enter an array size for our tests." << endl;
    cin >> input_array_size;
    int array_to_sort[input_array_size];
    int* p;
    p = array_to_sort;
    populate(p, input_array_size);
    
    //Shell Sort test.
    start = clock();
    shell_sort(p, input_array_size);
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "It took " << duration << " seconds to shell sort an array of ints of size " << input_array_size << endl;


    cout << "Too bad merge sort doesn't work yet" << endl;
/*
    //Merge Sort test.
    populate(p, input_array_size); //re generate unsorted list
    start = clock();
    merge_sort(p, input_array_size);
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "It took " << duration << " seconds to merge sort an array of ints of size " << input_array_size << endl;
*/

    //Quick Sort test.
    populate(p, input_array_size); //re generate unsorted list
    start = clock();
    quick_sort(p, 0, input_array_size-1);
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "It took " << duration << " seconds to quick sort an array of ints of size " << input_array_size << endl;

    //Gnome Sort test.
    populate(p, input_array_size); //re generate unsorted list
    start = clock();
    gnome_sort(p, input_array_size);
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "It took " << duration << " seconds to gnome sort an array of ints of size " << input_array_size << endl;
}