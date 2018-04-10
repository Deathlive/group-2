#include <iostream>
#include <cstdlib>
#include <ctime>

void SortSource(int source[], int n)
{
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

int BinarySearch(int source[], int size, int key, int start, int end)
{
	int mid = (start + end) / 2;
	
	if(source[mid] == key)
		return mid;
		
	else if((start >= size || end <= 0) && source[mid] != key)
		return -1;
		
	else
	{
		if(key < source[mid])
		{
			BinarySearch(source, size, key, start, mid - 1);
		}
		else if(key > source[mid])
		{
			BinarySearch(source, size, key, mid + 1, end);
		}
	}
}

int main() {
    srand(time(NULL));
    
	int size, num;
	int source[100];
	
	std::cout << "Write the Length of the Array: ";
    std::cin >> size;
    
    for(int i = 0; i < size; i++) {
        source[i] = (rand() % 100) + 1;
    }
    
    std::cout << "\nArray Elements: ";
	for(int k = 0; k < size; k++)
		std::cout << source[k] << " ";
	std::cout << "\n";
	
	SortSource(source, size);
	
	std::cout << "\nEnter the element to be searched: ";
	std::cin >> num;
	
	int key = BinarySearch(source, size, num, 0, size);
	if(key >= 0)
		std::cout<<"\nYour " << source[key] << " Number Find at index["<< key + 1 <<"]\n";
	else
		std::cout<<"\nNot Found Your Number!\n";
	return 0;
}