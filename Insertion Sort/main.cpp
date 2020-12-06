#include <iostream>

using namespace std;

void insertionSort(int arr[],int n){
    for(int i = 1 ; i <n ; i++){

        int temp = arr[i]; // The first element of the unsortedList from the left
        int j = i - 1 ; //The first element of the sorted list from the right
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j]; // Shift if the element of unsorted list is > the element of sorted list
            j--; // decrement the sorted list index
        }
        arr[j+1] = temp; // Put the element in appropriate place in the sorted list
    }
}

//Print the sorted array
void printSortedArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int arr[] = {9,3,7,5,6,4,8,2}; // Unsorted Array
    int arr_size = sizeof(arr) / sizeof(arr[0]); //Getting array size
    insertionSort(arr,arr_size); // Send the array to mergeSort
    printSortedArray(arr,arr_size); // Print the sorted array
    return 0;
}
