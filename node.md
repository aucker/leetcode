## Nov-17

In C++, `nullptr` and `NULL` can often be used interchangeably to represent a null pointer. However, there are some diffs between them:

1. `NULL` is a macro that is typically defined as `0` or `(void*)0`. This can sometimes lead to ambiguity. E.g., if a function has overloads for both integer and pointer arguments, and you call it with `NULL`, the compiler might not be able to determine which overload you intended to call.
2. `nullptr` is a keyword in C++11 and later that represents a null pointer value. It has its own type (`std::nullptr_t`), which can implicitly convert to any pointer type. This makes it unambiguous when used with overloaded functions.

However, using `nullptr` is generally recommended in C++ code 'cause it's more type-safe and less ambiguous.