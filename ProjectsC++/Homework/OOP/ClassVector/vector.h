#ifndef VECTOR_H
#define VECTOR_H

class Vector {
    private:
        int vsize, maxsize;
        int* array;
    public:
        Vector();
        Vector(unsigned int);
        Vector(const Vector&);
        ~Vector();
        void push_back(unsigned int);
        void push_front(unsigned int);
        void alloc_new();
        int size();
        const int& operator[](int);
        Vector& operator=(const Vector&);
        Vector& operator+=(int i);
        void clear();
        void printVector();
        bool isEmpty();
        void popBack();
        void popFront();
        void reverse();
        void removeAt(int);
        void insert(unsigned int, int);
        void quickSortAsc(int arr[], int left, int right);
        void sortAsc();
        int linearSearch(int);
};

#endif // VECTOR_H