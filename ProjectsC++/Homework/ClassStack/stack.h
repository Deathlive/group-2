#include <iostream>

class Stack
{
    int top;
    int arr[10];
    
public:
    Stack()
    {
        top = 0;
    }

    void print();
    void push(int);
    void clear();
    int pop();
    int isempty();
    int isfull();
};

int Stack::isempty()
{
    return (top == 0 ? 1:0);
}

int Stack::isfull()
{
    return (top == 10 ? 1:0);
}

void Stack::clear()
{
    top = 0;
}

void Stack::push(int x)
{
    if( !isfull() ) {
        arr[top++] = x;
    } else {
        std::cout << "\nStack overflow error ! Possible Data Loss !\n";
    }
}

int Stack::pop()
{
    if( !isempty() ) {
        std::cout << "\nTop number popped from the stack\n";
        return( arr[--top] );
    } else {
        std::cout << "\nStack is empty! What to pop...!\n";
    }
    return 0;
}

void Stack::print()
{
    if(!isempty()) {
        for(int i = top - 1; i >= 0; i--) {
            std::cout << "| " << arr[i] << "\n";
        }
        std::cout << "\n";
    } else {
        std::cout << "\nStack is empty!\n";
    }
}