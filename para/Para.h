#pragma once

#include "BinTree.h"

template<typename What, typename To>
class Para {
public:
    Para(const What &seq, const To &code) {
        what_ = seq;
        to_ = code;
    }

    Para(const Para &para) : what_(para.what_), to_(para.to_) {}

    Para &operator=(const Para &para) {
        if (this != para) {
            what_ = para.what_;
            to_ = para.to_;
        }
        return *this;
    }

    const What &getWhat() const { return what_; }

    const To &getTo() const { return to_; }

    bool operator==(const Para &para) const { return what_ == para.what_; }

    bool operator!=(const Para &para) const { return what_ != para.what_; }

    bool operator<(const Para &para) const { return what_ < para.what_; }

private:
    What what_;
    To to_;
};