#include <iostream>
#include "queue.h"

int main()
{
    Queue q(10);
    int x = 0, ch = 1;
    
    std::cout <<"\n-----Main Menu-----\n";
    std::cout << "1.Enqueue\n";
    std::cout << "2.Dequeue\n";
    std::cout << "3.Full or Empty\n";
    std::cout << "4.Print All Element\n";
    std::cout << "5.Print Begin Element\n";
    std::cout << "6.Print End Element\n";
    std::cout << "7.Clear Queue\n";
    std::cout << "0.Exit";
    std::cout <<"\n--------------------\n";
    
    while(ch != 0)
    {
        std::cout << "\n\n~#Select Menu: ";
        std::cin >> ch;
        std::cout << "\n";
        
        switch(ch)
        {
            case 0:
                std::exit(1);
            case 1:
                std::cout << "Enter -1 to exit\n";
                std::cout << "Enter ONLY number: ";
                std::cin >> x;
                while(x != -1) {
                    std::cout << "Enter number: ";
                    q.enqueue(x);
                    std::cin >> x;
                    while(std::cin.fail()) {
                        std::cout << "Error!! Enter Number: \n";
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                        std::cin >> x;
                    }
                }
                q.show();
                break;
            case 2:
                q.dequeue();
                q.show();
                break;
            case 3:
                if(q.isEmpty()) {
                    std::cout << "--> Queue is empty.\n";
                } else {
                    std::cout << "--> Queue is not empty.\n";
                }
                break;
            case 4:
                q.show();
                break;
            case 5:
                std::cout << "--> Begin Element: " << q.beginElem() << "\n";
                break;
            case 6:
                std::cout << "--> End Element: " << q.endElem() << "\n";
                break;
            case 7:
                q.clear();
                std::cout << "--> Queue is CLEAR!.\n";
                q.show();
                break;
            default:
                std::cout << "\n--> Illegal Option.Please try again\n";
        }
    }
    
    return 0;
} 