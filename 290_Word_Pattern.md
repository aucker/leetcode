## Problem

Given a `pattern` and a string `s`, find if `s` follows the same pattern.

Here **follow** means a full match, such that there is a bijection between a letter in `pattern` and a **non-empty** word in `s`.

### Example

```
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
```

```
Input: pattern = "abba", s = "dog cat cat fish"
Output: false
```

## Solution

```go
func wordPattern(pattern string, s string) bool {
    words := strings.Split(s, " ")
    used := make(map[string], 0)

    if len(pattern) != len(words) {
        return false
    }

    m := make(map[byte]string)

    for i := 0; i < len(pattern); i++ {
        p := pattern[i]
        w := words[i]
        v, found := m[p]
        if found && v != w {
            return false
        }

        if contains(used, w) && found == false {
            return false
        }

        m[p] = w
        used = append(used, w)
    }
    return true
}

func contains(s []string, e string) bool {
    for _, a := range s {
        if a == e {
            return true
        }
    }
    return false
}
```
```