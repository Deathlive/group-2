#ifndef QUEUE_H
#define QUEUE_H

class queue
{
    private:
        int *elem;
        int qend, qbeg;
        unsigned int size;
    public:
        queue(unsigned int size);
        ~queue();
        void push(int x);
        void pop(int& y);
        int  top();
        void clear();
        bool empty();
};

#endif // QUEUE_H