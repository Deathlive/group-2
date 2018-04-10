#include <iostream>
#include <cstdlib>
#include <ctime>

void PrintArray(int* array, int n);

void BubbleSort(int* array, int size);
void QuickSort(int* array, int start, int end);
void ShakerSort(int* array, int size);
void CombSort(int* array, int size);

int main() {
    srand(time(NULL));
    
    int size;
    std::cout << "Array Size: ";
    std::cin >> size;
    
    int array1[size];
    int array2[size];
    int array3[size];
    int array4[size];
    for(int i = 0; i < size; ++i)
    {
        array1[i] = (rand() % 100) + 1;
        array2[i] = (rand() % 100) + 1;
        array3[i] = (rand() % 100) + 1;
        array4[i] = (rand() % 100) + 1;
    }
    
    std::cout << "Source Array1: ";
    PrintArray(array1, size);
    std::cout << "Source Array2: ";
    PrintArray(array2, size);
    std::cout << "Source Array3: ";
    PrintArray(array3, size);
    std::cout << "Source Array4: ";
    PrintArray(array4, size);
    
    BubbleSort(array1, size);
    std::cout << "Bubble Sorted Array1: ";
    PrintArray(array1, size);
    
    QuickSort(array2, 0, size);
    std::cout << "Quick Sorted Array2: ";
    PrintArray(array2, size);
    
    ShakerSort(array3, size);
    std::cout << "Shaker Sorted Array3: ";
    PrintArray(array3, size);
    
    CombSort(array4, size);
    std::cout << "Comb Sorted Array4: ";
    PrintArray(array4, size);
    
    return 0;
}

void PrintArray(int* array, int n) {
   for(int i = 0; i < n; ++i) {
    	std::cout << array[i] << " ";
    }
    std::cout << "\n\n";
}

void BubbleSort(int* array, int size) {
	for(int i = 1; i < size; ++i)
    {
    	for(int r = 0; r < size - i; r++)
    	{
    		if(array[r] > array[r + 1])
    		{
    			int temp = array[r];
    			array[r] = array[r + 1];
    			array[r + 1] = temp;
    		}
    	}
    }
}

void QuickSort(int* array, int start, int end) {
    int i = start;
    int j = end;
    int mid = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < mid)
            i++;
        while (array[j] > mid)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > start)
        QuickSort(array, start, j);
    if (i < end)
        QuickSort(array, i, end);
        
}

void ShakerSort(int* array, int size) {
    for (int i = 0; i < size / 2; i++) {
        bool swapped = false;
        for (int j = i; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                swapped = true;
            }
        }
        
        for (int j = size - 2 - i; j > i; j--) {
            if (array[j] < array[j - 1]) {
                int tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
                swapped = true;
            }
        }

        if(!swapped) break;
    }
}

void CombSort(int* array, int size) {
	double gap = size;
	bool swaps = true;

	while (gap > 1 || swaps)
	{
		gap /= 1.247330950103979;

		if (gap < 1)
			gap = 1;

		int i = 0;
		swaps = false;

		while (i + gap < size)
		{
			int igap = i + (int)gap;

			if (array[i] > array[igap])
			{
				int temp = array[i];
				array[i] = array[igap];
				array[igap] = temp;
				swaps = true;
			}

			++i;
		}
	}
}