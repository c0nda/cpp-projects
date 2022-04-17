#pragma once

template<typename T>
class BinTree {
private:
    struct Node {
        Node *left_, *right_, *parent_;
        T data_;

        Node(const T &elem) : right_(nullptr), left_(nullptr),
                              parent_(nullptr), data_(elem) {}

        ~Node() {
            if (left_) delete left_;
            if (right_) delete right_;
            left_ = nullptr;
            right_ = nullptr;
            parent_ = nullptr;
        }

        Node *minimum() {
            Node *current = this;
            while (current->left_) current = current->left_;
            return current;
        }

        Node *maximum() {
            Node *current = this;
            while (current->right_) current = current->right_;
            return current;
        }

        Node *next() {
            if (right_) return right_->minimum();
            Node *tmp = parent_, *current = this;
            while (tmp) {
                if (current == tmp->left_) break;
                current = tmp;
                tmp = tmp->parent_;
            }
            return tmp;
        }

        Node *prev() {
            if (left_) return left_->maximum();
            Node *tmp = parent_, *current = this;
            while (tmp) {
                if (current == tmp->right_) break;
                current = tmp;
                tmp = tmp->parent_;
            }
            return tmp;
        }
    };

    Node *root_;

    unsigned int size_;
public:
    BinTree() {
        size_ = 0;
        root_ = nullptr;
    }

    ~BinTree() {
        if (root_) delete root_;
        root_ = nullptr;
    }

    unsigned int getSize() const { return size_; }

    class Marker {
    public:
        Marker(Node *pos = nullptr) {
            cur_marker_ = pos;
        }

        T &getCurValue() const {
            return cur_marker_->data_;
        }

        void moveNext() {
            if (cur_marker_) {
                cur_marker_ = cur_marker_->next();
            }
        }

        bool operator!=(const Marker &pos) const { return cur_marker_ != pos.cur_marker_; }

        bool operator==(const Marker &pos) const { return cur_marker_ == pos.cur_marker_; }

        friend class BinTree;

    private:
        Node *cur_marker_;
    };

    Marker rewind() const {
        if (root_) {
            return Marker(root_->minimum());
        }
        return Marker(nullptr);
    }

    Marker fastForward() const { return Marker(nullptr); }

    void add(const T &elem) {
        ++size_;
        if (root_ == nullptr) {
            root_ = new Node(elem);
            return;
        }
        Node *now = root_, *tmp;
        bool toLeft;
        do {
            tmp = now;
            if (elem < now->data_) {
                now = now->left_;
                toLeft = true;
            } else {
                now = now->right_;
                toLeft = false;
            }
        } while (now);
        now = new Node(elem);
        if (toLeft) {
            tmp->left_ = now;
        } else {
            tmp->right_ = now;
        }
        now->parent_ = tmp;
    }

    Node *find(const T &elem) const {
        Node *cur = root_;
        while (cur != nullptr) {
            if (cur->data_ == elem) return cur;
            if (cur->data_ < elem) {
                cur = cur->right_;
            } else {
                cur = cur->left_;
            }
        }
        return cur;
    }
};