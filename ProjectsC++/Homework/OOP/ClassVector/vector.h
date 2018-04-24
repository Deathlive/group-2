#ifndef VECTOR_H
#define VECTOR_H

class vector {
    private:
        int vsize,maxsize;
        int* array;
    public:
        vector();
        vector(int);
        vector(const vector&);
        ~vector();
        void push_back(int);
        void push_front(int);
        void alloc_new();
        int size();
        int operator[](int);
        vector& operator=(const vector&);
        vector& operator+=(int i);
        int at(int i);
        void clear();
        void printVector();
        bool isEmpty();
        void popBack();
        void popFront();
        void reverse();
        void removeAt(int);
        void insert(int, int);
        void quickSortAsc(int arr[], int left, int right);
        void sortAsc();
};

#endif // VECTOR_H