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

    Arr(Arr<T> &&arr) {
        size_ = arr.size_;
        storage_ = arr.storage_;
        arr.size_ = 0;
        arr.storage_ = nullptr;
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

    Arr<T> &operator=(Arr<T> &&arr) {
        if (this != &arr) {
            delete[] storage_;
            size_ = arr.size_;
            storage_ = arr.storage_;
            arr.size_ = 0;
            arr.storage_ = nullptr;
        }
        return *this;
    }

    class Marker {
    public:
        Marker(T *pos = nullptr) {
            cur_marker_ = pos;
        }

        T &getCurValue() {
            return *cur_marker_;
        }

        void moveNext() {
            ++cur_marker_;
        }

        void movePrevious() {
            --cur_marker_;
        }

        bool operator!=(const Marker &pos) const { return cur_marker_ != pos.cur_marker_; }

        bool operator==(const Marker &pos) const { return cur_marker_ == pos.cur_marker_; }

        friend class Arr;

    private:
        T *cur_marker_;
    };

    Marker rewind() const { return Marker(storage_); }

    Marker fastForward() const { return Marker(storage_ + size_); }

    Marker find(const T &elem) const;

    void removeElement(const typename Arr<T>::Marker &pos);

    void addElement(T);

    size_t getSize() const { return size_; }

private:
    T *storage_;
    size_t size_;
};

template<typename T>
void Arr<T>::removeElement(const typename Arr<T>::Marker &pos) {
    if (pos == fastForward() ) return;

    T* current = pos.cur_marker_;

    while (current != storage_ + size_ - 1){
        *current = std::move(*(current + 1));
        ++current;
    }
    --size_;
}

template<typename T>
void Arr<T>::addElement(T elem) {
    T *new_arr = new T[size_ + 1];
    for (size_t i = 0; i < size_; ++i) {
        new_arr[i] = std::move(storage_[i]);
    }
    new_arr[size_] = elem;
    delete[] storage_;
    storage_ = new_arr;
    ++size_;
}

template<typename T>
typename Arr<T>::Marker Arr<T>::find(const T &elem) const {
    for (int i = 0; i < size_; ++i) {
        if (storage_[i] == elem) return Marker(storage_ + i);
    }
    return fastForward();
}







