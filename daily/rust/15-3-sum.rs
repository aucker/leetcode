fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut nums = nums;
    nums.sort();
    let mut res = vec![];
    for i in 0..nums.len() {
        if i > 0 && nums[i] == nums[i - 1] {
            continue;
        }
        let (mut l, mut r) = (i + 1, nums.len() - 1);
        while l < r {
            let sum = nums[i] + nums[l] + nums[r];
            if sum < 0 {
                l += 1;
            } else if sum > 0 {
                r -= 1;
            } else {
                res.push(vec![nums[i], nums[l], nums[r]]);
                while l < r && nums[l] == nums[l + 1] {
                    l += 1;
                }
                while l < r && nums[r] == nums[r - 1] {
                    r -= 1;
                }
                l += 1;
                r -= 1;
            }
        }
    }
    res
}

#[test]
fn test1() {
    let nums = vec![-1, 0, 1, 2, -1, -4];
    let res = three_sum(nums);
    assert_eq!(res, vec![vec![-1, -1, 2], vec![-1, 0, 1]]);
}

#[test]
fn test2() {
    let nums = vec![];
    let res: Vec<Vec<i32>> = three_sum(nums);
    assert_eq!(res, vec![]);
}