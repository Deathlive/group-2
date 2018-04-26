#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    private:
        int *elem;
        int queueBegin, queueEnd;
        unsigned int size;
    public:
        Queue(unsigned int size);
        Queue(const Queue& obj);
        ~Queue();
        void enqueue(int x);
        void dequeue();
        int beginElem();
        int endElem();
        void clear();
        bool isEmpty();
        void show();
};

#endif