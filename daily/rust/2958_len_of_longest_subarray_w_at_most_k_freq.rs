use std::collections::HashMap;
impl Solution {
	pub fn max_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
		let (mut le, mut ri) = (0, 0);
		let mut ans = 0;
		let n = nums.len();
		let mut seen: HashMap<i32, i32> = HashMap::new();

		while ri < n {
			let mut curr = nums[ri];
			*seen.entry(curr).or_insert(0) += 1;
			ri += 1;

			while le < ri && *seen.get(&curr).unwrap_or(&0) > k {
				// *seen.get_mut(&nums[le]).unwrap() -= 1;
				if let Some(count) = seen.get_mut(&nums[le]) {
					*count -= 1;
				}
				le += 1;
			}
			// ans = std::cmp::max(ans, ri - le);
			ans = ans.max(ri - le);
		}
		ans as i32
	}
}

#[cfg(test)]
#[test]
fn test_1() {
	assert_eq!(max_subarray_length(vec![1, 2, 3, 1, 2, 3], 2), 6);
  assert_eq!(max_subarray_length(vec![1, 2, 3, 2, 1, 4], 3), 3);
}

#[test]
fn test_edge() {
	assert_eq!(max_subarray_length(vec![], 0), 0);  // empty
	assert_eq!(max_subarray_length(vec![1,2,3],4), 0);  // No subarray w/ freq > k
	assert_eq!(max_subarray_length(vec![1,2,3,1,2,3], 1), 3);  // Max freq = k
}