#include <iostream>

//
// Created by Andrew Massey on 5/1/18.
//

#ifndef DATASTRUCTURES_PROJECT5_SORTING_H
#define DATASTRUCTURES_PROJECT5_SORTING_H
using namespace std;
/**
 * A class of simple sorting algorithms. Includes:
 * - Insertion Sort
 * - Selection Sort
 * - Heap Sort
 * - Quick Sort (from "Data Structures Featuring C++" by Sridhar Radhakrishnan)
 * along with helper methods:
 * - Swap
 * - Heapify
 *
 */
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
/**
 * Insertion Sort Algorithm
 * @param arr the array of values to sort.
 * @param length the size of the array.
 * @return the sorted array.
 */
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
/**
 * Selection Sort Algorithm
 * @param arr the array of values to sort.
 * @param length the size of the array.
 * @return the sorted array.
 */
int** Sorting::selectionSort(int** arr, int length)
{
    int i; //Creates tracking variables
    int j;
    int pos;
    for ( i = 0 ; i < ( length - 1 ) ; i++ ) //Sorts through the entire array
    {
        pos = i; //Sets first element to check to the first unsorted element.

        for ( j = i + 1 ; j < length ; j++ ) //Sorts through the unsorted elements.
        {
            if ( *arr[pos] > *arr[j] ) //If the element checked is smaller than others,
                pos = j; //Store its position in pos.
        }
        if ( pos != i ) // If pos is not == i, swap. (this avoids a useless swap.)
        {
            swap(arr[i], arr[pos]); //Swaps the elements
        }
    }

    return arr; //Returns the array for convenience.
}
/**
 * Heapify Algorithm used in Sorting::heapSort.
 * @param arr the array to be heapified.
 * @param length the size/length of the array.
 * @param i the root.
 */
void Sorting::heapify(int **arr, int length, int i) {
    int lrg = i;
    int left = 2*i + 1; //Location of left child
    int right = 2*i + 2; //Location of right child.

    if(left < length && *arr[left] > *arr[lrg])//if left index is smaller than length, and left val greater that lrg val
    {
        lrg = left; //Set lrg = left
    }
    if(right < length && *arr[right] > *arr[lrg])//If right idx is smlr than len, & right val is grtr than lrg val
    {
        lrg = right; //Set lrg = right
    }

    if(lrg != i) //If the values in question are not equal
    {
        swap(arr[i], arr[lrg]); //Swap them
        heapify(arr, length, lrg); //Recursively heapify
    }

}
/**
 * Heap Sorting Algorithm
 * @param arr the array of values to sort.
 * @param length the size/length of the array.
 * @return the sorted array.
 */
int** Sorting::heapSort(int** arr, int length)
{
    for(int i = (length / 2) - 1; i >= 0; i--)
    {
        heapify(arr, length, i); //heapify the array
    }
    for(int i=length-1; i>=0; i--)
    {
        swap(arr[0], arr[i]); //Re-arrange the array, moving root to end

        heapify(arr, i, 0); //re-heapify
    }
    return arr;
}
/**
 * Quick Sort Algorithm from "Data Structures Featuring C++" by Sridhar Radhakrishnan
 * @param arr the array of values to sort.
 * @param left the left most index.
 * @param right the right most index.
 * @param length the size/length of the array
 * @return the sorted array.
 */
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
/**
 * A simple method to swap two given elements.
 * @param xVal one of the values to swap.
 * @param yVal the other value to swap.
 */
void Sorting::swap(int *xVal, int *yVal) {
    //cout << "Swapping " << *xVal << " and " << *yVal << endl;
    int temp = *xVal;
    *xVal = *yVal;
    *yVal = temp;
}

#endif //DATASTRUCTURES_PROJECT5_SORTING_H
