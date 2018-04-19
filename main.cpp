#include <iostream>
#include <time.h>

using namespace std;
clock_t start, endTime;
double cpu_time_used;

int main() {
    start = clock();
    int* dataArr = new int[500000000];
    for(int i=0; i < 500000000; i++)
    {
        (dataArr[i]) = (int) random();
    }

    endTime = clock();
    cpu_time_used = ((double) (endTime - start)) / CLOCKS_PER_SEC;
    cout << cpu_time_used;

    return 0;
}

int** insertionSort(int**)
{
    int** retArr = new int*[10];


}

int** selectionSort(int**)
{
    //int** retArr = int[10];


}

int** heapSort(int**)
{
    //int** retArr = int[10];


}

int** quickSort(int**)
{
    //int** retArr = int[10];


}