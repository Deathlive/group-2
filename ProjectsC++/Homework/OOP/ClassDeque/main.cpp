#include <iostream>
#include "deque.h"

int main() {
    Deque obj;
    
    int element = 0, position = 0, ch = 1;
    
    std::cout <<"\n-----Main Menu-----\n";
    std::cout << "1.Push Back\n";
    std::cout << "2.Push Front\n";
    std::cout << "3.Pop Back\n";
    std::cout << "4.Pop Front\n";
    std::cout <<"-------------------\n";
    std::cout << "5.Front \n";
    std::cout << "6.Back\n";
    std::cout << "7.Print Deque\n";
    std::cout << "8.Print Size\n";
    std::cout <<"-------------------\n";
    std::cout << "9.Clear\n";
    std::cout << "10.isEmpty\n";
    std::cout <<"-------------------\n";
    std::cout << "0.Exit";
    std::cout <<"\n-------------------\n";
    
    while(ch != 0)
    {
        std::cout << "\n\n~#Select Menu: ";
        std::cin >> ch;
        std::cout << "\n";
        
        switch(ch)
        {
            case 0:
                exit(1);
            case 1:
                std::cout<<"-->Enter -1 to EXIT<--\n";
                std::cout << "Enter number";
                std::cout << "\n[" << 1 << "]" << ": ";
                std::cin >> element;
                while (element != -1) {
                    obj.insertBack(element);
                    std::cout << "[" << ch + 1 << "]" << ": ";
                    std::cin >> element;
                    while (std::cin.fail()) {
                        std::cout << "*Error!! Enter Number: \n";
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                        std::cin >> element;
                    }
                    ++ch;
                }
                break;
            case 2:
                std::cout<<"-->Enter -1 to EXIT<--\n";
                std::cout << "Enter number";
                std::cout << "\n[" << 1 << "]" << ": ";
                std::cin >> element;
                while (element != -1) {
                    obj.insertFront(element);
                    std::cout << "[" << ch + 1 << "]" << ": ";
                    std::cin >> element;
                    while (std::cin.fail()) {
                        std::cout << "*Error!! Enter Number: \n";
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                        std::cin >> element;
                    }
                    ++ch;
                }
                break;
            case 3:
                std::cout << obj.removeBack() << "\n";
                break;
            case 4:
                std::cout << obj.removeFront() << "\n";
                break;
            case 5:
                std::cout << obj.pFront() << "\n";
                break;
            case 6:
                std::cout << obj.pBack() << "\n";
                break;
            case 7:
                obj.print();  
                break;
            case 8:
                std::cout << "Size of dequeue: " << obj.size() << "\n";    
                break;
            case 9:
                std::cout << "Decue CLEAN!\n"; 
                obj.clear();  
                break;
            case 10:
                if ( obj.isEmpty() ) {
                    std::cout << "Deque is empty\n";
                } else {
                    std::cout << "Deque is not empty\n";
                }
                break;
            default:
                std::cout << "\n--> Illegal Option.Please try again\n";
        }
    }
    
    return 0;
}