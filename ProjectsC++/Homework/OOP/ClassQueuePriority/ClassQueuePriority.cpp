#include <iostream>
#include "queue.h"

Queue::Queue(unsigned int size) {
    maxCount = size;
    count = 0;
    arr = new int[maxCount];
}

Queue::Queue(const Queue& obj) {
    maxCount = obj.maxCount;
    count = obj.count;
    arr = new int[maxCount];
    for(int i = 0; i < obj.count; ++i) {
        arr[i] = obj.arr[i];
    }
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::enqueue(int number) {
    if( isEmpty() ) {
        arr[0] = number;
        count++;
    } else if( !isFull() ) {
        for(int i = 0; i < count; ++i) {
            if(number >= arr[i]) {
                shift(i);
                arr[i] = number;
                count++;
                break;
            }
        }
    }
}

int Queue::dequeue() {
    int result = -1;

    if( !isEmpty() ) {
        int first = arr[0];
        for(int i = 1; i < count; ++i) {
            arr[i - 1] = arr[i];
        }
        count--;
        result = first;
    }

    return result;
}

bool Queue::isEmpty() {
    return count == 0;
}

bool Queue::isFull() {
    return count == maxCount;
}

void Queue::clear() {
    for(int i = 0; i < maxCount; ++i) {
        arr[i] = 0;
    }
    count = 0;
}

void Queue::show() {
    std::cout << "------------------------------\n";
    for (int i = 0; i < count; ++i) {
        std::cout << arr[i] << "  ";
    }
    std::cout << "\n";
    std::cout << "------------------------------\n";
}

void Queue::shift(int index) {
    if ( !isEmpty() ) {
        for(int i = count; i > index; --i) {
            arr[i] = arr[i - 1];
        }
    }
}