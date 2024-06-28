#include "IntegerArrayQueue.h"

bool IntegerArrayQueue::enqueue(int value)
{
    if ((front == 0 && back == size- 2 || back == front - 2)) {
        return false;
    }
    else {
        back = (back + 1) % size;
        array[back] = value;
        
        return true;
    }
}

int IntegerArrayQueue::dequeue()
{
    if (front - back == 1 || (back == size - 1 && front == 0)) {
        return 0;
    }
    else {
        int frontValue = array[front];
        front = (front + 1) % size;
        
        return frontValue;
    }
}