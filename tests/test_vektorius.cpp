// C++

#include <gtest/gtest.h>
#include "vektorius.h"

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