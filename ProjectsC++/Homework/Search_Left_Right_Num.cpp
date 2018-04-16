#include <iostream>
#include <cstdlib>
#include <ctime>

void SortSource(int source[], int n)
{
    std::cout << "\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(source[i] > source[j])
            {
                std::swap(source[i], source[j]);
            }
        }
    }
    
    std::cout << "\nSorted Array Elements: ";
    for(int k = 0; k < n; k++)
        std::cout << source[k] << " ";
    std::cout << "\n";
}

int main() {
    srand(time(NULL));
    
    int size, num;
    std::cout << "Enter size: ";
    std::cin >> size;
    int arr[size];
    std::cout << "\n";
    
    for(int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 + 1;
    }
    
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    
    std::cout << "\n\nEnter num: ";
    std::cin >> num;
    std::cout << "\n";
    
    arr[size] = num;
    size = size + 1;
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    
    SortSource(arr, size);
    
    for(int i = 0; i < size; i++) {
        if (arr[i] == num) {
            if (arr[i - 1] == num || arr[i + 1] == num) {
                std::cout << "\nThe Number Found: " << arr[i];
                break;
            } else if (i == 0) {
                std::cout << "\nThe Number Found: " << arr[i + 1];
                break;
            } else if (i == size - 1) {
                std::cout << "\nThe Number Found: " << arr[i - 1];
                break;
            } else {
                std::cout << "\nThe Number Found: " << arr[i - 1] << " and " << arr[i + 1];
                break;
            }
        }
    }
    std::cout << "\n";
    
    return 0;
}