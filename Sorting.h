#include <iostream>

//
// Created by Andrew Massey on 5/1/18.
//

#ifndef DATASTRUCTURES_PROJECT5_SORTING_H
#define DATASTRUCTURES_PROJECT5_SORTING_H
using namespace std;

class Sorting
{
public:
    static int** insertionSort(int** input, int size);
    static int** selectionSort(int** input, int size);
    static int** heapSort(int** input, int size);
    static void heapify(int** arr, int n, int i);
    static int** quickSort(int** input, int left, int right, int length);
    static void swap(int *xVal, int *yVal);
};

int** Sorting::insertionSort(int** arr, int length) {
    int i, key, j;
    for (i = 1; i < length; i++)
    {
        key = *arr[i];
        j = i-1;

        while (j >= 0 && *arr[j] > key)
        {
            *arr[j+1] = *arr[j];
            j = j-1;
        }
        *arr[j+1] = key;
    }
    return arr;
}
int** Sorting::selectionSort(int** arr, int length)
{
    int i;
    int j;
    int pos;
    for ( i = 0 ; i < ( length - 1 ) ; i++ ) //Sorts through the entire array
    {
        pos = i;

        for ( j = i + 1 ; j < length ; j++ ) //Sorts through the unsorted elements.
        {
            if ( *arr[pos] > *arr[j] )
                pos = j;
        }
        if ( pos != i )
        {
            swap(arr[i], arr[pos]);
        }
    }

    return arr;
}

void Sorting::heapify(int **arr, int length, int i) {
    int lrg = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < length && *arr[left] > *arr[lrg])
    {
        lrg = left;
    }
    if(right < length && *arr[right] > *arr[lrg])
    {
        lrg = right;
    }

    if(lrg != i)
    {
        swap(arr[i], arr[lrg]);
        heapify(arr, length, lrg);
    }

}

int** Sorting::heapSort(int** arr, int length)
{
    for(int i = (length / 2) - 1; i >= 0; i--)
    {
        heapify(arr, length, i);
    }
    for(int i=length-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
    return arr;
}

int** Sorting::quickSort(int** arr, int left, int right, int length)
{
    if (left < right)
    {
        int pivot = *arr[left]; //Choose Pivot

        int i = left; //Partitioning
        int j = right + 1;

        do{
            do{
                i = i+1;
            }
            while((i < length) && (*arr[i] < pivot));
            do
                j = j-1;
            while(*arr[j] > pivot);
            if(i < j)
                swap(arr[i], arr[j]); //Swapping the values.
        }
        while (i < j);
        swap(arr[left], arr[j]); //Swapping the values.
        quickSort(arr, left, j-1, length); //Recursion
        quickSort(arr, j+1, right, length); //Recursion

    }
    return arr;
}

void Sorting::swap(int *xVal, int *yVal) {
    //cout << "Swapping " << *xVal << " and " << *yVal << endl;
    int temp = *xVal;
    *xVal = *yVal;
    *yVal = temp;
}

#endif //DATASTRUCTURES_PROJECT5_SORTING_H
