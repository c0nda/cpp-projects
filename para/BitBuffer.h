#pragma once

#include "Arr.h"

class BitBuffer {
public:
    void addBits(unsigned int source, unsigned int num) {
        unsigned int add = 0;
        for (size_t i = 0; i < num; ++i) {
            add = (source << (32 - num + i)) >> 31;
            buffer.addElement(add != 0);
        }
    }

    unsigned char getByte() {
        unsigned char tmp = 0;
        for (size_t i = 0; i < 8 && i < buffer.getSize(); ++i) {
            if (buffer[0]) {
                tmp |= 1 << (7 - i);
            }
            buffer.removeElement(0);
        }
        return tmp;
    }

    bool checkSize() {
        if (buffer.getSize() > 8) {
            return true;
        }
        return false;
    }

private:
    Arr<bool> buffer;
};
