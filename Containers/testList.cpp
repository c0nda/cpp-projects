#include "gtest/gtest.h"
#include "List.h"

class testList : public ::testing::Test {
protected:
    void SetUp() {
        for (int i = 0; i < 3; ++i) {
            filled_list.addElement(i);
        }
    }
    List<int> filled_list;
    List<int> empty_list;
};

TEST_F(testList, addElement){
    filled_list.addElement(3);
    EXPECT_EQ(filled_list.getSize(), 4);
    int i = 0;
    for (auto marker = filled_list.rewind(); marker != filled_list.fastForward(); marker.moveNext()){
        EXPECT_EQ(marker.getCurValue(), i);
        ++i;
    }
}

TEST_F(testList, removeElement){
    auto pos = filled_list.find(1);
    filled_list.removeElement(pos);
    EXPECT_EQ(filled_list.getSize(), 2);
    pos = filled_list.find(2);
    filled_list.removeElement(pos);
    EXPECT_EQ(filled_list.getSize(), 1);
    pos = filled_list.find(0);
    filled_list.removeElement(pos);
    EXPECT_EQ(filled_list.getSize(), 0);
}



