#pragma once

#include <iostream>
#include <cstring>

template<typename T>
class Arr {
public:
    Arr() {
        size_ = 0;
        storage_ = nullptr;
    }

    Arr(int new_size) {
        if (new_size < 1) {
            std::cout << "Invalid size" << std::endl;
        }
        size_ = new_size;
        storage_ = new T[size_];
    }

    Arr(const Arr<T> &arr) {
        size_ = arr.size_;
        storage_ = new T[size_];
        std::memcpy(storage_, arr.storage_, size_);
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
            std::memcpy(storage_, arr.storage_, size_);
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

    Marker<T> getMarker() { return marker_; }

    class Marker {
    public:
        Marker() {
            m_size_ = size_;
            m_storage_ = storage_;
            cur_marker_ = m_storage_;
        }

        template<typename T>
        T &Marker<T>::getCurValue() {
            return *cur_marker_;
        }

        template<typename T>
        void Marker<T>::moveNext() {
            ++cur_marker_;
        }

        template<typename T>
        void Marker<T>::movePrevious() {
            --cur_marker_;
        }

        template<typename T>
        void Marker<T>::rewind() {
            cur_marker_ = m_storage_;
        }

        template<typename T>
        bool Marker<T>::canMoveNext() {
            if (cur_marker_ + 1 > &m_storage_[getSize() - 1]) {
                return false;
            } else {
                return true;
            }
        }

        template<typename T>
        bool Marker<T>::canMovePrev() {
            if (cur_marker_ - 1 < &m_storage_[0]) {
                return false;
            } else {
                return true;
            }
        }

        template<typename T>
        void Marker<T>::fastForward() {
            cur_marker_ = m_storage_ + m_size_ - 1;
        }

        size_t getMsize() { return m_size_; }

    private:
        size_t m_size_;
        T *m_storage_;
        T *cur_marker_;
    }

    friend class Marker;

private:
    T *storage_;
    size_t size_;
    Marker<T> marker_;
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
void Arr<T>::addElement(T elem) {
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
void Arr<T>::resize(size_t newsize) {
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
void Arr<T>::printInfo() const {
    std::cout << "Storage: ";
    for (size_t i = 0; i < size_; ++i) {
        std::cout << storage_[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Size: " << size_ << std::endl;
}

template<typename T>
void Arr<T>::fillRand() {
    for (int i = 0; i < size_; ++i) {
        storage_[i] = rand() % 10;
    }
}





