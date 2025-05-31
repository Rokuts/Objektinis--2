// C++

#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include "studentas.h"

TEST(StudentasTest, DefaultConstructor) {
    Studentas s;
    EXPECT_EQ(s.getVardas(), "");
    EXPECT_EQ(s.getPavarde(), "");
    EXPECT_EQ(s.getEgzas(), 0);
    EXPECT_TRUE(s.getNamuDarbai().empty());
}

TEST(StudentasTest, ParameterizedConstructor) {
    std::vector<int> nd = {8, 9, 10};
    Studentas s("Jonas", "Jonaitis", 7, nd);
    EXPECT_EQ(s.getEgzas(), 7);
    EXPECT_EQ(s.getNamuDarbai(), nd);
}

TEST(StudentasTest, CopyConstructor) {
    std::vector<int> nd = {5, 6};
    Studentas s1("A", "B", 9, nd);
    Studentas s2(s1);
    EXPECT_EQ(s2.getEgzas(), 9);
    EXPECT_EQ(s2.getNamuDarbai(), nd);
}

TEST(StudentasTest, MoveConstructor) {
    std::vector<int> nd = {4, 5};
    Studentas s1("C", "D", 8, nd);
    Studentas s2(std::move(s1));
    EXPECT_EQ(s2.getEgzas(), 8);
    EXPECT_EQ(s2.getNamuDarbai(), nd);
}

TEST(StudentasTest, CopyAssignment) {
    Studentas s1("E", "F", 6, {1,2});
    Studentas s2;
    s2 = s1;
    EXPECT_EQ(s2.getEgzas(), 6);
    EXPECT_EQ(s2.getNamuDarbai(), std::vector<int>({1,2}));
}

TEST(StudentasTest, MoveAssignment) {
    Studentas s1("G", "H", 10, {3,4});
    Studentas s2;
    s2 = std::move(s1);
    EXPECT_EQ(s2.getEgzas(), 10);
    EXPECT_EQ(s2.getNamuDarbai(), std::vector<int>({3,4}));
}

TEST(StudentasTest, VidurkisWithHomework) {
    Studentas s("I", "J", 10, {8, 9, 10});
    // (8+9+10)/3 = 9, 9*0.4 + 10*0.6 = 9.6
    EXPECT_DOUBLE_EQ(s.vidurkis(), 9.6);
}

TEST(StudentasTest, VidurkisNoHomework) {
    Studentas s("K", "L", 7, {});
    // Only exam: 7*0.6
    EXPECT_DOUBLE_EQ(s.vidurkis(), 4.2);
}

TEST(StudentasTest, MedianaOdd) {
    Studentas s("M", "N", 8, {5, 7, 9});
    // Sorted: 5,7,9 -> mediana=7, 7*0.4+8*0.6=7.6
    EXPECT_DOUBLE_EQ(s.mediana(), 7.6);
}

TEST(StudentasTest, MedianaEven) {
    Studentas s("O", "P", 6, {4, 8, 10, 12});
    // Sorted: 4,8,10,12 -> (8+10)/2=9, 9*0.4+6*0.6=7.2
    EXPECT_DOUBLE_EQ(s.mediana(), 7.2);
}

TEST(StudentasTest, MedianaNoHomework) {
    Studentas s("Q", "R", 5, {});
    EXPECT_DOUBLE_EQ(s.mediana(), 3.0);
}

TEST(StudentasTest, InputOperator) {
    std::istringstream iss("Vardas Pavarde 7 8 9 10");
    Studentas s;
    iss >> s;
    EXPECT_EQ(s.getEgzas(), 10);
    EXPECT_EQ(s.getNamuDarbai(), std::vector<int>({7,8,9}));
}

TEST(StudentasTest, OutputOperator) {
    Studentas s("Vardas", "Pavarde", 6, {1,2,3});
    std::ostringstream oss;
    oss << s;
    EXPECT_EQ(oss.str(), "Vardas Pavarde 1 2 3 6");
}