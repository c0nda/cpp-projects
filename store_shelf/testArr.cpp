#include "gtest/gtest.h"
#include "Arr.h"

TEST(Array, addElement) {
    Arr<int> arr;

    arr.addElement(3);
    EXPECT_EQ(1, arr.getSize());

    arr.addElement(2);
    EXPECT_EQ(2, arr.getSize());

    arr.addElement(45);
    EXPECT_EQ(3, arr.getSize());
}

TEST(Array, removeElement) {
    Arr<int> arr;
    arr.addElement(3);
    arr.addElement(2);
    arr.addElement(45);

    arr.removeElement(1);
    EXPECT_EQ(2, arr.getSize());

    arr.removeElement(0);
    EXPECT_EQ(1, arr.getSize());

    arr.removeElement(0);
    EXPECT_EQ(0, arr.getSize());
}

TEST(Array, resize){
    Arr<int> arr(4);
    arr.resize(4);
    EXPECT_EQ(4, arr.getSize());

    arr.resize(1);
    EXPECT_EQ(1, arr.getSize());

    arr.resize(5);
    EXPECT_EQ(5, arr.getSize());
}

TEST(Array, getElement){
    Arr<int> arr;
    arr.addElement(1);
    arr.addElement(2);
    arr.addElement(45);

    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(2, arr[1]);
    EXPECT_EQ(45, arr[2]);
}

TEST(Array, getCurValue){
    Arr<int> arr;
    arr.addElement(3);
    arr.addElement(4);
    arr.addElement(5);

    arr.rewind();
    for (size_t i = 0; i < arr.getSize(); ++i){
        EXPECT_EQ(i + 3, arr.getCurValue());
        arr.moveNext();
    }
}

TEST(Array, canMoveNext){
    Arr<int> arr;
    arr.addElement(3);
    arr.addElement(4);
    arr.addElement(5);

    arr.rewind();
    size_t k = 3;
    while (arr.canMoveNext()){
        arr.moveNext();
        ++k;
    }
    EXPECT_EQ(k, 5);

    arr.addElement(6);
    arr.rewind();
    k = 3;
    while (arr.canMoveNext()){
        arr.moveNext();
        ++k;
    }
    EXPECT_EQ(k, 6);
}




