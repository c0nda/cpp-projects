#include <iostream>

#define T int

class Arr {
public:
    Arr() {
        size = 0;
        storage = nullptr;
    }

    T getElement(size_t index) {
        if (index < size) {
            return storage[index];
        } else {
            std::cout << "Invalid index. Returned the first element" << std::endl;
            return storage[0];
        }
    }

    size_t getSize() const {
        return size;
    }

    T removeElement(size_t index) {
        T delElem = -1;
        if (index < size) {
            delElem = storage[index];
            T *new_arr = new T[size - 1];
            for (size_t i = 0; i < index; ++i) {
                new_arr[i] = storage[i];
            }
            for (size_t i = index + 1; i < size; ++i) {
                new_arr[i - 1] = storage[i];
            }
            storage = new_arr;
            --size;
            std::cout << "Deleted element: ";
            return delElem;
        } else {
            std::cout << "Invalid index" << std::endl;
            return delElem;
        }
    }

    void addElement(T elem) {
        T *new_arr = new T[size + 1];
        for (size_t i = 0; i < size; ++i) {
            new_arr[i] = storage[i];
        }
        new_arr[size] = elem;
        storage = new_arr;
        ++size;
    }

    void resize(size_t newsize) {
        T *new_arr = new T[newsize];
        if (newsize > size) {
            for (size_t i = 0; i < newsize; ++i) {
                new_arr[i] = storage[i];
            }
            storage = new_arr;
        } else {
            for (size_t i = 0; i < newsize; ++i) {
                new_arr[i] = storage[i];
            }
            storage = new_arr;
        }
        size = newsize;
    }

    void printInfo() {
        std::cout << "Storage: ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << storage[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Size: " << size << std::endl;
    }

    void fillRand() {
        for (int i = 0; i < size; ++i) {
            storage[i] = rand() % 10;
        }
    }

    void setStorage(size_t new_size){
        storage = new int[new_size];
    }

    void setSize(int new_size){
        size = new_size;
    }
    bool testGetElement(){
        int fail = 0;
        for (size_t i = 0; i < size; ++i){
            if (getElement(i) != storage[i]){
                ++fail;
            }
        }
        if (fail) {
            return false;
        } else {
            return true;
        }
    }
private:
    T *storage;
    size_t size;
};


int main() {
    Arr a, b, c;
    a.setSize(5);
    a.setStorage(5);
    a.fillRand();
    a.printInfo();

    b.setSize(10);
    b.setStorage(10);
    b.fillRand();
    b.printInfo();


    std::cout << a.testGetElement() << std::endl;
    std::cout << b.testGetElement() << std::endl;

    
    return 0;
}
