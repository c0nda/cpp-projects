#pragma once

#include <cstring>

template<typename T>
class List {
    struct Node {
        T data_;
        Node *next_;

        Node(const T &node) {
            data_ = node;
            next_ = nullptr;
        }
    };

    Node *first_;
    size_t size_;
public:
    List() {
        size_ = 0;
        first_ = nullptr;
    }

    List(const List<T> &lst) {
        size_ = lst.size_;
        first_ = nullptr;
        for (auto marker = lst.rewind(); marker != lst.fastForward(); marker.moveNext()) {
            addElement(*marker);
        }
    }

    List(List<T> &&arr) {
        size_ = arr.size_;
        first_ = arr.first_;
        arr.size_ = 0;
        arr.first_ = nullptr;
    }

    List<T> &operator=(const List<T> &lst) {
        if (this != &lst) {
            clear();
            for (auto marker = lst.rewind(); marker != lst.fastForward(); marker.moveNext()) {
                addElement(*marker);
            }
        }
        return *this;
    }

    List<T> &operator=(List<T> &&lst) {
        if (this != &lst) {
            clear();
            size_ = lst.size_;
            first_ = lst.first_;
            lst.size_ = 0;
            lst.first_ = nullptr;
        }
        return *this;
    }

    ~List() {
        clear();
    }

    class Marker {
    public:
        Marker(Node *pos = nullptr) {
            cur_marker_ = pos;
        }

        T &getCurValue() {
            return cur_marker_->data_;
        }

        void moveNext() {
            cur_marker_->next_;
        }

        bool operator!=(const Marker &pos) const { return cur_marker_ != pos.cur_marker_; }

        bool operator==(const Marker &pos) const { return cur_marker_ == pos.cur_marker_; }

        friend class List;

    private:
        Node *cur_marker_;
    };

    Marker rewind() const { return Marker(first_); }

    Marker fastForward() const { return Marker(nullptr); }

    void clear();

    void addElement(const T &elem);

    Marker find(const T &elem) const;

    size_t getSize() const { return size_; }

    void removeElement(const Marker &pos);
};

template<typename T>
void List<T>::clear() {
    Node *tmp;
    while (first_) {
        tmp = first_;
        first_ = first_->next_;
        delete tmp;
    }
    size_ = 0;
}

template<typename T>
void List<T>::addElement(const T &elem) {
    Node *newnode = new Node(elem);
    if (first_ == nullptr) {
        first_ = newnode;
        ++size_;
        return;
    }
    Node *cur = first_;
    while (cur->next_ != nullptr) {
        cur = cur->next_;
    }
    cur->next_ = newnode;
    ++size_;
}

template<typename T>
typename List<T>::Marker List<T>::find(const T &elem) const {
    Node *current = first_;
    while (current){
        if (*current->data_ == elem){
            return Marker(current);
        }
        current = current->next_;
    }
    return fastForward();
}





