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
    int** selectionSort(int** input, int size);
    int** heapSort(int** input, int size);
    int** quickSort(int** input, int size);
};

int** Sorting::insertionSort(int** arr, int length) {
    for (int i = 1; i < length; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            int tmp = *arr[j];
            *arr[j] = *arr[j - 1];
            *arr[j - 1] = tmp;
        }
    }
    return arr;
}
int** Sorting::selectionSort(int** input, int size)
{
    //int** retArr = int[10];


}

int** Sorting::heapSort(int** input, int size)
{
    //int** retArr = int[10];


}

int** Sorting::quickSort(int** input, int size)
{
    //int** retArr = int[10];


}

#endif //DATASTRUCTURES_PROJECT5_SORTING_H
