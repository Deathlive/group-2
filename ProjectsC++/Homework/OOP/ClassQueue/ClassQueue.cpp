#include <iostream>
#include "queue.h"

queue::queue(unsigned int size) {
    if(size > 0) {
        this->size = size;
        elem = new int[size];
    } else {
        std::cout << "Write Correct Size!\n";
    }
    qend = 0;
    qbeg = 0;
    for (int i = 0; i < size; i++)
        elem[i] = 0;
}

queue::~queue() {
    delete[] elem;
}

void queue::push(int x) {
    if(!(qend == size)) {
        elem[qend++] = x;
        if (qend == size + 1)
            qend = 1;           
    } else {
        std::cout<<"--> Error! What to Push...!\n";
    }
}

void queue::pop(int& y) {
    y = elem[qbeg++];
    if (qbeg == size + 1)
        qbeg = 1;
}

bool queue::empty() {
    return (qbeg == qend);
}

void queue::clear() {
    qend = 0;
    qbeg = 0;
}

int queue::top() {
    return ( elem[qbeg]);
}