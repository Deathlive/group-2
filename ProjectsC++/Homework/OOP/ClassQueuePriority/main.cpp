#include <iostream>
#include "queue.h"

int main()
{
    Queue q(5);
    int element = 0, ch = 1;
    
    std::cout <<"\n-----Main Menu-----\n";
    std::cout << "1.Enqueue\n";
    std::cout << "2.Dequeue\n";
    std::cout << "3.Full or Empty\n";
    std::cout << "4.Print Queue\n";
    std::cout << "5.Clear Queue\n";
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
                exit(1);
            case 1:
                std::cout<<"Enter -1 to exit\n";
                std::cout << "Enter number: ";
                std::cin >> element;
                while(element != -1) {
                    std::cout << "Enter number: ";
                    q.enqueue(element);
                    std::cin >> element;
                    while(std::cin.fail()) {
                        std::cout << "Error!! Enter Number: \n";
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                        std::cin >> element;
                    }
                }
                q.show();
                break;
            case 2:
                q.dequeue();
                q.show();
                break;
            case 3:
                if( q.isEmpty() ) {
                    std::cout<<"--> Queue is empty.\n";
                } 
                else if( q.isFull() )  {
                    std::cout<<"--> Queue is full.\n";
                } else {
                    std::cout<<"--> Queue is not empty.\n";
                }
                break;
            case 4:
                q.show();
                break;
            case 5:
                q.clear();
                std::cout<<"--> Queue is CLEAR!.\n";
                break;
            default:
                std::cout<<"\n--> Illegal Option.Please try again\n";
        }
    }
    
    return 0;
}