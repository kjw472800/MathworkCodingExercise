#include "pch.h"
#include "../MathworkCodingExercise/LIFO.h"
#include "../MathworkCodingExercise/Collection.h"

class LIFOTest : public ::testing::Test {
protected:
    void SetUp() override {
        fullStack_.Add(1);
        fullStack_.Add(2);
        fullStack_.Add(3);
        fullStack_.Add(4);
        collection_ptr = &stack_;
    }
    LIFO<int> stack_;
    // Used to test run time polymorphism
    Collection<int>* collection_ptr{ nullptr };
    // Used to test resize
    LIFO<int> fullStack_;
};

TEST_F(LIFOTest, IsEmptyInitially) {
    EXPECT_EQ(stack_.Size(), 0);
    EXPECT_EQ(stack_.IsEmpty(), true);
}

TEST_F(LIFOTest, AddOperationWorks) {
    stack_.Add(0);
    stack_.Add(1);
    EXPECT_EQ(stack_.Size(), 2);
    EXPECT_EQ(stack_.IsEmpty(), false);
    EXPECT_EQ(stack_.Get(), 1);
    EXPECT_EQ(stack_.Get(), 0);
    EXPECT_EQ(stack_.Size(), 0);
    EXPECT_EQ(stack_.IsEmpty(), true);
}


TEST_F(LIFOTest, ResizeWorks) {
    fullStack_.Add(5);
    fullStack_.Add(6);
    EXPECT_EQ(fullStack_.Get(), 6);
    EXPECT_EQ(fullStack_.Get(), 5);
    EXPECT_EQ(fullStack_.Get(), 4);
    EXPECT_EQ(fullStack_.Get(), 3);
    EXPECT_EQ(fullStack_.Get(), 2);
    EXPECT_EQ(fullStack_.Get(), 1);
}

TEST_F(LIFOTest, ThrowEmptyExceptionWhenGetWorks) {
    EXPECT_THROW(stack_.Get(), std::out_of_range);
}

TEST_F(LIFOTest, ThrowExceedCapacityLimitExceptionWhenAddWorks) {
    for (int i = 0; i < 1024; i++) {
        stack_.Add(i);
    }
    EXPECT_THROW(stack_.Add(1025), std::length_error);
}


TEST_F(LIFOTest, PolymorphismWorks) {
    collection_ptr->Add(0);
    collection_ptr->Add(1);
    EXPECT_EQ(collection_ptr->Size(), 2);
    EXPECT_EQ(collection_ptr->IsEmpty(), false);
    EXPECT_EQ(collection_ptr->Get(), 1);
    EXPECT_EQ(collection_ptr->Get(), 0);
    EXPECT_EQ(collection_ptr->Size(), 0);
    EXPECT_EQ(collection_ptr->IsEmpty(), true);
}