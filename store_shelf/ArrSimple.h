#pragma once

#include <iostream>
#include "StandardFunctions.h"

template<typename T>
class ArrSimple {
public:
    ArrSimple() {
        size_ = 0;
        storage_ = nullptr;
        cur_marker_ = nullptr;
    }

    ArrSimple(int new_size) {
        if (new_size < 1) {
            std::cout << "Invalid size" << std::endl;
        }
        size_ = new_size;
        storage_ = new T[size_];
        cur_marker_ = storage_;
    }

    ArrSimple(const ArrSimple<T> &arr) {
        size_ = arr.size_;
        storage_ = new T[size_];
        cpymem(storage_, arr.storage_, size_);
        cur_marker_ = storage_;
    }

    ~ArrSimple() {
        if (storage_ != nullptr) {
            delete[] storage_;
        }
    }

    ArrSimple<T> &operator=(const ArrSimple<T> &arr) {
        if (this != &arr) {
            delete[] storage_;
            size_ = arr.size_;
            storage_ = new T[size_];
            cpymem(storage_, arr.storage_, size_);
        }
        return *this;
    }

    size_t getSize() const { return size_; }

    void removeElement(size_t);

    void addElement(T);

    void resize(size_t);

    void printInfo() const;

    void fillRand();

    const T &operator[](size_t) const;

    T &operator[](size_t);

    T &getCurValue();

    void moveNext();

    void rewind();

    bool canMoveNext();

private:
    T *storage_;
    size_t size_;
    T *cur_marker_;
};


template<typename T>
const T &ArrSimple<T>::operator[](size_t index) const {
    if (index < size_) {
        return storage_[index];
    } else {
        std::cout << "Invalid index. Returned the first element" << std::endl;
        return storage_[0];
    }
}

template<typename T>
T &ArrSimple<T>::operator[](size_t index) {
    if (index < size_) {
        return storage_[index];
    } else {
        std::cout << "Invalid index. Returned the first element" << std::endl;
        return storage_[0];
    }
}

template<typename T>
void ArrSimple<T>::removeElement(size_t index) {
    if (index < size_) {
        T *new_arr = new T[size_ - 1];
        for (size_t i = 0; i < index; ++i) {
            new_arr[i] = storage_[i];
        }
        for (size_t i = index + 1; i < size_; ++i) {
            new_arr[i - 1] = storage_[i];
        }
        delete[] storage_;
        storage_ = new_arr;
        --size_;
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

template<typename T>
void ArrSimple<T>::addElement(T elem) {
    T *new_arr = new T[size_ + 1];
    for (size_t i = 0; i < size_; ++i) {
        new_arr[i] = storage_[i];
    }
    new_arr[size_] = elem;
    delete[] storage_;
    storage_ = new_arr;
    ++size_;
}

template<typename T>
void ArrSimple<T>::resize(size_t newsize) {
    T *new_arr = new T[newsize];
    if (newsize > size_) {
        for (size_t i = 0; i < newsize; ++i) {
            new_arr[i] = storage_[i];
        }
        delete[] storage_;
        storage_ = new_arr;
    } else {
        for (size_t i = 0; i < newsize; ++i) {
            new_arr[i] = storage_[i];
        }
        delete[] storage_;
        storage_ = new_arr;
    }
    size_ = newsize;
}

template<typename T>
void ArrSimple<T>::printInfo() const {
    std::cout << "Storage: ";
    for (size_t i = 0; i < size_; ++i) {
        std::cout << storage_[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Size: " << size_ << std::endl;
}

template<typename T>
void ArrSimple<T>::fillRand() {
    for (int i = 0; i < size_; ++i) {
        storage_[i] = rand() % 10;
    }
}

template<typename T>
T &ArrSimple<T>::getCurValue() {
    return *cur_marker_;
}

template<typename T>
void ArrSimple<T>::moveNext() {
    ++cur_marker_;
}

template<typename T>
void ArrSimple<T>::rewind() {
    cur_marker_ = storage_;
}

template<typename T>
bool ArrSimple<T>::canMoveNext() {
    if (cur_marker_ + 1 > &storage_[getSize() - 1]) {
        return false;
    } else {
        return true;
    }
}


