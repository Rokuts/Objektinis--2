// C++
#include <gtest/gtest.h>
#include "vektorius.h"

// Esami testai
TEST(VektoriusClearTest, ClearOnEmptyVector) {
    Vektorius<int> v;
    v.clear();
    EXPECT_EQ(v.size(), 0u);
    EXPECT_EQ(v.capacity(), 0u);
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.begin(), nullptr);
    EXPECT_EQ(v.end(), nullptr);
}

TEST(VektoriusClearTest, ClearOnNonEmptyVector) {
    Vektorius<int> v;
    for (int i = 0; i < 5; ++i) v.push_back(i);
    EXPECT_EQ(v.size(), 5u);
    EXPECT_GE(v.capacity(), 5u);
    EXPECT_FALSE(v.empty());
    v.clear();
    EXPECT_EQ(v.size(), 0u);
    EXPECT_EQ(v.capacity(), 0u);
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.begin(), nullptr);
    EXPECT_EQ(v.end(), nullptr);
}

// Papildomi testai

TEST(VektoriusFunctionalityTest, PushBackAndIndexOperator) {
    Vektorius<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i * 2);
    ASSERT_EQ(v.size(), 10u);
    for (size_t i = 0; i < v.size(); ++i) {
        EXPECT_EQ(v[i], static_cast<int>(i * 2));
    }
}

TEST(VektoriusFunctionalityTest, CopyConstructor) {
    Vektorius<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    Vektorius<int> v2 = v1;
    EXPECT_EQ(v2.size(), v1.size());
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    v1[0] = 99;
    EXPECT_EQ(v2[0], 1); // turi būti deep copy
}

TEST(VektoriusFunctionalityTest, MoveConstructor) {
    Vektorius<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    Vektorius<int> v2 = std::move(v1);
    EXPECT_EQ(v2.size(), 2u);
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v1.size(), 0u);
}

TEST(VektoriusFunctionalityTest, AssignmentOperator) {
    Vektorius<int> v1(3, 7);
    Vektorius<int> v2;
    v2 = v1;
    EXPECT_EQ(v2.size(), 3u);
    EXPECT_EQ(v2[0], 7);
    v1[0] = 99;
    EXPECT_EQ(v2[0], 7); // deep copy
}

TEST(VektoriusFunctionalityTest, AtThrows) {
    Vektorius<int> v;
    v.push_back(1);
    EXPECT_NO_THROW(v.at(0));
    EXPECT_THROW(v.at(1), std::out_of_range);
}

TEST(VektoriusFunctionalityTest, PopBack) {
    Vektorius<int> v;
    v.push_back(10);
    v.push_back(20);
    v.pop_back();
    EXPECT_EQ(v.size(), 1u);
    EXPECT_EQ(v[0], 10);
    v.pop_back();
    EXPECT_EQ(v.size(), 0u);
    EXPECT_THROW(v.pop_back(), std::out_of_range);
}

TEST(VektoriusFunctionalityTest, BeginEndIteration) {
    Vektorius<int> v;
    for (int i = 0; i < 5; ++i) v.push_back(i * 3);
    int sum = 0;
    for (auto it = v.begin(); it != v.end(); ++it) sum += *it;
    EXPECT_EQ(sum, 30); // 0+3+6+9+12
}

TEST(VektoriusFunctionalityTest, ClearAndReuse) {
    Vektorius<int> v(5, 1);
    v.clear();
    EXPECT_EQ(v.size(), 0u);
    v.push_back(42);
    EXPECT_EQ(v.size(), 1u);
    EXPECT_EQ(v[0], 42);
}

TEST(VektoriusFunctionalityTest, Empty) {
    Vektorius<int> v;
    EXPECT_TRUE(v.empty());
    v.push_back(1);
    EXPECT_FALSE(v.empty());
    v.clear();
    EXPECT_TRUE(v.empty());
}

TEST(VektoriusFunctionalityTest, CapacityGrowth) {
    Vektorius<int> v;
    size_t prev_capacity = v.capacity();
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
        EXPECT_GE(v.capacity(), v.size());
        EXPECT_TRUE(v.capacity() >= prev_capacity);
        prev_capacity = v.capacity();
    }
}

TEST(VektoriusFunctionalityTest, SelfAssignment) {
    Vektorius<int> v(3, 9);
    v = v;
    EXPECT_EQ(v.size(), 3u);
    EXPECT_EQ(v[0], 9);
}

struct Dummy {
    int x;
    Dummy(int x = 0) : x(x) {}
    bool operator==(const Dummy& other) const { return x == other.x; }
};

TEST(VektoriusFunctionalityTest, CustomType) {
    Vektorius<Dummy> v;
    v.push_back(Dummy(1));
    v.push_back(Dummy(2));
    EXPECT_EQ(v.size(), 2u);
    EXPECT_EQ(v[0], Dummy(1));
    EXPECT_EQ(v[1], Dummy(2));
}

TEST(VektoriusClearTest, PushBackAfterClear) {
    Vektorius<int> v;
    for (int i = 0; i < 3; ++i) v.push_back(i);
    v.clear();
    v.push_back(42);
    EXPECT_EQ(v.size(), 1u);
    EXPECT_EQ(v[0], 42);
    EXPECT_FALSE(v.empty());
}

TEST(VektoriusClearTest, AccessAfterClearThrows) {
    Vektorius<int> v;
    v.push_back(1);
    v.clear();
    EXPECT_THROW(v.at(0), std::out_of_range);
    // operator[] is undefined, but let's check for crash
    // (cannot check throw, but can check not to crash)
    // Do not access v[0] if begin()==nullptr
    if (v.begin() != nullptr)
        (void)v[0];
}

TEST(VektoriusClearTest, MultipleClearCalls) {
    Vektorius<int> v;
    for (int i = 0; i < 2; ++i) v.push_back(i);
    v.clear();
    v.clear();
    EXPECT_EQ(v.size(), 0u);
    EXPECT_EQ(v.capacity(), 0u);
    EXPECT_TRUE(v.empty());
    v.push_back(7);
    v.clear();
    EXPECT_EQ(v.size(), 0u);
    EXPECT_EQ(v.capacity(), 0u);
    EXPECT_TRUE(v.empty());
}