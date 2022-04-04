#include "gtest/gtest.h"
#include "Arr.h"

class testArr : public ::testing::Test {
protected:
    void SetUp() {
        for (int i = 0; i < 3; ++i) {
            arr.addElement(i);
        }
    }

    Arr<int> arr;
};

TEST_F(testArr, addElement) {

    arr.addElement(3);
    EXPECT_EQ(4, arr.getSize());

    arr.addElement(2);
    EXPECT_EQ(5, arr.getSize());

    arr.addElement(45);
    EXPECT_EQ(6, arr.getSize());
}

TEST_F(testArr, removeElement) {
    auto pos = arr.find(45);
    arr.removeElement(pos);
    EXPECT_EQ(3, arr.getSize());

    pos = arr.find(2);
    arr.removeElement(pos);
    EXPECT_EQ(2, arr.getSize());

    pos = arr.find(0);
    arr.removeElement(pos);
    EXPECT_EQ(1, arr.getSize());
}






