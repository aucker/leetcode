#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val,
        }
    }
}

impl Solution {
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        // let mut dummy = Some(Box::new(ListNode::new(0)));
        // let mut p = &mut dummy;
        // let mut head = head;
        // while let Some(mut node) = head {
        //     if let Some(mut next) = node.next.take() {
        //         node.next = next.next.take();
        //         next.next = Some(node);
        //         p.as_mut().unwrap().next = Some(next);
        //         p = &mut p.as_mut().unwrap().next.as_mut().unwrap().next;
        //     } else {
        //         p.as_mut().unwrap().next = Some(node);
        //         break;
        //     }
        //     head = p.as_mut().unwrap().next.as_mut().unwrap().next.take();
        // }

        let mut dummy = Some(Box::new(ListNode { val: 0, next: head}));
        let mut head = dummy.as_mut();
        loop {
            let mut left = head.as_mut().unwrap().next.take();
            if left.is_none() {
                break;
            }
            let mut right = left.as_mut().unwrap().next.take();
            if right.is_none() {
                // when ele is odd, left is the last ele
                head.as_mut().unwrap().next = left;
                break;
            }

            // head -> left -> right -> next
            // head -> right -> left -> next
            let mut next = right.as_mut().unwrap().next.take();
            left.as_mut().unwrap().next = next;
            right.as_mut().unwrap().next = left;
            head.as_mut().unwrap().next = right;
            head = head.unwrap().next.as_mut().unwrap().next.as_mut();
        }

        dummy.unwrap().next
    }
}