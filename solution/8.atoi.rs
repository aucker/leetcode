/// Implement of 'myAtoi(string s)' which converge the 'string' to 32-byte signed num;
///

impl Solution {
    pub fn my_atio(s: String) -> i32 {
        let mut result = 0;
        let mut sign = 1;
        let mut index = 0;

        // delete the space
        while index < s.len() && ' ' == s.as_bytes()[index] {index += 1}
        // count the sign
        if index < s.len() && '-' == s.as_bytes()[index] {sign = -1; index += 1}
        else if index < s.len() && '+' = s.as_bytes()[index] {index+=1}

        // calculate the number
        while index < s.len() && s.as_bytes()[index] >= '0' && s.as_bytes()[index] <= '9' {
            let mut num = s.as_bytes()[index] as i32 - '0' as i32;
            if result > (i32::MAX - num) / 10 {return i32::MAX}
            if result < (i32::MIN + num) / 10 {return i32::MIN}
            result = result * 10 + num * sign;
            index += 1;
        }
        result
    }
}

/// try to use cpp finish this, quite easy
/// class Solution {
/// public:
///     int myAtoi(string s) {
///         int result = 0;
///         int sign = 1;
///         int index = 0;
///
///         // delete the space
///         while (index < s.size() && ' ' == s[index]) index++;
///         // count the sign
///         if (index < s.size() && '-' == s[index]) sign = -1; index++;
///         else if (index < s.size() && '+' == s[index]) index++;
///
///         // calculate the result
///         while (index < s.size() && s[index] >= '0' && s[index] <= '9') {
///             int num = s[index] - '0';
///             if (result > (INT_MAX-num) / 10) return INT_MAX;
///             if (result < (INT_MIN + num) / 10) return INT_MIN;
///             result = result * 10 + num * sign;
///             index++;
///         }
///         return result;
///     }
/// }
