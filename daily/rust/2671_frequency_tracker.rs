use std::collections::HashMap;

struct FrequencyTracker {
    freq: HashMap<i32, i32>,
    freq_cnt: HashMap<i32, i32>,
}

impl FrequencyTracker {
    fn new() -> Self {
        FrequencyTracker {
            freq: HashMap::new(),
            freq_cnt: HashMap::new(),
        }
    }

    fn add(&mut self, number: i32) {
        let prev = *self.freq.get(&number).unwrap_or(&0);
        *self.freq_cnt.entry(prev).or_insert(0) -= 1;
        *self.freq.entry(number).or_insert(0) += 1;
        *self.freq_cnt.entry(prev+1).or_insert(0) += 1;
    }

    fn delete_one(&mut self, number: i32) {
        if self.freq.get(&number).unwrap_or(&0) == &0 {
            return;
        }
        let prev = *self.freq.get(&number).unwrap();
        *self.freq_cnt.entry(prev).or_insert(0) -= 1;
        *self.freq.entry(number).or_insert(0) -= 1;
        *self.freq_cnt.entry(prev - 1).or_insert(0) += 1;
    }

    fn has_frequency(&self, frequency: i32) -> bool {
        self.freq_cnt.get(&frequency).unwrap_or(&0) > &0
    }
}