#include <iostream>
#include "stack.h"

int main() {
    Stack myStack;
    int ch = 1, num = 0;
    
    while(ch != 0)
    {
        std::cout <<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "Stack Operations Mani Menu\n";
        std::cout << "1.Push\n";
        std::cout << "2.Pop\n";
        std::cout << "3.IsEmpty\n";
        std::cout << "4.IsFull\n";
        std::cout << "5.Print Stack\n";
        std::cout << "6.Clear Stack\n";
        std::cout << "0.Exit";
        std::cout <<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "Select Menu: ";
        std::cin >> ch;
        std::cout << "\n";
        
        switch(ch)
        {
            case 0:
                exit(1);
            case 1:
                std::cout<<"Enter -1 to exit\n";
                std::cout << "Enter ONLY number to push: ";
                std::cin >> num;
                while(num != -1) {
                    std::cout << "Enter the number to push: ";
                    myStack.push(num);
                    std::cin >> num;
                    while(std::cin.fail()) {
                        std::cout << "Error!! Enter Number: " << std::endl;
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                        std::cin >> num;
                    }
                }
                break;
            case 2:
                myStack.pop();
                break;
            case 3:
                if(myStack.isempty()) {
                        std::cout<<"Stack is empty.\n";
                    } else {
                        std::cout<<"Stack is not empty.\n";
                    }
                break;
            case 4:
                if(myStack.isfull()) {
                    std::cout<<"Stack is full.\n";
                } else {
                    std::cout<<"Stack is not full.\n";
                }
                break;
            case 5:
                myStack.print();
                break;
            case 6:
                myStack.clear();
                std::cout<<"Stack is CLEAR!.\n";
                break;
            default:
                std::cout<<"Illegal Option.Please try again\n";
        }
    }
    return 0;
}