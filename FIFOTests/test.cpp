#include "pch.h"
#include "../MathworkCodingExercise/FIFO.h"
#include "../MathworkCodingExercise/Collection.h"

class FIFOTest : public ::testing::Test {
protected:
    void SetUp() override {
        fullQueue_.Add(1);
        fullQueue_.Add(2);
        fullQueue_.Add(3);
        fullQueue_.Add(4);
        collection_ptr = &fullQueue_;
    }
    FIFO<int> queue_;
    // Used to test run time polymorphism
    Collection<int>* collection_ptr{nullptr};
    // Used to test resize and circular buffer work
    FIFO<int> fullQueue_;
};

TEST_F(FIFOTest, IsEmptyInitially) {
    EXPECT_EQ(queue_.Size(), 0);
    EXPECT_EQ(queue_.IsEmpty(), true);
}

TEST_F(FIFOTest, AddOperationWorks) {
    queue_.Add(1);
    queue_.Add(2);
    EXPECT_EQ(queue_.Size(), 2);
    EXPECT_EQ(queue_.IsEmpty(), false);
    EXPECT_EQ(queue_.Get(), 1);
    EXPECT_EQ(queue_.Get(), 2);
    EXPECT_EQ(queue_.Size(), 0);
    EXPECT_EQ(queue_.IsEmpty(), true);
}


TEST_F(FIFOTest, CircularBufferWorks) {
    EXPECT_EQ(fullQueue_.Get(), 1);
    EXPECT_EQ(fullQueue_.Get(), 2);
    fullQueue_.Add(5);
    fullQueue_.Add(6);
    EXPECT_EQ(fullQueue_.Get(), 3);
    EXPECT_EQ(fullQueue_.Get(), 4);
    fullQueue_.Add(7);
    fullQueue_.Add(8);
    EXPECT_EQ(fullQueue_.Get(), 5);
    EXPECT_EQ(fullQueue_.Get(), 6);
    EXPECT_EQ(fullQueue_.Get(), 7);
    EXPECT_EQ(fullQueue_.Get(), 8);
}

TEST_F(FIFOTest, ResizeWorks) {
    fullQueue_.Add(5);
    fullQueue_.Add(6);
    EXPECT_EQ(fullQueue_.Get(), 1);
    EXPECT_EQ(fullQueue_.Get(), 2);
    EXPECT_EQ(fullQueue_.Get(), 3);
    EXPECT_EQ(fullQueue_.Get(), 4);
    EXPECT_EQ(fullQueue_.Get(), 5);
    EXPECT_EQ(fullQueue_.Get(), 6);
}

TEST_F(FIFOTest, ResizeAndCircularBufferWorks) {
    EXPECT_EQ(fullQueue_.Get(), 1);
    EXPECT_EQ(fullQueue_.Get(), 2);
    fullQueue_.Add(5);
    fullQueue_.Add(6);
    fullQueue_.Add(7);
    EXPECT_EQ(fullQueue_.Size(), 5);
    EXPECT_EQ(fullQueue_.Get(), 3);
    EXPECT_EQ(fullQueue_.Get(), 4);
    EXPECT_EQ(fullQueue_.Get(), 5);
    EXPECT_EQ(fullQueue_.Get(), 6);
    EXPECT_EQ(fullQueue_.Get(), 7);
    EXPECT_EQ(fullQueue_.IsEmpty(), true);
}

TEST_F(FIFOTest, ThrowEmptyExceptionWhenGetWorks) {
    EXPECT_THROW(queue_.Get(), std::out_of_range);
}

TEST_F(FIFOTest, ThrowExceedCapacityLimitExceptionWhenAddWorks) {
    for (int i = 0; i < 1024; i++) {
        queue_.Add(i);
    }
    EXPECT_THROW(queue_.Add(1025), std::length_error);
}


TEST_F(FIFOTest, PolymorphismWorks) {
    EXPECT_EQ(collection_ptr->Get(), 1);
    EXPECT_EQ(collection_ptr->Get(), 2);
    collection_ptr->Add(5);
    collection_ptr->Add(6);
    collection_ptr->Add(7);
    EXPECT_EQ(collection_ptr->Size(), 5);
    EXPECT_EQ(collection_ptr->Get(), 3);
    EXPECT_EQ(collection_ptr->Get(), 4);
    EXPECT_EQ(collection_ptr->Get(), 5);
    EXPECT_EQ(collection_ptr->Get(), 6);
    EXPECT_EQ(collection_ptr->Get(), 7);
    EXPECT_EQ(collection_ptr->IsEmpty(), true);
}