#include "gtest/gtest.h"
#include "add_iterator.hpp"
#include "sub_iterator.hpp"
#include "pow_iterator.hpp"
#include "op_iterator.hpp"

#include "sub_latex.hpp"
#include "add_latex.hpp"
#include "pow_latex.hpp"
#include "add_mathml.hpp"
#include "sub_mathml.hpp"
#include "pow_mathml.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
