#include <iostream>
#include "list.h"

int main()
{
    Double_List obj;
    int element = 0, position = 0, ch = 1, select = 1;

    std::cout <<"\n-----Main Menu-----\n";
    std::cout << "1.Add Head\n";
    std::cout << "2.Add Last\n";
    std::cout <<"-------------------\n";
    std::cout << "3.Delete Head\n";
    std::cout << "4.Delete Last\n";
    std::cout << "5.Delete At Value\n";
    std::cout << "6.Clear\n";
    std::cout <<"-------------------\n";
    std::cout << "7.Print List\n";
    std::cout << "8.Print List Size\n";
    std::cout <<"-------------------\n";
    std::cout << "9.Search\n";
    std::cout << "10.IsEmpty\n";
    std::cout << "11.Reverse\n";
    std::cout <<"-------------------\n";
    std::cout << "0.Exit";
    std::cout <<"\n-------------------\n";
    
    while (1)
    {
        std::cout << "\n\n~#Select Menu: ";
        std::cin >> ch;
        std::cout << "\n";
        
        switch (ch)
        {
            case 0:
                exit(1);
            case 1:
                select = 1;
                std::cout<<"-->Enter -1 to EXIT<--\n";
                std::cout << "Enter number";
                std::cout << "\n[" << 0 << "]" << ": ";
                std::cin >> element;
                while (element != -1) {
                    obj.addHead(element);
                    std::cout << "[" << select << "]" << ": ";
                    std::cin >> element;
                    while (std::cin.fail()) {
                        std::cout << "*Error!! Enter Number: \n";
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                        std::cin >> element;
                    }
                    ++select;
                }
                obj.print();
                break;
            case 2:
                select = 1;
                std::cout<<"-->Enter -1 to EXIT<--\n";
                std::cout << "Enter number";
                std::cout << "\n[" << 0 << "]" << ": ";
                std::cin >> element;
                while (element != -1) {
                    obj.addLast(element);
                    std::cout << "[" << select << "]" << ": ";
                    std::cin >> element;
                    while (std::cin.fail()) {
                        std::cout << "*Error!! Enter Number: \n";
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                        std::cin >> element;
                    }
                    ++select;
                }
                obj.print();
                break;
            case 3:
                std::cout << "Head Deleted..";
                obj.delHead();
                obj.print();
                break;
            case 4:
                std::cout << "Last Deleted..";
                obj.delLast();
                obj.print();
                break;
            case 5:
                std::cout << "Enter number: ";
                std::cin >> element;
                obj.del(element);
                obj.print();
                break;
            case 6:
                std::cout << "List Cleared!\n";
                obj.clear();
                break;
            case 7:
                obj.print();
                break;    
            case 8:
                std::cout << "List Size: " << obj.getCount() << "\n";
                break;
            case 9:
                std::cout << "Enter Number: ";
                std::cin >> element;
                obj.search(element);
                break;
            case 10:
                if ( obj.isEmpty() ) {
                    std::cout << "List empty..\n";
                } else {
                    std::cout << "List not empty..\n";
                }
                break;
            case 11:
                obj.reverse();
                obj.print();
                break;
            default:
                std::cout << "\n--> Illegal Option.Please try again\n";
        }
    }
    
    return 0;
}