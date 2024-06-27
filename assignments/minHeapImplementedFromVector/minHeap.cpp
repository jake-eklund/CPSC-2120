/*
 * Name: Jake Eklund
 * Date Submitted: November 27, 2023
 * Lab Section: 007
 * Assignment Name: Min-Heap Implementation Using a Vector
 */

#include <iostream>
#include "minHeap.h"
using namespace std;

void minHeap::siftUp(int pos) {
    while (pos > 0 && heap[pos] < heap[(pos - 1) / 2]) {
        swap(heap[pos], heap[(pos - 1) / 2]);
        pos = (pos - 1) / 2;
    }
}

void minHeap::siftDown(int pos) {
    int head = pos;
    int left = 2 * head + 1;
    int right = 2 * head + 2;
    int temp = -1;

    if (left < (int)heap.size() && heap[left] < heap[head]) {
        temp = left;
    }

    if (right < (int)heap.size() && heap[right] < heap[head]) {
        if (temp == -1) {
            temp = right;
        }
        else if (heap[right] < heap [left]) {
            temp = right;
        }

    }

    if (temp == -1) {
        return;
    }

    int helper = heap[head];
    heap[head] = heap[temp];
    heap[temp] = helper;
    siftDown(temp);
}

minHeap::minHeap(vector<int> v) {
    heap.resize(0);
    for(int i = 0;i<(int)v.size();i++) heap.push_back(v[i]);
    for(int i=heap.size()-1;i>=0;i--) siftDown(i);
}

void minHeap::insert(int value) {
    heap.push_back(value);
    int pos = heap.size() - 1;
    siftUp(pos);
}

int minHeap::removeMin() {
    if(heap.size() == 0) {
        return -1;
    }

    int temp = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap[heap.size() - 1] = temp;
    heap.pop_back();
    siftDown(0);
    
    return temp;
}