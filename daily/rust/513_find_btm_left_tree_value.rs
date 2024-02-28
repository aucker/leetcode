use std::{cell::RefCell, collections::VecDeque, rc::Rc};

// Definition of TreeNode
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    val: i32,
    left: Option<Rc<RefCell<TreeNode>>>,
    right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

impl Solution {
    pub fn find_bottom_left_value(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut queue = VecDeque::new();
        queue.push_back(root.unwrap());
        let mut result = 0;
        while !queue.is_empty() {
            let len = queue.len();
            for i in 0..len {
                let node = queue.pop_front().unwrap();
                if i == 0 {
                    result = node.borrow().val;
                }
                if let Some(left) = &node.borrow().left {
                    queue.push_back(left.clone());
                }
                if let Some(right) = &node.borrow().right {
                    queue.push_back(right.clone());
                }
            }
        }
        result
    }
}