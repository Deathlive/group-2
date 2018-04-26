#include <iostream>
#include "list.h"

Double_List::Double_List(): first(nullptr), current(nullptr), last(nullptr), count(0) { }

Double_List::Double_List(const Double_List& obj): first(nullptr), current(nullptr), last(nullptr), count(obj.count) {
    Node* tmp = obj.first;
    Node* next = NULL;
    while(tmp) {
        first = new Node();
        first->data = tmp->data;
        first->next = tmp->next;
        next ? next->prev = first: last = first;
        next = first;
        tmp = tmp->prev;
    }
}

Double_List::~Double_List(){ 
    Node* elem = first;
    for(int i = 0; i < count; ++i) {
        Node* elemNext = elem->next;
        delete[] elem;
        elem = elemNext;
    }
}

const int& Double_List::operator [](int index){
    static int tmp = -1;
    if (count == 0 || index < count) {
        current = first;
        int i = 0;
        while(i < count) {
            if(i == index) {
                return current->data;
            }
            current = current->next;
            i++;
        }
    } else {
        std::cout << "Error: Write correct index.. ";
        return tmp;
    }
}

bool Double_List::isEmpty() const {
    return count == 0;
}

void Double_List::addHead(int value) {
    current = new Node();
    current->data = value;
    if(first) {
        first->prev = current;
        current->next = first;
    }
    if(NULL == last) {
        last = current;
    }
    first = current;
    count++;
}

void Double_List::addLast(int value) {
    current = new Node();
    current->data = value;
    if (last) {
        last->next = current;
        current->prev = last;
    }
    if(NULL == first) {
        first = current;
    }
    last = current;
    count++;
}

int Double_List::getCount() const { 	
    return count;
}

void Double_List::print() {
    if(first == NULL) {
        std::cout << "List empty,nothing to display\n";
        return;
    }
    current = first;
    std::cout << "\nDisplay: ";
    while(current != NULL) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}

void Double_List::delHead() {
    if(count == 0) {
        std::cout << "Empty list!\n";
        return;
    }
    Node* temp = first;
    first = first->next;
    delete temp;
    count--;
    if(first == nullptr) {
        last = nullptr;
    }
}

void Double_List::delLast() {
    
    Node* temp = new Node();
    temp = last;
    if (last->prev != NULL) {
        last->prev->next = NULL;
    }
    last = last->prev;
    count--;
}

void Double_List::del(int value) {
    if (first->data == value) {
        current = first;
        first = first->next;  
        first->prev = NULL;
        std::cout<<"Element Deleted\n";
        free(current);
        return;
    }
    last = first;
    while (last->next->next != NULL) {
        if (last->next->data == value) {
            current = last->next;
            last->next = current->next;
            current->next->prev = last;
            std::cout<<"Element Deleted\n";
            free(current);
            return;
        }
        last = last->next;
    }
    
    if (last->next->data == value) { 	
        current = last->next;
        free(current);
        last->next = NULL;
        std::cout<<"Element Deleted\n";
        return;
    }
    std::cout << "Element " << value << " not found\n";
}

void Double_List::clear() {
    while(first != nullptr) {
        delHead();
    }
}

void Double_List::reverse() {
    Node *p1, *p2;
    p1 = first;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while(p2 != NULL) {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; 
    }
    first = p1;
    std::cout << "List Reversed\n";
}

int Double_List::search(int value) {
    bool founded = false;
    if(count == 0) {
        
    }
    current = first;
    int i = 0;
    while(i < count) {
        if(value == current->data) {
            std::cout << "\nThe Number Found: " << value << " - Index[" << i << "]\n";
            founded = true;
        }
        i++;
        current = current->next;
    }
    
    if(!founded){
        std::cout<<"\nThe " << value << " Not found: \n";
    }
}