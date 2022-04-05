// Definition for a binary tree node.
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

pub struct Solution {}
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn average_of_levels(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<f64> {
        let mut ans: Vec<f64> = Vec::new();
        let mut queue: Vec<Rc<RefCell<TreeNode>>> = Vec::new();
        if let Some(r) = root {
            queue.push(r);
        }
        while !queue.is_empty() {
            let count = queue.len();
            let mut sum: f64 = 0.0;
            let mut tmp: Rc<RefCell<TreeNode>> = Rc::new(RefCell::new(TreeNode::new(0)));
            for i in 0..count {
                tmp = queue[i].clone();
                sum += tmp.borrow().val as f64;
                if let Some(l) = &tmp.borrow().left {
                    queue.push(l.clone());
                }
                if let Some(r) = &tmp.borrow().right {
                    queue.push(r.clone());
                }
            }
            queue.drain(0..count);
            ans.push(sum / count as f64);
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use std::{cell::RefCell, rc::Rc};

    use crate::{Solution, TreeNode};

    #[test]
    fn it_works() {
        // let input = Option(Rc(RefCell(TreeNode(3,9,20,15,7))));
        // let root: Option<Rc<RefCell<TreeNode>>> = [3,9,20,15,7];
        // the test is not available yet!!
        let res = vec![3.00000, 14.50000, 11.00000];
        // let result = 2 + 2;
        // assert_eq!(Solution::average_of_levels(root), res);
    }
}
