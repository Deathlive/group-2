#include <iostream>
#include "list.h"

int main()
{
	List obj;
	int element = 0, position = 0, ch = 1, select = 1;
    
    std::cout <<"\n-----Main Menu-----\n";
    std::cout << "1.Add Head\n";
    std::cout << "2.Add Tail\n";
    std::cout << "3.Insert\n";
    std::cout <<"-------------------\n";
    std::cout << "4.Delete Head\n";
    std::cout << "5.Delete Tail\n";
    std::cout << "6.Delete At Index\n";
    std::cout << "7.Clear\n";
    std::cout <<"-------------------\n";
    std::cout << "8.Print List\n";
    std::cout << "9.Print List Size\n";
    std::cout <<"-------------------\n";
    std::cout << "10.Search\n";
    std::cout << "11.IsEmpty\n";
    std::cout << "12.Reverse\n";
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
                select = 1;
                std::cout << "-->Enter -1 to EXIT<--\n";
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
                std::cout << "-->Enter -1 to EXIT<--\n";
                std::cout << "Enter number";
                std::cout << "\n[" << 0 << "]" << ": ";
                std::cin >> element;
                while (element != -1) {
                    obj.addTail(element);
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
                std::cout << "Enter Position: ";
                std::cin >> position;
                std::cout << "Enter Number: ";
                std::cin >> element;
                obj.insert(element, position);
                obj.print();
                break;
            case 4:
                std::cout << "Head Deleted..";
                obj.delHead();
                obj.print();
                break;
            case 5:
                std::cout << "Tail Deleted..";
                obj.delTail();
                obj.print();
                break;
            case 6:
                std::cout << "Enter Index: ";
                std::cin >> position;
                obj.del(position);
                obj.print();
                break;
            case 7:
                std::cout << "List Cleared!\n";
                obj.clear();
                break;
            case 8:
                obj.print();
                break;
            case 9:
                std::cout << "List Size: " << obj.getCount() << "\n";
                break;
            case 10:
                std::cout << "Enter Number: ";
                std::cin >> element;
                obj.search(element);
                break;
            case 11:
                if ( obj.isEmpty() ) {
                    std::cout << "List empty..\n";
                } else {
                    std::cout << "List not empty..\n";
                }
                break;
            case 12:
                obj.reverse();
                obj.print();
                break;
            default:
                std::cout << "\n--> Illegal Option.Please try again\n";
        }
    }
	
	return 0;
}