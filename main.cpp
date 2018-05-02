#include <iostream>
#include <time.h>
#include <random>
#include "Sorting.h"

using namespace std;
clock_t start, endTime;
double cpu_time_used;

int main() {
    int** dataArr = new int *[5000];
    int** output = new int *[30];
    for(int i=0; i < 50000; i++)
    {
        dataArr[i] = new int(random());
    }
    start = clock();
    output = Sorting::insertionSort(dataArr, 5000);
    endTime = clock();
    cpu_time_used = ((double) (endTime - start)) / CLOCKS_PER_SEC;
    cout << cpu_time_used;

    for(int i=0; i < 30; i++)
    {
        cout << *output[i] << ' ';
    }

    return 0;
}

