#include "gtest/gtest.h"
#include "add_iterator.hpp"
#include "sub_iterator.hpp"
#include "pow_iterator.hpp"
#include "op_iterator.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
