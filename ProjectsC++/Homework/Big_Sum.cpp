#include <iostream>
#include <cstdlib>

int main () {
    srand(time(NULL));
    
    long sum = 0;
    long sumend = 0;
    int start, end, y = 0;
    
    std::cout << "Enter Range: ";
    int x;
    std::cin >> x;
    int arr[x];
    
    for(int i = 0; i < x; i++){
        arr[i] = (rand() % 20 + 1) - 10;
        std::cout<< arr[i] << " ";
    }
    std::cout << "\n\n";
    
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < x - i; j++){
            sum = 0;
            int k;
            k = j;
            y++;
            while(k >= 0){
                sum+=arr[i+k];
                k--;
            }
            if(sum > sumend){
                sumend = sum;
                start = i + 1;
                end = i + j + 1;
            }
        }
    }
    
    std::cout << "Sum: " << sumend;
    std::cout << "\nStart Index: " << start;
    std::cout << "\nEnd Index: " << end;
    std::cout << "\n";
    
    return 0;
}