#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "../../src/dp/25-Apr6.cc"  // Include the solution file
using namespace std;

// Test cases
TEST(LargestDivisibleSubsetTest, BasicTest) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> expected = {1, 2, 4, 8};
  vector<int> result = sol.largestDivisibleSubset(nums);
  sort(result.begin(), result.end());
  sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
}

TEST(LargestDivisibleSubsetTest, SingleElement) {
  Solution sol;
  vector<int> nums = {5};
  vector<int> expected = {5};
  vector<int> result = sol.largestDivisibleSubset(nums);
  EXPECT_EQ(result, expected);
}

TEST(LargestDivisibleSubsetTest, AllPrimes) {
  Solution sol;
  vector<int> nums = {2, 3, 5, 7, 11, 13};
  vector<int> expected = {2};  // Any single prime number is a valid subset
  vector<int> result = sol.largestDivisibleSubset(nums);
  EXPECT_EQ(result.size(), 1);
  EXPECT_TRUE(find(nums.begin(), nums.end(), result[0]) != nums.end());
}

TEST(LargestDivisibleSubsetTest, LargeNumbers) {
  Solution sol;
  vector<int> nums = {1, 2, 4, 8, 16, 32, 64, 128};
  vector<int> expected = {1, 2, 4, 8, 16, 32, 64, 128};
  vector<int> result = sol.largestDivisibleSubset(nums);
  sort(result.begin(), result.end());
  sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
}

TEST(LargestDivisibleSubsetTest, DuplicateNumbers) {
  Solution sol;
  vector<int> nums = {1, 1, 1, 2, 2, 2, 4, 4, 4};
  vector<int> expected = {1, 1, 1, 2, 2, 2, 4, 4, 4};
  vector<int> result = sol.largestDivisibleSubset(nums);
  sort(result.begin(), result.end());
  sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
