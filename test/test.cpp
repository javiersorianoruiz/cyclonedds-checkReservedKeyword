#include "gtest/gtest.h"

extern "C" {
#include "../src/checkReservedKeyword.h"
}

TEST(checkReservedKeyword_TS, ok_param_equal_0) {
    ASSERT_EQ(foo(0), 0);
}

TEST(checkReservedKeyword_TS, _param_equal_1) {
    ASSERT_EQ(foo(1), -1);  
}