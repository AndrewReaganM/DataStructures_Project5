#include <iostream>
//
// Created by Andrew Massey on 5/3/18.
//

#ifndef DATASTRUCTURES_PROJECT5_MINHEAP_H
#define DATASTRUCTURES_PROJECT5_MINHEAP_H

using namespace std;

class MinHeap{
protected:
    int* _array;
    int _size;
    int _maxSize;
public:
    MinHeap(int maxSize);
    void insert(int val); //Inserts a value
    int root(); //Returns the value of the root.
    void deleteRoot(); //Deletes the root value.
    int size(); //Returns the num of elements.
    bool isFull(); //Returns true if full, false if not full.
    bool isEmpty(); //Returns true if empty, false otherwise.
    int parent(int pos);
    int leftChild(int pos);
    int rightChild(int pos);

};

void MinHeap::insert(int val) {

}

MinHeap::MinHeap(int maxSize) {
    _array = new int[maxSize];
    _size = 0;
    _maxSize = maxSize;
}
int MinHeap::size() {
    return _size;
}

bool MinHeap::isFull() {
    return _size == _maxSize;
}

bool MinHeap::isEmpty() {
    return _size == 0;
}

int MinHeap::root() {
    if(!isEmpty())
    {
        return _array[0];
    }
    else{
        cout << "not good things here" << endl;
    }
}

int MinHeap::parent(int pos) {
    return (pos-1)/2;
}
int MinHeap::leftChild(int pos) {
    return 2*pos+1;
}

int MinHeap::rightChild(int pos) {
    return 2*pos+2;
}

#endif //DATASTRUCTURES_PROJECT5_MINHEAP_H
