#include "../../src/dp/25-Apr7.cc"

#include <gtest/gtest.h>

#include <vector>
using namespace std;

TEST(PartitionEqualSubsetSumTest, BasicTest) {
  Solution sol;
  vector<int> nums = {1, 5, 11, 5};
  EXPECT_TRUE(sol.canPartition(nums));
}

TEST(PartitionEqualSubsetSumTest, CannotPartition) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 5};
  EXPECT_FALSE(sol.canPartition(nums));
}

TEST(PartitionEqualSubsetSumTest, EmptyArray) {
  Solution sol;
  vector<int> nums = {};
  EXPECT_TRUE(sol.canPartition(nums));
}

TEST(PartitionEqualSubsetSumTest, SingleElement) {
  Solution sol;
  vector<int> nums = {5};
  EXPECT_FALSE(sol.canPartition(nums));
}

TEST(PartitionEqualSubsetSumTest, AllSameElements) {
  Solution sol;
  vector<int> nums = {2, 2, 2, 2};
  EXPECT_TRUE(sol.canPartition(nums));
}

TEST(PartitionEqualSubsetSumTest, LargeNumbers) {
  Solution sol;
  vector<int> nums = {100, 100, 100, 100, 100, 100, 100, 100};
  EXPECT_TRUE(sol.canPartition(nums));
}

TEST(PartitionEqualSubsetSumTest, MixedNumbers) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_FALSE(sol.canPartition(nums));
}

TEST(PartitionEqualSubsetSumTest, OddSum) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_FALSE(sol.canPartition(nums));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
