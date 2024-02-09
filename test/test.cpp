#include "gtest/gtest.h"
#include "../include/Hailstone.h"
using sequence::satisfiesHailstone;


TEST(HailstoneTests, testNumZero) {
    EXPECT_FALSE(satisfiesHailstone(0));
}

TEST(HailstoneTests, testNumOne) {
    EXPECT_TRUE(satisfiesHailstone(1));
}


