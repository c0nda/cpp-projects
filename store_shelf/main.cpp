#include <iostream>

#define T int

struct Arr {
    T *storage;
    size_t size;
};

T getElement(Arr a, size_t index) {
    if (index < a.size) {
        return a.storage[index];
    }
    else {
        std::cout << "Invalid index. Returned the first element" << std::endl;
        return a.storage[0];
    }
}

T removeElement(Arr &a, size_t index) {
    T delElem = -1;
    if (index < a.size){
        delElem = a.storage[index];
        T* new_arr = new T[a.size - 1];
        for (size_t i = 0; i < index; ++i){
            new_arr[i] = a.storage[i];
        }
        for (size_t i = index + 1; i < a.size; ++i){
            new_arr[i - 1] = a.storage[i];
        }
        a.storage = new_arr;
        --a.size;
        std::cout << "Deleted element: ";
        return delElem;
    } else {
        std::cout << "Invalid index" << std::endl;
        return delElem;
    }
}

void addElement(Arr &a, T elem) {
    T* new_arr = new T[a.size + 1];
    for (size_t i = 0; i < a.size; ++i){
        new_arr[i] = a.storage[i];
    }
    new_arr[a.size] = elem;
    a.storage = new_arr;
    ++a.size;
}

void resize(Arr &a, size_t newsize) {
    T* new_arr = new T[newsize];
    if (newsize > a.size){
        for (size_t i = 0; i < newsize; ++i){
            new_arr[i] = a.storage[i];
        }
        a.storage = new_arr;
    } else {
        for (size_t i = 0; i < newsize; ++i){
            new_arr[i] = a.storage[i];
        }
        a.storage = new_arr;
    }
    a.size = newsize;
}

void printInfo(Arr a){
    std::cout << "Storage: ";
    for (size_t i = 0; i < a.size; ++i){
        std::cout << getElement(a, i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Size: " << a.size << std::endl;
}

void fillRand(Arr& a){
    for (int i = 0; i < a.size; ++i){
        a.storage[i] = rand() % 10;
    }
}

int main() {

    // initialization
    Arr shelf;
    std::cout << "Input size of shelf: " << std::endl;
    std::cin >> shelf.size;
    shelf.storage = new int[shelf.size];
    fillRand(shelf);
    printInfo((shelf));

    // get element
    size_t index1;
    std::cout << "Input index of value: " << std::endl;
    std::cin >> index1;
    std::cout << "Element with index " << index1 << ": " << getElement(shelf, index1) << std::endl;

    // add element
    int value;
    std::cout << "Input value of element: " << std::endl;
    std::cin >> value;
    addElement(shelf, value);
    printInfo(shelf);

    // remove element
    size_t index2;
    std::cout << "Input index of element for removing: " << std::endl;
    std::cin >> index2;
    std::cout << removeElement(shelf, index2) << std::endl;
    printInfo(shelf);

    // resize
    size_t newsize;
    std::cout << "Input new size: " << std::endl;
    std::cin >> newsize;
    resize(shelf, newsize);
    printInfo(shelf);
    return 0;
}
