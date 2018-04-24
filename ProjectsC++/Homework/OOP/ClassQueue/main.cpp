#include <iostream>
#include "queue.h"

int main()
{
    queue q(5);
    int x = 0, y = 0, ch = 1;
    
    std::cout <<"\n-----Main Menu-----\n";
    std::cout << "1.Push\n";
    std::cout << "2.Pop\n";
    std::cout << "3.Full or Empty\n";
    std::cout << "4.Print Top\n";
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
                std::cout << "Enter ONLY number to push: ";
                std::cin >> x;
                while(x != -1) {
                    std::cout << "Enter the number to push: ";
                    q.push(x);
                    std::cin >> x;
                    while(std::cin.fail()) {
                        std::cout << "Error!! Enter Number: \n";
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                        std::cin >> x;
                    }
                }
                break;
            case 2:
                if(!q.empty()) {
                    std::cout<<"--> POP! -> " << q.top() << "\n";
                    q.pop(y);
                } else {
                    std::cout<<"--> Queue is empty! What to pop...!\n";
                }
                break;
            case 3:
                if(q.empty()) {
                    std::cout<<"--> Queue is empty.\n";
                } else {
                    std::cout<<"--> Queue is not empty.\n";
                }
                break;
            case 4:
                std::cout << "--> TOP! -> " << q.top() << "\n";
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