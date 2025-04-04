use std::{cell::RefCell, rc::Rc};
use rust::util::tree::TreeNode;

// Define Solution struct
pub struct Solution {}

impl Solution {
    pub fn lca_deepest_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut ans = None;
        let mut max_depth = -1; // max global depth

        fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, depth: i32, max_depth: &mut i32, ans: &mut Option<Rc<RefCell<TreeNode>>>) -> i32 {
            if let Some(node) = node {
                let x = node.borrow();
                let left_max_depth = dfs(&x.left, depth + 1, max_depth, ans); // left sub tree
                let right_max_depth = dfs(&x.right, depth + 1, max_depth, ans); // right sub tree
                if left_max_depth == right_max_depth && left_max_depth == *max_depth {
                    *ans = Some(node.clone());
                }
                left_max_depth.max(right_max_depth)
            } else {
                *max_depth = (*max_depth).max(depth); // global max depth
                depth
            }
        }

        dfs(&root, 0, &mut max_depth, &mut ans);
        ans
    }
}

// Add a main function to avoid the "main function not found" error
fn main() {
    // Example usage can be added here
    println!("LCA of Deepest Leaves implementation");
}

#[cfg(test)]
mod tests {
    use super::*;
    use rust::util::tree::{to_tree, TreeNode};

    #[test]
    fn test_lca_deepest_leaves_example1() {
        // Create a tree: [3,5,1,6,2,0,8,null,null,7,4]
        //        3
        //       / \
        //      5   1
        //     / \ / \
        //    6  2 0  8
        //      / \
        //     7   4
        let root = Some(Rc::new(RefCell::new(TreeNode::new(3))));
        let node5 = Rc::new(RefCell::new(TreeNode::new(5)));
        let node1 = Rc::new(RefCell::new(TreeNode::new(1)));
        let node6 = Rc::new(RefCell::new(TreeNode::new(6)));
        let node2 = Rc::new(RefCell::new(TreeNode::new(2)));
        let node0 = Rc::new(RefCell::new(TreeNode::new(0)));
        let node8 = Rc::new(RefCell::new(TreeNode::new(8)));
        let node7 = Rc::new(RefCell::new(TreeNode::new(7)));
        let node4 = Rc::new(RefCell::new(TreeNode::new(4)));

        // Link the nodes
        node2.borrow_mut().left = Some(node7.clone());
        node2.borrow_mut().right = Some(node4.clone());

        node5.borrow_mut().left = Some(node6.clone());
        node5.borrow_mut().right = Some(node2.clone());

        node1.borrow_mut().left = Some(node0.clone());
        node1.borrow_mut().right = Some(node8.clone());

        root.as_ref().unwrap().borrow_mut().left = Some(node5.clone());
        root.as_ref().unwrap().borrow_mut().right = Some(node1.clone());

        // Expected output: node 2, as it's the lowest common ancestor of the deepest nodes (7 and 4)
        let result = Solution::lca_deepest_leaves(root);
        assert!(result.is_some());
        assert_eq!(result.unwrap().borrow().val, 2);
    }

    #[test]
    fn test_lca_deepest_leaves_example2() {
        // Create a tree: [1]
        let root = Some(Rc::new(RefCell::new(TreeNode::new(1))));

        // Expected output: node 1, as it's the only node
        let result = Solution::lca_deepest_leaves(root);
        assert!(result.is_some());
        assert_eq!(result.unwrap().borrow().val, 1);
    }

    #[test]
    fn test_lca_deepest_leaves_example3() {
        // Create a tree: [1,2,3,4,5]
        //        1
        //       / \
        //      2   3
        //     / \
        //    4   5

        // Using the utility function to_tree for easier tree creation
        let vec = vec![Some(1), Some(2), Some(3), Some(4), Some(5)];
        let root = to_tree(vec);

        // Expected output: node 2, as it's the lowest common ancestor of the deepest nodes (4 and 5)
        let result = Solution::lca_deepest_leaves(root);
        assert!(result.is_some());
        assert_eq!(result.unwrap().borrow().val, 2);
    }

    #[test]
    fn test_lca_deepest_leaves_unbalanced() {
        // Create an unbalanced tree: [1,2,null,3,null,4]
        //        1
        //       /
        //      2
        //     /
        //    3
        //   /
        //  4
        let root = Some(Rc::new(RefCell::new(TreeNode::new(1))));
        let node2 = Rc::new(RefCell::new(TreeNode::new(2)));
        let node3 = Rc::new(RefCell::new(TreeNode::new(3)));
        let node4 = Rc::new(RefCell::new(TreeNode::new(4)));

        node3.borrow_mut().left = Some(node4.clone());
        node2.borrow_mut().left = Some(node3.clone());
        root.as_ref().unwrap().borrow_mut().left = Some(node2.clone());

        // Expected output: node 4, as it's the deepest node
        let result = Solution::lca_deepest_leaves(root);
        assert!(result.is_some());
        assert_eq!(result.unwrap().borrow().val, 4);
    }
}
