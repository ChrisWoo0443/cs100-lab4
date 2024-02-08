#include "gtest/gtest.h"
#include "../include/Triangle.h"
using shapes::Triangle;

// 4 Failures (added 1)
TEST(TriangleTests, testPerimeterDifferentNumbers){
    Triangle *aTriangle = new Triangle(5, 4, 3);
    EXPECT_EQ (aTriangle->getPerimeter(),12);
}

TEST(TriangleTests, testAreaEquilateral) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_DOUBLE_EQ (aTriangle->getArea(),4.5);
}

TEST(TriangleTests, testGetKindEquilateral) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::EQUILATERAL);
}

// 1 Expect Death (Success)
TEST(TriangleTests, testFirstSideNotLongest) {
    EXPECT_DEATH (Triangle *aTriangle = new Triangle(4,10,10);,"First side is not the longest");
}

// 4 Additional Passes

// Already here, renamed but passed
TEST(TriangleTests, testPerimeterEquilateral) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

TEST(TriangleTests, testPerimeterIsosceles) {
    Triangle *aTriangle = new Triangle(4,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),10);
}

TEST(TriangleTests, testFirstSideLongerThanOthersCombined) {
    EXPECT_DEATH (Triangle *aTriangle = new Triangle(10,4,2);,"Does not satisfy triangle inequality");
}

TEST(TriangleTests, testGetKindIsosceles) {
    Triangle *aTriangle = new Triangle(4,3,3);
    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::ISOSCELES);
}

TEST(TriangleTests, testGetKindScalene) {
    Triangle *aTriangle = new Triangle(4,3,2);
    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::SCALENE);
}


