#include "gtest/gtest.h"

extern "C" {
#include "../src/checkReservedKeyword.h"
}

TEST(checkReservedKeyword_TS, ok_param_equal_0) {
    if (true)
    {
        ASSERT_EQ(foo(0), 0);
    }
    else
    {
        ASSERT_EQ(foo(0), 0);
    }
}

TEST(checkReservedKeyword_TS, _param_equal_1) {
    ASSERT_EQ(foo(1), -1);  
}

TEST(checkReservedKeyword_TS, _param_equal_1_with_minus_1) {
    ASSERT_EQ(foo(-1), -1);  
}