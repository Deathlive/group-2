#include <iostream>
#include "list.h"

List::List(): head(nullptr), tail(nullptr), count(0) { }

List::List(const List& list): head(nullptr), tail(nullptr), count(0) {
    for(int i = 0; i < list.getCount(); ++i) {
        Node* temp = new Node();
        temp->data = list[i];
        if(tail == nullptr) {
            head = temp;
        } else {
            tail->next = temp;
        }
        tail = temp;
        count++;
    }
}

List::~List() {
    Node* elem = head;
    for(int i = 0; i < count; ++i) {
        Node* elemNext = elem->next;
        delete[] elem;
        elem = elemNext;
    }
}

const int& List::operator [](int index) const {
    static int tmp = -1;
    if (count == 0 || index < count) {
        Node* temp = head;
        int i = 0;
        while(i < count) {
            if(i == index) {
                return temp->data;
            }
            temp = temp->next;
            i++;
        }
    } else {
        std::cout << "Error: Write correct index.. ";
        return tmp;
    }
}

void List::addHead(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;
    if(head == nullptr) {
        tail = temp;
    }
    head = temp;
    count++;
}

void List::addTail(int data) {
    Node* temp = new Node();
    temp->data = data;
    if(tail == nullptr) {
        head = temp;
    } else {
        tail->next = temp;
    }
    tail = temp;
    count++;
}

void List::insert(int data, int position) {
    if(position >= count) {
        addTail(data);
        return;
    }
    else if(position <= 0) {
        addHead(data);
        return;
    }

    Node* temp = new Node();
    temp->data = data;
    int i = 1;
    Node* beforeNew = head;
    while(i++ != position) {
        beforeNew = beforeNew->next;
    }
    temp->next = beforeNew->next;
    beforeNew->next = temp;

    count++;
}

void List::delHead() {
    if(count == 0) {
        std::cout << "Empty list!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    count--;
    if(head == nullptr) {
        tail = nullptr;
    }
}

void List::delTail() {
    if(count == 0) {
        std::cout << "Empty list!\n";
        return;
    }
    del(count - 1);
}

void List::del(int position) {
    if(position <= 0) {
        delHead();
        return;
    }

    if(position >= count) {
        position = count - 1;
    }

    int i = 1;
    Node* beforeDel = head;
    while(i++ != position) {
        beforeDel = beforeDel->next;
    }
    Node* sacrifice = beforeDel->next;
    beforeDel->next = sacrifice->next;
    delete sacrifice;
    count--;
    if(beforeDel->next == nullptr) {
        tail = beforeDel;
    }
}

void List::clear() {
    while(head != nullptr) {
        delHead();
    }
}

void List::print() const {
    if(count == 0) {
        std::cout << "Empty list!\n";
        return;
    }
    Node* current = head;
    std::cout << "\nList: ";
    while(current != nullptr) {
        std::cout << current->data << "  ";
        current = current->next;
    }
    std::cout << "\n";
}

int List::getCount() const {
    return count;
}

int List::search(int data) const {
    bool founded = false;
    if(count == 0) {
        
    }
    Node* temp = head;
    int i = 0;
    while(i < count) {
        if(data == temp->data) {
            std::cout << "\nThe Number Found: " << data << " - Index[" << i << "]\n";
            founded = true;
        }
        i++;
        temp = temp->next;
    }
    
    if(!founded){
        std::cout<<"\nThe " << data << " Not found: \n";
    }
}

bool List::isEmpty() const {
    bool result = false;

    if(count == 0) {
        result = true;
    }

    return result;
}

void List::reverse() {
    Node* currNode = head;
    Node* prevNode = nullptr;
    Node* nextNode = nullptr;
    
    while(currNode != nullptr) {
      nextNode = currNode->next;
      currNode->next = prevNode;
      prevNode = currNode;
      currNode = nextNode;
    }
    
    head = prevNode;
}