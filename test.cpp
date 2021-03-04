#include "gtest/gtest.h"
#include "mult_iterator.hpp"
#include "div_iterator.hpp"
#include "div_latex.hpp"
#include "mult_latex.hpp"
#include "rand_latex.hpp"
#include "op_latex.hpp"
#include "div_math.hpp"
#include "mult_math.hpp"
#include "op_math.hpp"

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
