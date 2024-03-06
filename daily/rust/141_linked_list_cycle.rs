pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> ListNode {
        ListNode { next: None, val }
    }
}

impl Solution {
    pub fn has_cycle(head: Option<Box<ListNode>>) -> bool {
        let (mut slow, mut fast) = (head.as_ref(), head.as_ref());
        while fast.is_some() && fast.as_ref().unwrap().next.is_some() {
            slow = slow.unwrap().next.as_ref();
            fast = fast.unwrap().next.as_ref().unwrap().next.as_ref();
            if slow.as_ref().unwrap() as *const _ == fast.as_ref().unwrap() as *const _ {
                return true;
            }
        }
        false
    }
}