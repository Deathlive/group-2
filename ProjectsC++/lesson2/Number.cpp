#include <iostream>

int main() {
    int x;
    std::cout << "Enter number 1-9999: " << std::endl;
    std::cin >> x;
    
    if (x > 0 && x < 10000) {
        switch (x / 1000) {
            case 1 : std::cout << " one thousand "; break;
            case 2 : std::cout << " two thousand "; break;
            case 3 : std::cout << " three thousand "; break; 
            case 4 : std::cout << " four thousand "; break;
            case 5 : std::cout << " five thousand "; break;
            case 6 : std::cout << " six thousand "; break;
            case 7 : std::cout << " seven thousand "; break;
            case 8 : std::cout << " eight thousand "; break;
            case 9 : std::cout << " nine thousand "; break;    
        }
        
         switch ((number % 1000) / 100) {
            case 1 : std::cout << " one hundred "; break;
            case 2 : std::cout << " two hundred "; break;
            case 3 : std::cout << " three hundred  "; break;
            case 4 : std::cout << " four hundred "; break;
            case 5 : std::cout << " five hundred "; break;
            case 6 : std::cout << " six hundred "; break;
            case 7 : std::cout << " seven hundred "; break;
            case 8 : std::cout << " eight hundred "; break;
            case 9 : std::cout << " nine hundred "; break;
        }  
        
        switch ((x % 100) / 10) {
            case 1 : std::cout << " ten "; break;
            case 2 : std::cout << " twenty "; break;
            case 3 : std::cout << " thirty "; break;
            case 4 : std::cout << " forty "; break;
            case 5 : std::cout << " fifty "; break;
            case 6 : std::cout << " sixty "; break;
            case 7 : std::cout << " seventy "; break;
            case 8 : std::cout << " eighty "; break;
            case 9 : std::cout << " ninety "; break;
        }
        
        switch (x % 10) {
            case 1 : std::cout << " one "<<std::endl; break;
            case 2 : std::cout << " two "<<std::endl; break;
            case 3 : std::cout << " three "<<std::endl; break;
            case 4 : std::cout << " four "<<std::endl; break;
            case 5 : std::cout << " five  "<<std::endl; break;
            case 6 : std::cout << " six  "<<std::endl; break;
            case 7 : std::cout << " seven  "<<std::endl; break;
            case 8 : std::cout << " eight  "<<std::endl; break;
            case 9 : std::cout << " nine  "<<std::endl; break;
        }
    } else {
          std::cout << "Error" << std::endl;
      }
    
    return 0;
}