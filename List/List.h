#pragma once

#include <cstring>

class Node;

template<typename T>
class List {
public:
    List() {
        size_ = 0;
        first_ = nullptr;
    }

    List(const List<T> &lst) {
        size_ = lst.size_;
        first_ = new T;
        std::memcpy(first_, lst.first_, 1);
        while (lst.first_->next_ != nullptr) {
            addElement(lst.first_->next_);
            first_ = first_->next_;
        }
    }

    List(List<T> &&) {}

    void operator=(const List<T> &lst) {
        if (this != &lst) {
            delete first_;
            size_ = lst.size_;
            first_ = new T;
            std::memcpy(first_, lst.first_, 1);
            while (lst.first_->next_ != nullptr) {
                addElement(lst.first_->next_);
                first_ = first_->next_;
            }
        }
        return *this;
    };

    ~List() {
        if (first_ == nullptr) return;
        do {
            Node *cur = first_->next_;
            delete first_;
            first_ = cur;
        } while (first_ != nullptr);
    };

    size_t getSize() const { return size_; }

//    void removeElement(const Marker& );

    void addElement(T newElem) {
        Node *newnode = new Node(newElem);
        if (first_ == nullptr) {
            first_ = newnode;
            ++size_;
            std::cout << first_->data_;
            return;
        }
        Node *cur = first_;
        while (cur->next_ != nullptr) {
            cur = cur->next_;
        }
        cur->next_ = newnode;
        ++size_;
    }

    class ListMarker {
    public:
        ListMarker(){
            cur_ = nullptr;
        }

        ListMarker(Node *p){
            cur_ = p;
        }

        T &getCurValue() {
            return List::Node::cur_->next_;
        }

        void moveNext() {
            cur_ = List::Node::cur_->next_;
        }

        bool canMoveNext() {
            return (List::Node::cur_->next_ != nullptr);
        }

    private:
        Node *cur_;
    };

    ListMarker getMarker();

private:
    struct Node {
        T data_;
        Node *next_;

        Node(const T &d) {
            data_ = d;
            next_ = nullptr;
        }
    };

    Node *first_;
    size_t size_;
};


