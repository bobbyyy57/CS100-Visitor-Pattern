#include "gtest/gtest.h"
#include "mult_iterator.hpp"
#include "div_iterator.hpp"
#include "op_test.hpp"
//#include "rand_iterator.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
