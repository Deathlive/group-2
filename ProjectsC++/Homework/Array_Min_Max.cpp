#include <iostream>

int main() {
    int evenSum = 0, oddSum = 0, min, max;
    int size;
    std::cout << "Write Array Size: ";
    std::cin >> size;
    int arr[size];
    
    for(int i = 0; i < size; ++i) {
	    std::cout << "[" << i + 1 << "]:";
	    std::cin >> arr[i];
    }
    
    std::cout << "\nSource Array: ";
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n\n";
	
	min = arr[0];
	max = arr[0];
	
	for(int i = 0; i < size; ++i) {
	    if(max < arr[i]) max = arr[i];
		if(min > arr[i]) min = arr[i];
		
	    if(arr[i] % 2 == 0) {
		    evenSum += arr[i];
	    } else {
	        oddSum += arr[i];
	    }
	}
	
    std::cout << "evenSum Sum: " << evenSum << "\n";
    std::cout << "oddSum Sum: " << oddSum << "\n";
    std::cout << "Min: " << min << "\n";
	std::cout << "Max: " << max << "\n";
	
    return 0;
}