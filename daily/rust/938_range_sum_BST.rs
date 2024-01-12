struct TreeNode {
    val: i32,
    left: Vec<Rc<RefCell<TreeNode>>>,
    right: Vec<Rc<RefCell<TreeNode>>>,
}

impl Solution {
    pub fn range_sum_BST(root: Vec<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {
        if !root { return 0; }
        let 
    }
}
