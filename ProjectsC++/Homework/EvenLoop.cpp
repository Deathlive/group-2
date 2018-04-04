#include <iostream>

int main() {
    int num1, num2, sum = 0;
    
    std::cout << "First num: ";
    std::cin >> num1;
    std::cout << "Second num: ";
    std::cin >> num2;
    
    if (num1 > num2) {
        std::cout << "\nError, First num is bigger";
        return 0;
    } else {
        std::cout << "Even number: ";
        for (int i = num1; i <= num2; i++) {
            if (i % 2 == 0) {
                std::cout << i << " ";
                sum += i;
            }
        }
        std::cout << "\nAddition even number: " << sum; 
    }

    return 0;
}