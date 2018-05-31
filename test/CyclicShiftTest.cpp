#include "../src/kmp.h"
#include <gtest/gtest.h>
#include <iostream>

typedef
struct testState {
  std::string checkingString;
  std::string sourceString;
  int result;

  friend std::ostream& operator<<(std::ostream& os, const testState& obj) {

    os << "[Checking string(A): " << obj.checkingString << " | ";
    os << "Source(B): " << obj.sourceString << " | ";
    os << "Result: " << obj.result;

    os << "]" <<std::endl;

    return os;
  }
}testState;


struct CyclicShiftTest : testing::Test, testing::WithParamInterface<testState> {
    void SetUp() {
      std::cout << GetParam();
    }
};

TEST_P(CyclicShiftTest, CycleShiftcheck) {
  auto state = GetParam();
  ASSERT_EQ(state.result, CyclicShift(state.sourceString, state.checkingString));
}


INSTANTIATE_TEST_CASE_P(Default, CyclicShiftTest,
  testing::Values(
  testState{"defabc", "abcdef", 3},
  testState{"m", "mmmm", -1},
  testState{"kkk", "k", -1},
  testState{"bcabca","abcabc", 1},
  testState{"a12345kdcskbdcasd","12345kdcskbdcasda" , 16}
  ));

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
