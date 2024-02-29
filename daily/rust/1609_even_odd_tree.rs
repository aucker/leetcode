use std::{cell::RefCell, rc::Rc};

#[derive(Debug, PartialEq, Eq)]
struct TreeNode {
    val: i32,
    left: Option<Rc<RefCell<TreeNode>>>,
    right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new() {
        TreeNode {
            val: 0,
            left: None,
            right: None,
        }
    }
}

impl Solution {
    pub fn is_even_odd_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut queue = vec![root];
        let mut level = 0;
        while !queue.is_empty() {
            let mut prev = if level % 2 == 0 { i32::MIN } else { i32::MAX };
            let mut next = vec![];
            for node in queue {
                if let Some(node) = node {
                    let node = node.borrow();
                    if level % 2 == 0 {
                        if node.val % 2 == 0 || node.val <= prev {
                            return false;
                        }
                    } else {
                        if node.val % 2 == 1 || node.val >= prev {
                            return false;
                        }
                    }
                    prev = node.val;
                    if let Some(left) = &node.left {
                        next.push(Some(left.clone()));
                    }
                    if let Some(right) = &node.right {
                        next.push(Some(right.clone()));
                    }
                }
            }
            queue = next;
            level += 1;
        }
        true
    }
}
