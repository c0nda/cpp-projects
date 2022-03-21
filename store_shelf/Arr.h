#pragma once

#include <iostream>
#include "StandardFunctions.h"

template<typename T>
class Arr {
public:
    Arr() {
        size_ = 0;
        storage_ = nullptr;
        cur_marker_ = nullptr;
    }

    Arr(int new_size) {
        if (new_size < 1) {
            std::cout << "Invalid size" << std::endl;
        }
        size_ = new_size;
        storage_ = new T[size_];
        cur_marker_ = storage_;
    }

    Arr(const Arr<T> &arr) {
        size_ = arr.size_;
        storage_ = new T[size_];
        cpymem(storage_, arr.storage_, size_);
        cur_marker_ = storage_;
    }

    ~Arr() {
        if (storage_ != nullptr) {
            delete[] storage_;
        }
    }

    Arr<T> &operator=(const Arr<T> &arr) {
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

    void printInfo();

    void fillRand();

    const T &operator[](size_t) const;

    T &operator[](size_t);

    T &getCurValue();

    void moveNext();

    void movePrevious();

    void rewind();

    bool canMoveNext();

private:
    T *storage_;
    size_t size_;
    T *cur_marker_;
};


template<typename T>
const T &Arr<T>::operator[](size_t index) const {
    if (index < size_) {
        return storage_[index];
    } else {
        std::cout << "Invalid index. Returned the first element" << std::endl;
        return storage_[0];
    }
}

template<typename T>
T &Arr<T>::operator[](size_t index) {
    if (index < size_) {
        return storage_[index];
    } else {
        std::cout << "Invalid index. Returned the first element" << std::endl;
        return storage_[0];
    }
}

template<typename T>
void Arr<T>::removeElement(size_t index) {
    if (index < size_) {
        rewind();
        T *new_arr = new T[size_ - 1];
        if (index > 1) {
            for (size_t i = 0; i < index && canMoveNext(); ++i) {
                new_arr[i] = getCurValue();
                moveNext();
            }
            movePrevious();
        }
        for (size_t i = index; i < size_; ++i) {
            if (canMoveNext()) {
                moveNext();
            } else {
                break;
            }
            new_arr[i] = getCurValue();
        }
        rewind();
        delete[] storage_;
        storage_ = new_arr;
        --size_;
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

template<typename T>
void Arr<T>::addElement(T elem) {
    rewind();
    T *new_arr = new T[size_ + 1];
    for (size_t i = 0; i < size_; ++i) {
        new_arr[i] = getCurValue();
        if (canMoveNext()) {
            moveNext();
        } else {
            break;
        }
    }
    rewind();
    new_arr[size_] = elem;
    delete[] storage_;
    storage_ = new_arr;
    ++size_;
}

template<typename T>
void Arr<T>::resize(size_t newsize) {
    rewind();
    T *new_arr = new T[newsize];
    if (newsize > size_) {
        for (size_t i = 0; i < newsize; ++i) {
            new_arr[i] = getCurValue();
            if (canMoveNext()) {
                moveNext();
            } else {
                break;
            }
        }
        rewind();
        delete[] storage_;
        storage_ = new_arr;
    } else {
        for (size_t i = 0; i < newsize; ++i) {
            new_arr[i] = getCurValue();
            if (canMoveNext()) {
                moveNext();
            } else {
                break;
            }
        }
        rewind();
        delete[] storage_;
        storage_ = new_arr;
    }
    size_ = newsize;
}

template<typename T>
void Arr<T>::printInfo() {
    rewind();
    if (cur_marker_) {
        std::cout << "Storage: ";
        while (true) {
            std::cout << getCurValue() << " ";
            if (!canMoveNext()) break;
            moveNext();
        }
        std::cout << std::endl;
        std::cout << "Size: " << size_ << std::endl;
    } else {
        std::cout << "Nullptr error" << std::endl;
    }
}

template<typename T>
void Arr<T>::fillRand() {
    rewind();
    if (cur_marker_) {
        while (true) {
            getCurValue() = rand() % 10;
            if (!canMoveNext()) break;
            moveNext();
        }
    } else {
        std::cout << "Nullptr error" << std::endl;
    }
}

template<typename T>
T &Arr<T>::getCurValue() {
    return *cur_marker_;
}

template<typename T>
void Arr<T>::moveNext() {
    ++cur_marker_;
}

template<typename T>
void Arr<T>::movePrevious() {
    --cur_marker_;
}

template<typename T>
void Arr<T>::rewind() {
    cur_marker_ = storage_;
}

template<typename T>
bool Arr<T>::canMoveNext() {
    if (cur_marker_ + 1 > &storage_[getSize() - 1]) {
        return false;
    } else {
        return true;
    }
}



