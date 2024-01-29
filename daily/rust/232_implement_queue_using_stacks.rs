struct MyQueue {
    stack: Vec<i32>,
    temp: Vec<i32>,
}

impl MyQueue {
    fn new() -> Self {
        MyQueue {
            stack: Vec::new(),
            temp: Vec::new(),
        }
    }

    fn push(&mut self, x: i32) {
        while let Some(v) = self.stack.pop() {
            self.temp.push(v);
        }
        self.stack.push(x);
        while let Some(v) = self.temp.pop() {
            self.stack.push(v);
        }
    }

    fn pop(&mut self) -> i32 {
        self.stack.pop().unwrap()
    }

    fn peek(&self) -> i32 {
        *self.stack.last().unwrap()
    }

    fn empty(&self) -> bool {
        self.stack.is_empty()
    }
}