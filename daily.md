# Leetcode daily

## help me to keep coding everyday

### 2023-11-14 [leetcode 2785](https://leetcode.com/problems/sort-vowels-in-a-string/?envType=daily-question&envId=2023-11-13)

```cpp
class Solution {
    string sortVowels(string s) {
        vector<char> vowels;
        for (char c : s) {
            if (string("aeiouAEIOU").find(c) != string::npos) {
                vowels.push_back(c);
            }
        }

        sort(vowels.begin(), vowels.end(), greater<char>());
        string result;
        for (char c : s) {
            if (string("aeiouAEIOU").find(c) != string::npos) {
                result += vowels.back();
                vowels.pop_back();
            } else {
                result += c;
            }
        }

        return result;
    }
}
```

```python
class Solution:
    def sortVowels(self, s: str) -> str:
        vowels_sorted = sorted([c for c in s if c.lower() in 'aeiou'], reverse=True)

        result = []
        for char in s:
            if char.lower() in 'aeiou':
                result.append(vowels_sorted.pop())
            else:
                result.append(char)
        
        return ''.join(result)
```