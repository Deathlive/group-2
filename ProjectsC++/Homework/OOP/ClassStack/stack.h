#include <iostream>

class Stack
{
    int top;
    int* arr;
    unsigned int size;
    
public:
    Stack(unsigned int size) {
        if(size > 0) {
            this->size = size;
            arr = new int[size];
        } else {
            std::cout << "Write Correct Size!\n";
        }
        top = 0;
    }
    
    ~Stack() {
        delete [] arr;
    }

    void print();
    void push(int);
    void clear();
    int pop();
    int isEmpty();
    int isFull();
};

int Stack::isEmpty()
{
    return (top == 0);
}

int Stack::isFull()
{
    return (top == 10);
}

void Stack::clear()
{
    top = 0;
}

void Stack::push(int x)
{
    if( !isFull() ) {
        arr[top++] = x;
    } else {
        std::cout << "\nStack overflow error ! Possible Data Loss !\n";
    }
}

int Stack::pop()
{
    if( !isEmpty() ) {
        std::cout << "\nTop number popped from the stack\n";
        return arr[--top];
    } else {
        std::cout << "\nStack is empty! What to pop...!\n";
    }
    return -1;
}

void Stack::print()
{
    if(!isEmpty()) {
        for(int i = top - 1; i >= 0; i--) {
            std::cout << "| " << arr[i] << "\n";
        }
    } else {
        std::cout << "\nStack is empty!\n";
    }
}