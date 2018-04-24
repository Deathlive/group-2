#include <iostream>
#include "vector.h"

vector::vector() {
    maxsize = 20;
    array = new int [maxsize];
    vsize = 0;
}

vector::vector(int i) {
    maxsize = i;
    array = new int [maxsize];
    vsize = 0;
}

vector::vector(const vector& v) {
    maxsize = v.maxsize;
    vsize = v.vsize;
    array = new int[maxsize];
    for(int i = 0; i < v.vsize; ++i) {
        array[i] = v.array[i];
    }
    
}

vector::~vector() {
    delete[] array;
}

void vector::push_back(int i) {
    if(vsize + 1 > maxsize) {
        alloc_new();
    }
    array[vsize] = i;
    vsize++;
}
void vector::push_front(int i) {
    alloc_new();
    for (int i = vsize; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = i;
    vsize++;
}

int vector::operator[](int i) {
    return array[i];
}

int vector::at(int i) {
    if(i < vsize) {
        return array[i];
    }
}

void vector::alloc_new() {
    maxsize = vsize * 2;
    int* tmp = new int[maxsize];
    for(int i = 0; i < vsize; ++i) {
        tmp[i] = array[i];
    }
    delete[] array;
    array = tmp;
}

int vector::size() {
    return vsize;
}

vector& vector::operator+=(int i) {
    this->push_back(i);
    return *this;
}

vector& vector::operator=(const vector& v) {
    if(this != &v) {
        maxsize = v.maxsize;
        vsize = v.vsize;
        delete[] array;
        array = new int [maxsize];
        for(int i = 0; i < v.vsize; ++i) {
            array[i] = v.array[i];
        }
    }
    return *this;
}

void vector::clear() {
    for(int i = 0; i < vsize; i++) {
        array[i] = 0;
    }
    vsize = 0;
}

void vector::printVector() {
    if ( isEmpty() ) {
        std::cout << "Collection Is Empty\n";
    } else {
        std::cout << "Vector: ";
        for(int i = 0; i < size(); ++i) {
            std::cout << array[i] << " ";
        }
    }
}

void vector::popFront() {
    for(int i = 0; i < vsize; ++i) {
        array[i] = array[i + 1];
    }
    vsize--;
}

void vector::popBack()
{
    vsize--;
}

bool vector::isEmpty() {
    return vsize == 0;
}

void vector::reverse() {
    int* tempData = new int[maxsize];
    for(int i = 0; i < vsize ; ++i) {
        tempData[i] = array[vsize - i - 1];
    }
    delete[] array;
    array = tempData;
}

void vector::removeAt(int index) {
    if(index < vsize && index > -1) {
        for(int i = index; i < vsize; i++) {
            array[i] = array[i + 1];
        }
        vsize--;
    } else {
        std::cout << "Unreacheble index!\n";
    }
}

void vector::insert(int value, int index) {
    if(index < vsize && index > -1) {
        array[index] = value;
    }
}

void vector::quickSortAsc(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    if (left < j)
        quickSortAsc(arr, left, j);
    if (i < right)
        quickSortAsc(arr, i, right);
}

void vector::sortAsc() {
    quickSortAsc(array, 0, vsize - 1);
}