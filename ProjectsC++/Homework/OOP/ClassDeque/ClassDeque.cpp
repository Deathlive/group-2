#include <iostream>
#include "deque.h"

Deque::Deque() {
    front = NULL;
    last = NULL;
    count = 0;
}      

Deque::~Deque() {
    Node* elem = front;
    for(int i = 0; i < count; ++i) {
        Node* elemNext = elem->next;
        delete[] elem;
        elem = elemNext;
    }
}   

void Deque::insertFront(int element) {
    Node* tmp = new Node();
    tmp->data = element;
    tmp->next = NULL;
    tmp->prev = NULL;

    if ( isEmpty() ) {
        front = last = tmp;
    } else {
        tmp->next = front;
        front->prev = tmp;
        front = tmp;
    }

    count++;
}

int Deque::removeFront() {
    if ( isEmpty() ) {
        std::cout << "Deque empty: ";
        return -1;
    } else {

        int ret = front->data;
    
        Node* tmp = front;
        if ( front->next != NULL ) {
            front = front->next;
            front->prev = NULL;
        } else {
            front = NULL;
        }
        
        count--;
        delete tmp;
    
        return ret;
    }
}

void Deque::insertBack(int element) {          
    Node* tmp = new Node();
    tmp->data = element;
    tmp->next = NULL;
    tmp->prev = NULL;

    if ( isEmpty() ) {
        front = last = tmp;
    } else {
        last->next = tmp;
        tmp->prev = last;
        last = tmp;
    }

    count++;
}

int Deque::removeBack() {
    if ( isEmpty() ) {
        std::cout << "Deque empty: ";
        return -1;
    } else {

        int ret = last->data;
    
        Node* tmp = last;
        if ( last->prev != NULL ) {
            last = last->prev;
            last->next = NULL;
        } else {
            last = NULL;
        }
        
        count--;
        delete tmp;
    
        return ret;
    }
}

int Deque::pFront() {          
    if ( isEmpty() ) {
        std::cout << "Deque empty: ";
        return -1;
    } else {

        return front->data;
    }
}

int Deque::pBack() {
    if ( isEmpty() ) {
        std::cout << "Deque empty: ";
        return -1;
    } else {

        return last->data;
    }
}

int Deque::size() {
    return count;
}

bool Deque::isEmpty() {
    return count == 0;
}

void Deque::clear() {
    while(front != nullptr) {
        if(count == 0) {
            std::cout << "Empty list!\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;
        if(front == nullptr) {
            last = nullptr;
        }
    }
}

void Deque::print() {
    if ( isEmpty() ) {
        std::cout << "deque Is Empty\n";
    } else {
        Node *temp = new Node;
        temp = front;
        std::cout << "Display: ";
        while (temp != NULL) {
            std::cout << temp->data << "  ";
            temp = temp->next;
        }
    }
}