#ifndef DEQUE_H
#define DEQUE_H

class Deque {  
    private:
        struct Node {
            int data;
            Node* next;
            Node* prev;
        };
        Node* front;
        Node* last;
        int count;
    public:
        Deque();
        Deque(const Deque&);
        ~Deque();
        void insertFront(int element);
        int removeFront();
        void insertBack(int element);
        int removeBack();
        int pFront();
        int pBack();
        int size();
        bool isEmpty();
        void clear();
        void print();
};

#endif // DEQUE_H