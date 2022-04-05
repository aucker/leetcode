// reference link:
// https://leetcode.com/problems/lru-cache/

use std::{rc::Rc, cell::{RefCell, Ref}, collections::HashMap};

struct ListNode {
    key: i32,
    value: i32,
    prev: Option<Rc<RefCell<ListNode>>>,
    next: Option<Rc<RefCell<ListNode>>>
}
impl ListNode {
    fn new(k: i32, v: i32) -> Self {
        ListNode { 
            key: k, 
            value: v,
            prev: None, 
            next: None, 
        }
    }
}

struct LRUCache {
    map: HashMap<i32, Rc<RefCell<ListNode>>>,
    capacity: usize,
    head: Option<Rc<RefCell<ListNode>>>,
    tail: Option<Rc<RefCell<ListNode>>>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {

    fn new(capacity: i32) -> Self {
        LRUCache { 
            map: HashMap::new(), 
            capacity: capacity as usize, 
            head: None, 
            tail: None 
        }
    }
    
    fn get(&mut self, key: i32) -> i32 {
        if let Some(node) = self.map.get(&key) {
            let node = Rc::clone(node);
            let value = node.borrow().value;
            self.remove(&node);
            self.offer_last(&node);
            value
        } else {
            -1
        }  
    }
    
    fn put(&mut self, key: i32, value: i32) {
        if self.map.contains_key(&key) {
            let node_exist = Rc::clone(self.map.get(&key).unwrap());
            self.remove(&node_exist);
        } else {
            if self.map.len() == self.capacity {
                self.poll_first();
            }
        }
        let node_insert = Rc::new(RefCell::new(ListNode::new(key, value)));
        self.offer_last(&node_insert);
    }

    fn remove(&mut self, node: &Rc<RefCell<ListNode>>) {
        match (
            Rc::clone(node).borrow().prev.as_ref(),
            Rc::clone(node).borrow().next.as_ref(),
        ) {
            (None, None) => {
                self.head = None;
                self.tail = None;
            }
            (None, Some(next)) => {
                self.head = Some(Rc::clone(next));
                next.borrow_mut().prev = None;
            }
            (Some(prev), None) => {
                self.tail = Some(Rc::clone(prev));
                prev.borrow_mut().next = None;
            }
            (Some(prev), Some(next)) => {
                next.borrow_mut().prev = Some(Rc::clone(prev));
                prev.borrow_mut().next = Some(Rc::clone(next));
            }
        }
        let key = node.borrow().key;
        self.map.remove(&key);
    }

    fn offer_last(&mut self, node: &Rc<RefCell<ListNode>>) {
        let node = Rc::clone(node);
        let mut node_borrow = node.borrow_mut();
        if let Some(n) = self.tail.take() {
            n.borrow_mut().next = Some(Rc::clone(&node));

            node_borrow.prev = Some(n);
            node_borrow.next = None;

            self.tail = Some(Rc::clone(&node));
        } else {
            // empty the ListNode
            node_borrow.prev = None;
            node_borrow.next = None;

            self.head = Some(Rc::clone(&node));
            self.tail = Some(Rc::clone(&node));
        }
        let key = node_borrow.key;
        self.map.insert(key, Rc::clone(&node));
    }

    fn poll_first(&mut self) -> Option<Rc<RefCell<ListNode>>> {
        if let Some(node) = self.head.take() {
            // remove from map
            let key = node.borrow().key;
            self.map.remove(&key);

            // update linklist
            match node.borrow().next.as_ref() {
                Some(next) => {
                    let next = Rc::clone(next);
                    next.borrow_mut().prev = None;
                    self.head = Some(next);
                }
                None => {
                    self.head = None;
                    self.tail = None;
                }
            }
            Some(node)
        } else {
            None
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = LRUCache::new(capacity);
 * let ret_1: i32 = obj.get(key);
 * obj.put(key, value);
 */


#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn it_works() {
        // let result = 2 + 2;
        let mut cache = LRUCache::new(2);
        cache.put(1, 1);
        cache.put(1, 2);
        assert_eq!(cache.get(1), 2);
        cache.put(2, 2);
        cache.put(3, 3);
        assert_eq!(cache.get(1), -1);
        cache.put(4, 4);
        assert_eq!(cache.get(2), -1);
        assert_eq!(cache.get(3), 3);
        assert_eq!(cache.get(4), 4);
    }
}

// there still need optimization