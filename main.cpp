#include <iostream>
#include <time.h>
#include <random>
#include "Sorting.h"

using namespace std;
clock_t start, endTime;
double cpu_time_used;

int main() {

    int** A;
    int** B;
    int X[] = {1000,2000,3000,4000,5000,6000,7000,8000,9000,100000};
    cpu_time_used = 0; //Tracks the time used in ticks.


    A = new int*[30]; //Test array main
    B = new int*[30]; //Test array slave
    for (int i = 0; i < 30; ++i) { //Create random numbers
        A[i] = new int(random()); //Create 30 random numbers
    }
    for (int i = 0; i < 30; ++i) { //Copy over
        B[i] = new int(*A[i]);
    }

    Sorting::insertionSort(B, 30); //Sort using Insertion Sort

    for (int i = 0; i < 30; i++) { //Output sorted array.
        cout << *B[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < 30; ++i) { //Copy over
        B[i] = new int(*A[i]);
    }

    Sorting::selectionSort(B, 30); //Sort using Selection Sort

    for (int i = 0; i < 30; i++) { //Output sorted array.
        cout << *B[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < 30; ++i) { //Copy over
        B[i] = new int(*A[i]);
    }

    Sorting::quickSort(B, 0, 29, 30); //Sort using Selection Sort

    for (int i = 0; i < 30; i++) { //Output sorted array.
        cout << *B[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < 30; ++i) { //Copy over
        B[i] = new int(*A[i]);
    }

    Sorting::heapSort(B, 30); //Sort using Selection Sort

    for (int i = 0; i < 30; i++) { //Output sorted array.
        cout << *B[i] << ' ';
    }
    cout << endl;
    delete [] A;

//////////////////////////// Main Timing /////////////////////////////

    for(int k=0; k< 10; k++)
    {
        A = new int*[X[k]]; //Create master array
        B = new int*[X[k]]; //Create slave array

        for(int q = 0; q<10; q++)
        {
            for (int i = 0; i < X[k]; ++i) { //Create random numbers
                A[i] = new int(random()); //Fill master array
            }
            for (int i = 0; i < X[k]; ++i) { //Copy over
                B[i] = new int(*A[i]); //Fill slave array
            }
            start = clock(); //Starts the timer
            Sorting::insertionSort(B, X[k]); //Sorts the array
            endTime = clock(); //Ends the timer
            cpu_time_used += ((double) (endTime - start)) / CLOCKS_PER_SEC; //Calculates time in seconds.


        }
        cout << "Insertion Sort @ " << X[k] << " = ";
        cout << (cpu_time_used/10) << " sec" << endl;
        cpu_time_used = 0;

        for(int q = 0; q<10; q++)
        {
            for (int i = 0; i < X[k]; ++i) { //Create random numbers
                A[i] = new int(random());
            }
            for (int i = 0; i < X[k]; ++i) { //Copy over
                B[i] = new int(*A[i]);
            }
            start = clock();
            Sorting::selectionSort(B, X[k]);
            endTime = clock();
            cpu_time_used += ((double) (endTime - start)) / CLOCKS_PER_SEC;


        }
        cout << "Selection Sort @ " << X[k] << " = ";
        cout << (cpu_time_used/10) << " sec" << endl;
        cpu_time_used = 0;

        for(int q = 0; q<10; q++)
        {
            for (int i = 0; i < X[k]; ++i) { //Create random numbers
                A[i] = new int(random());
            }
            for (int i = 0; i < X[k]; ++i) { //Copy over
                B[i] = new int(*A[i]);
            }
            start = clock();
            Sorting::heapSort(B, X[k]);
            endTime = clock();
            cpu_time_used += ((double) (endTime - start)) / CLOCKS_PER_SEC;


        }
        cout << "Heap Sort @ " << X[k] << " = ";
        cout << (cpu_time_used/10) << " sec" << endl;
        cpu_time_used = 0;

        for(int q = 0; q<10; q++)
        {
            for (int i = 0; i < X[k]; ++i) { //Create random numbers
                A[i] = new int(random());
            }
            for (int i = 0; i < X[k]; ++i) { //Copy over
                B[i] = new int(*A[i]);
            }
            start = clock();
            Sorting::quickSort(B, 0, X[k]-1, X[k]);
            endTime = clock();
            cpu_time_used += ((double) (endTime - start)) / CLOCKS_PER_SEC;


        }
        cout << "Quick Sort @ " << X[k] << " = ";
        cout << (cpu_time_used/10) << " sec" << endl;
        cpu_time_used = 0;
    }






    /*int size = 1000;
    int **dataArr = new int *[size];
    for (int i = 0; i < size; ++i) {
        dataArr[i] = new int(random());
    }
    dataArr[13] = new int(2);

    start = clock();
    Sorting::heapSort(dataArr, size);
    endTime = clock();

    cpu_time_used = ((double) (endTime - start)) / CLOCKS_PER_SEC;
    cout << cpu_time_used;
    cout << endl;
    for (int i = 0; i < 30; i++) {
        cout << *dataArr[i] << ' ';
    }*/
}


