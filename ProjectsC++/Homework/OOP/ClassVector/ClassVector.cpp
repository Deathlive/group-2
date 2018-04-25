#include <iostream>
#include "vector.h"

Vector::Vector() {
    maxsize = 20;
    array = new int [maxsize];
    vsize = 0;
}

Vector::Vector(unsigned int i) {
    maxsize = i;
    array = new int [maxsize];
    vsize = 0;
}

Vector::Vector(const Vector& v) {
    maxsize = v.maxsize;
    vsize = v.vsize;
    array = new int[maxsize];
    for(int i = 0; i < v.vsize; ++i) {
        array[i] = v.array[i];
    }
}

Vector::~Vector() {
    delete[] array;
}

void Vector::push_back(unsigned int i) {
    if(vsize + 1 > maxsize) {
        alloc_new();
    }
    array[vsize] = i;
    vsize++;
}
void Vector::push_front(unsigned int i) {
    if(vsize + 1 > maxsize) {
        alloc_new();
    }
    for (int i = vsize; i > 0; --i)
    {
        array[i] = array[i - 1];
    }
    array[0] = i;
    vsize++;
}

const int& Vector::operator[](int i) {
    return array[i];
}

void Vector::alloc_new() {
    maxsize = vsize * 2;
    int* tmp = new int[maxsize];
    for(int i = 0; i < vsize; ++i) {
        tmp[i] = array[i];
    }
    delete[] array;
    array = tmp;
}

int Vector::size() {
    return vsize;
}

Vector& Vector::operator+=(int i) {
    this->push_back(i);
    return *this;
}

Vector& Vector::operator=(const Vector& v) {
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

void Vector::clear() {
    for(int i = 0; i < vsize; ++i) {
        array[i] = 0;
    }
    vsize = 0;
}

void Vector::printVector() {
    if ( isEmpty() ) {
        std::cout << "Vector Is Empty\n";
    } else {
        std::cout << "Vector: ";
        for(int i = 0; i < size(); ++i) {
            std::cout << array[i] << "  ";
        }
    }
}

void Vector::popFront() {
    for(int i = 0; i < vsize; ++i) {
        array[i] = array[i + 1];
    }
    vsize--;
}

void Vector::popBack()
{
    vsize--;
}

bool Vector::isEmpty() {
    return vsize == 0;
}

void Vector::reverse() {
    int* tempData = new int[maxsize];
    for(int i = 0; i < vsize ; ++i) {
        tempData[i] = array[vsize - i - 1];
    }
    delete[] array;
    array = tempData;
}

void Vector::removeAt(int index) {
    if(index < vsize && index > -1) {
        for(int i = index; i < vsize; ++i) {
            array[i] = array[i + 1];
        }
        vsize--;
    } else {
        std::cout << "Unreacheble index!\n";
    }
}

void Vector::insert(unsigned int value, int index) {
    if(index < vsize && index > -1) {
        array[index] = value;
    }
}

void Vector::quickSortAsc(int arr[], int left, int right) {
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

void Vector::sortAsc() {
    quickSortAsc(array, 0, vsize - 1);
}

int Vector::linearSearch(int element) {
    bool founded = false;
    for(int i = 0; i < maxsize; ++i) {
        if(array[i] == element) {
            std::cout << "\nThe Number Found: " << array[i] << " - Index[" << i << "]\n";
            founded = true;
            break;
        }
    }
    
    if(!founded){
        std::cout<<"\nThe " << element << " Not found: \n";
    }
}