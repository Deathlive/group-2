#include <iostream>
#include "list.h"

int main()
{
	list obj;
	int element = 0, position = 0, ch = 1;
    
    std::cout <<"\n-----Main Menu-----\n";
    std::cout << "1.Create Node\n";
    std::cout << "2.Display Node\n";
    std::cout << "3.Delete All\n";
    std::cout <<"-------------------\n";
    std::cout << "4.Insert at End\n";
    std::cout << "5.Insert at Start\n";
    std::cout << "6.Inserting after position\n";
    std::cout <<"-------------------\n";
    std::cout << "7.Delete at End\n";
    std::cout << "8.Delete at Start\n";
    std::cout << "9.Delete At Position\n";
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
                    obj.createnode(element);
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
                obj.display();
                break;
            case 3:
                std::cout << "Delete All\n";
            	obj.delete_all();
                break;
            case 4:
                std::cout << "Enter Number: ";
                std::cin >> element;
            	obj.createnode(element);
            	obj.display();
                break;
            case 5:
                if (obj.head == NULL) {
                    std::cout << "List empty..\n";
                    break;
                }
                std::cout << "Enter Number: ";
                std::cin >> element;
            	obj.insert_start(element);
            	obj.display();
                break;
            case 6:
                if (obj.head == NULL) {
                    std::cout << "List empty..\n";
                    break;
                }
                std::cout << "Enter Position: ";
                std::cin >> position;
                std::cout << "Enter Number: ";
                std::cin >> element;
            	obj.insert_position(position, element);
            	obj.display();
                break;
            case 7:
                if (obj.head == NULL) {
                    std::cout << "List empty..\n";
                    break;
                }
                obj.delete_first();
            	obj.display();
                break;
            case 8:
                if (obj.head == NULL) {
                    std::cout << "List empty..\n";
                    break;
                }
                obj.delete_last();
            	obj.display();
                break;
            case 9:
                if (obj.head == NULL) {
                    std::cout << "List empty..\n";
                    break;
                }
                std::cout << "Enter Position: ";
                std::cin >> position;
                obj.delete_position(position);
                std::cout << "Display: ";
            	obj.display();
                break;
            default:
                std::cout << "\n--> Illegal Option.Please try again\n";
        }
    }
	
	return 0;
}