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
            right: None,
        }
    }
}

impl Solution {
    pub fn tree2str(root: Option<Rc<RefCell<TreeNode>>>) -> String {
        let mut res = String::new();
        Self::dfs(root, &mut res);
        res
    }

    pub fn dfs(node: Option<Rc<RefCell<TreeNode>>>, str: &mut String) {

        if let Some(node) = node {
            let node = node.borrow();
            *str += node.val.to_string().as_str();
            if node.left.is_some() || node.right.is_some() {
                *str += "(";
                Self::dfs(node.left.clone(), str);
                *str += ")";

                if node.right.is_some() {
                    *str += "(";
                    Self::dfs(node.right.clone(), str);
                    *str += ")";
                }
            }
        }
    }
}
