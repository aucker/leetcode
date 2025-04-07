pub struct Solution {}

impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        // Input validation
        if nums.is_empty() {
            return true;
        }
        if nums.len() == 1 {
            return false;
        }

        // Calculate total sum and check if it's even
        let total = nums.iter().sum::<i32>() as usize;
        if total % 2 != 0 {
            return false;
        }

        let target = total / 2;
        // let n = nums.len();

        // Early termination if any number is larger than target
        if nums.iter().any(|&x| x as usize > target) {
            return false;
        }

        // Use 1D array for memoization to optimize space
        let mut dp = vec![false; target + 1];
        dp[0] = true; // Base case: sum of 0 is always possible

        for &num in &nums {
            let num = num as usize;
            // Iterate backwards to avoid using the same number multiple times
            for j in (num..=target).rev() {
                if dp[j - num] {
                    dp[j] = true;
                    // Early termination if we find the target
                    if j == target {
                        return true;
                    }
                }
            }
        }

        dp[target]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_empty_input() {
        assert!(Solution::can_partition(vec![]));
    }

    #[test]
    fn test_single_element() {
        assert!(!Solution::can_partition(vec![1]));
    }

    #[test]
    fn test_odd_sum() {
        assert!(!Solution::can_partition(vec![1, 2, 3, 4, 5]));
    }

    #[test]
    fn test_even_sum_possible() {
        assert!(Solution::can_partition(vec![1, 5, 11, 5]));
    }

    #[test]
    fn test_even_sum_impossible() {
        assert!(!Solution::can_partition(vec![1, 2, 3, 5]));
    }

    #[test]
    fn test_large_numbers() {
        assert!(Solution::can_partition(vec![100, 100, 100, 100]));
    }

    #[test]
    fn test_negative_numbers() {
        assert!(!Solution::can_partition(vec![-1, 1, 2, 3]));
    }

    #[test]
    fn test_duplicate_numbers() {
        assert!(Solution::can_partition(vec![2, 2, 2, 2]));
    }

    #[test]
    fn test_large_input() {
        let nums = vec![1; 100];
        assert!(Solution::can_partition(nums));
    }

    #[test]
    fn test_edge_case_zero() {
        assert!(Solution::can_partition(vec![0, 0, 0, 0]));
    }

    #[test]
    fn test_mixed_numbers() {
        assert!(Solution::can_partition(vec![1, 2, 3, 4, 5, 5]));
    }
}
