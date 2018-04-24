#include <iostream>
#include "list.h"

int main()
{
    int ch = 1, element = 0, position = 0;
    double_list obj;
    
    std::cout <<"\n-----Main Menu-----\n";        
    std::cout << "1.Create Node\n";
    std::cout << "2.Display Node\n";
    std::cout << "3.Delete All\n";
    std::cout <<"-------------------\n";
    std::cout << "4.Insert at Start\n";
    std::cout << "5.Inserting after position\n";
    std::cout << "6.Delete after position\n";
    std::cout <<"-------------------\n";
    std::cout << "7.Count\n";
    std::cout << "8.Reverse\n";
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
                std::cout<<"-->Enter -1 to EXIT<--\n";
                    std::cout << "Enter number";
                    std::cout << "\n[" << 1 << "]" << ": ";
                    std::cin >> element;
                    while (element != -1) {
                        obj.create_list(element);
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
                if (obj.start == NULL) {                      
                    std::cout << "List empty..\n";   
                    break;
                }
                std::cout << "Enter the element: ";
                std::cin >> element;
                obj.insert_start(element);
                obj.display();
                break;
            case 5:
                std::cout << "Enter the element: ";
                std::cin >> element;
                std::cout << "Insert Element after postion: ";
                std::cin >> position;
                obj.add_after(element, position);
                break;
            case 6:
                if (obj.start == NULL) {                      
                    std::cout << "List empty..\n";   
                    break;
                }
                std::cout << "Enter the element for deletion: ";
                std::cin >> element;
                obj.delete_element(element);
                obj.display();
                break;
            case 7:
                obj.count();
                break;    
            case 8:
                if (obj.start == NULL) {
                    std::cout << "List empty..\n";
                    break;
                }
                obj.reverse();
                obj.display();
                break;
            default:
                std::cout << "\n--> Illegal Option.Please try again\n";
        }
    }
    return 0;
}