## Nov-17

In C++, `nullptr` and `NULL` can often be used interchangeably to represent a null pointer. However, there are some diffs between them:

1. `NULL` is a macro that is typically defined as `0` or `(void*)0`. This can sometimes lead to ambiguity. E.g., if a function has overloads for both integer and pointer arguments, and you call it with `NULL`, the compiler might not be able to determine which overload you intended to call.
2. `nullptr` is a keyword in C++11 and later that represents a null pointer value. It has its own type (`std::nullptr_t`), which can implicitly convert to any pointer type. This makes it unambiguous when used with overloaded functions.

However, using `nullptr` is generally recommended in C++ code 'cause it's more type-safe and less ambiguous.

---

## Nov-18

Diffs between `if (!p)`, `if (p==NULL)` and `if (p==nullptr)`

1. if(!p)
The expression is the most idiomatic way to check whether a pointer is null in C and C++. It uses the logical negation operator `!` to check whether the value of the pointer `p` is zero. If the value of `p` is zero, then the expression `!p` is true, and the if statement will be executed. Otherwise the expression, vice versa.

2. if (p==NULL)
Also a valid way to check pointer is null or not in C/C++. `NULL` macro is a predefined constant that is equal to zero.

3. if (p==nullptr)
Most modern way to check whether a pointer is null in C++. `nullptr` is a special keyword introduced in C++11 to represent a null pointer.

In general, recommended way is to use `if (!p)`. And `if (p == nullptr)` is the most modern way to check whether a pointer is null in C++.
