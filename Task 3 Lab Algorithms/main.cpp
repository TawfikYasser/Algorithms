#include <iostream>
#include<algorithm>
using namespace std;

//Function to swap
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to partition array
int partitionArray(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

//Function to find the Kth smallest element
int kthSmallestArray(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1) {
        int pos = partitionArray(arr, l, r);
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallestArray(arr, l, pos - 1, k);
        return kthSmallestArray(arr, pos + 1, r, k - pos + l - 1);
    }
    return INT_MAX;
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26}; // Unsorted Array
    int k = 3;
    int arr_size = sizeof(arr) / sizeof(arr[0]); //Getting array size
    cout<<"The Kth smallest element: "<<kthSmallestArray(arr,0,arr_size-1,k); // Send the array to quickSort
    return 0;
}
