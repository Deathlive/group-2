#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    private:
        int* arr;
        int maxCount;
        int count;
        
        void shift(int index);
    public:
        Queue(unsigned int size);
        Queue(const Queue& obj);
        ~Queue();
        void enqueue(int number);
        int dequeue();
        void show();
        void clear();
        bool isEmpty();
        bool isFull();
};

#endif // QUEUE_H