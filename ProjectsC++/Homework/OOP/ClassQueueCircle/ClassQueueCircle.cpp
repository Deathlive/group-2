#include <iostream>
#include "queue.h"

Queue::Queue(unsigned int size) {
    if(size > 0) {
        this->size = size;
        elem = new int[size];
    } else {
        std::cout << "Write Correct Size!\n";
    }
    queueEnd = 0;
    queueBegin = 0;
    for (int i = 0; i < size; ++i)
        elem[i] = 0;
}

Queue::Queue(const Queue& obj) {
    queueEnd = 0;
    queueBegin = 0;
    elem = new int[size];
    for(int i = 0; i < size; ++i) {
        elem[i] = obj.elem[i];
    }
}

Queue::~Queue() {
    delete[] elem;
}

void Queue::enqueue(int x) {
    elem[queueEnd++] = x;
    if (queueEnd == size)
        queueEnd = 0;
}

void Queue::dequeue() {
    std::cout << "--> POP " << elem[queueBegin] << "\n";
    elem[queueBegin++] = 0;
    if (queueBegin == size)
        queueBegin = 0;
}

bool Queue::isEmpty() {
    return queueBegin == queueEnd;
}

void Queue::clear() {
    queueEnd = 0;
    queueBegin = 0;
    for (int i = 0; i < size; ++i)
        elem[i] = 0;
}

int Queue::beginElem() {
    return elem[queueEnd];
}

int Queue::endElem() {
    return elem[queueBegin];
}

void Queue::show() {
    std::cout << "------------------------------\n";
    for (int i = 0; i < size; ++i) {
        std::cout << elem[i] << "  ";
    }
    std::cout << "\n";
    std::cout << "------------------------------\n";
}