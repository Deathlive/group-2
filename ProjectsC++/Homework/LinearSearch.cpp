#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL));
    
    int size, num;
    bool founded = false;
    
    std::cout << "Write the Length of the Array: ";
    std::cin >> size;
    
    int array[size] = {};
    
    for(int i = 0; i < size; i++) {
        array[i] = (rand() % 100) + 1;
    }
    
    std::cout<<"\nArray Elements: ";
    for(int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "\nEnter the element to be searched: ";
    std::cin >> num;
    
    for(int i = 0; i < size; i++) {
        if(array[i] == num) {
            std::cout << "\nThe Number Found: " << array[i] << " - Index[" << i + 1 << "]\n";
            founded = true;
            break;
        }
    }
    
    if(!founded){
        std::cout<<"\nThe " << num << " Not found: \n";
    }
    
    return 0;
}