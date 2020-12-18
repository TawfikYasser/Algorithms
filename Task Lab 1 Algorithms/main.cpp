#include<iostream>
#include<Time.h>
#include<sys/time.h>
#include<ctime>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

//Function for Sequential Search
int recursiveSequntialSearch(int arr[], int l, int r, int x)
{
    if (r < l)
        return -1;
    if (arr[l] == x)
        return l;
    if (arr[r] == x)
        return r;
    return recursiveSequntialSearch(arr, l + 1, r - 1, x);
}

//Function for Binary Search
int recursiveBinarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return recursiveBinarySearch(arr, l, mid - 1, x);

        return recursiveBinarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

//Function to generate random array
int* generateRandomArray(int _size) {
	srand(time(0));
	int* arr = new int[_size];
	for (int i = 0; i < _size; i++) {
		arr[i] = rand() % _size + 0;
	}
	return arr;
}

int main()
{
    //Declarations
    int lim1 = 1000, lim2 = 10000, lim3 = 100000, findElement = 259;
    int* unsortedArray;
    time_t startingTime,endingTime;

    cout<<"Sequential Search ************************************************************************************"<<endl;

    //1. Array with 1000 element -> Sequential Search
    unsortedArray = generateRandomArray(lim1);
    startingTime = time(0);
    char* stringStartingTime1 = ctime(&startingTime);
    cout<<"Starting time for array["<<lim1<<"] "<<stringStartingTime1<<endl;
    cout<<"Index of "<<findElement<<" :"<<recursiveSequntialSearch(unsortedArray,0,lim1-1,findElement)<<endl;
    endingTime = time(0);
    char* stringEndingTime1 = ctime(&endingTime);
    cout<<"Ending time for array["<<lim1<<"] "<<stringEndingTime1<<endl;
    cout<<"Difference in time : "<<endingTime-startingTime<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;


    //2. Array with 10000 element -> Sequential Search
    unsortedArray = generateRandomArray(lim2);
    startingTime = time(0);
    char* stringStartingTime2 = ctime(&startingTime);
    cout<<"Starting time for array["<<lim2<<"] "<<stringStartingTime2<<endl;
    cout<<"Index of "<<findElement<<" :"<<recursiveSequntialSearch(unsortedArray,0,lim2-1,findElement)<<endl;
    endingTime = time(0);
    char* stringEndingTime2 = ctime(&endingTime);
    cout<<"Ending time for array["<<lim2<<"] "<<stringEndingTime2<<endl;
    cout<<"Difference in time : "<<endingTime-startingTime<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;

    //3. Array with 100000 element -> Sequential Search
    unsortedArray = generateRandomArray(lim3);
    startingTime = time(0);
    char* stringStartingTime3 = ctime(&startingTime);
    cout<<"Starting time for array["<<lim3<<"] "<<stringStartingTime3<<endl;
    cout<<"Index of "<<findElement<<" :"<<recursiveSequntialSearch(unsortedArray,0,lim3-1,findElement)<<endl;
    endingTime = time(0);
    char* stringEndingTime3 = ctime(&endingTime);
    cout<<"Ending time for array["<<lim3<<"] "<<stringEndingTime3<<endl;
    cout<<"Difference in time : "<<endingTime-startingTime<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;


    cout<<"Binary Search ************************************************************************************"<<endl;

    //1. Array with 1000 element -> Binary Search
    unsortedArray = generateRandomArray(lim1);
    sort(unsortedArray,unsortedArray+lim1);
    startingTime = time(0);
    char* stringStartingTime1bs = ctime(&startingTime);
    cout<<"Starting time for array["<<lim1<<"] "<<stringStartingTime1bs<<endl;
    cout<<"Index of "<<findElement<<" :"<<recursiveBinarySearch(unsortedArray,0,lim1-1,findElement)<<endl;
    endingTime = time(0);
    char* stringEndingTime1bs = ctime(&endingTime);
    cout<<"Ending time for array["<<lim1<<"] "<<stringEndingTime1bs<<endl;
    cout<<"Difference in time : "<<endingTime-startingTime<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;

    //2. Array with 10000 element -> Binary Search
    unsortedArray = generateRandomArray(lim2);
    sort(unsortedArray,unsortedArray+lim2);
    startingTime = time(0);
    char* stringStartingTime2bs = ctime(&startingTime);
    cout<<"Starting time for array["<<lim2<<"] "<<stringStartingTime2bs<<endl;
    cout<<"Index of "<<findElement<<" :"<<recursiveBinarySearch(unsortedArray,0,lim2-1,findElement)<<endl;
    endingTime = time(0);
    char* stringEndingTime2bs = ctime(&endingTime);
    cout<<"Ending time for array["<<lim2<<"] "<<stringEndingTime2bs<<endl;
    cout<<"Difference in time : "<<endingTime-startingTime<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;


    //3. Array with 100000 element -> Binary Search
    unsortedArray = generateRandomArray(lim3);
    sort(unsortedArray,unsortedArray+lim3);
    startingTime = time(0);
    char* stringStartingTime3bs = ctime(&startingTime);
    cout<<"Starting time for array["<<lim3<<"] "<<stringStartingTime3bs<<endl;
    cout<<"Index of "<<findElement<<" :"<<recursiveBinarySearch(unsortedArray,0,lim3-1,findElement)<<endl;
    endingTime = time(0);
    char* stringEndingTime3bs = ctime(&endingTime);
    cout<<"Ending time for array["<<lim3<<"] "<<stringEndingTime3bs<<endl;
    cout<<"Difference in time : "<<endingTime-startingTime<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;

    return 0;
}
