#include <iostream>
#include "vector.h"

int main() {
    vector vec;
    int element = 0, position = 0, ch = 1;
    
    std::cout <<"\n-----Main Menu-----\n";
    std::cout << "1.Push Back in Vector\n";
    std::cout << "2.Push Front in Vector\n";
    std::cout << "3.Pop Back in Vector\n";
    std::cout << "4.Pop Front in Vector\n";
    std::cout <<"-------------------\n";
    std::cout << "5.Print Vector\n";
    std::cout << "6.Print Vector Size\n";
    std::cout << "7.Insert Vector value\n";
    std::cout << "8.Remove at index\n";
    std::cout <<"-------------------\n";
    std::cout << "9.Clear\n";
    std::cout << "10.isEmpty\n";
    std::cout << "11.Reverse\n";
    std::cout << "12.Quick Sort\n";
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
                    vec.push_back(element);
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
                std::cout << "Enter number: ";
                std::cin >> element;
                vec.push_front(element);
                vec.printVector();
                break;
            case 3:
                vec.popBack();
                vec.printVector();
                break;
            case 4:
                vec.popFront();
                vec.printVector();
                break;
            case 5:
                vec.printVector();
                break;
            case 6:
                std::cout << "Vector Size: " << vec.size() << "\n";
                break;
            case 7:
                std::cout << "Enter Index: ";
                std::cin >> position;
                std::cout << "Enter Value: ";
                std::cin >> element;
                vec.insert(element, position);
                break;
            case 8:
                std::cout << "Enter Index: ";
                std::cin >> element;
                vec.removeAt(element);
                vec.printVector();
                break;
            case 9:
                std::cout << "Delete All\n";
                vec.clear();
                break;
            case 10:
                if( vec.isEmpty() ) {
                    std::cout << "Is Empty\n";
                } else {
                    std::cout << "Not Empty\n";
                }
                break;
            case 11:
                vec.reverse();
                vec.printVector();
                break;
            case 12:
                vec.sortAsc();
                vec.printVector();
                break;
            default:
                std::cout << "\n--> Illegal Option.Please try again\n";
        }
    }
    
    return 0;
}