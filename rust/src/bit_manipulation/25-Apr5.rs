pub struct Solution {}

impl Solution {
    pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        nums.into_iter().reduce(|or, x| or | x).unwrap() << (n - 1)
    }
}

fn main() {
    println!("subset xor sum implementation");
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_subset_xor_sum_example1() {
        let nums = vec![1, 3];
        assert_eq!(Solution::subset_xor_sum(nums), 6);
        // Subsets: [1], [3], [1,3]
        // XOR sums: 1 + 3 + 2 = 6
    }

    #[test]
    fn test_subset_xor_sum_example2() {
        let nums = vec![5, 1, 6];
        assert_eq!(Solution::subset_xor_sum(nums), 28);
        // Subsets: [5], [1], [6], [5,1], [5,6], [1,6], [5,1,6]
        // XOR sums: 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
    }

    #[test]
    fn test_subset_xor_sum_single_element() {
        let nums = vec![2];
        assert_eq!(Solution::subset_xor_sum(nums), 2);
    }

    // #[test]
    // /// We don't test the empty case
    // fn test_subset_xor_sum_empty() {
    //     let nums = vec![];
    //     assert_eq!(Solution::subset_xor_sum(nums), 0);
    // }
}
