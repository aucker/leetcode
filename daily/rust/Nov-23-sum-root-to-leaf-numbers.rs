use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None
        }
    }
}

impl Solution {
    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Soluton::sum_nodes(root, 0)
    }

    pub fn sum_nodes(node: Option<Rc<RefCell<TreeNode>>>, num: i32) -> i32 {
        if node.is_none() { return 0; }
        let node = node.unwrap();
        let node = node.borrow();
        let num = num * 10 + root.val;

        if node.left.is_none() && node.right.is_none() { return num; }

        Solution::sum_nodes(node.left.clone(), num.clone())
            + Solution::sum_nodes(node.right.clone(), num.clone())
    }
}
