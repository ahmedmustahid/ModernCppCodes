# Lecture 6 Iterators

### Highlights
1. iterator has ordering over elems; it always knows what the “next” element is.  `it = container.begin();`, `++it` upto `container.end()`
2. Dereference element: `*it`
3. Why use ++iter and not iter++? => ++iter returns the value after being incremented, so there’s no need to store the old value of the iterator!
4. dereferencing a `std::map::iterator` returns a `std::pair`. Iterator of a map corresponds to pair. Incrementing iterator once moves to the next `std::pair`.
5. Iterator obtained from a container becomes invalid if the elements being iterated over change address or are destroyed. [Iterator invalidation](https://en.cppreference.com/w/cpp/container/vector#Iterator_invalidation)

### [Types of iterators](https://www.cplusplus.com/reference/iterator/)
0. All categories
    1. copy-constructible, copy-assignable and destructible `X b(a);` `b = a;`
    2. Can be incremented `a++`, `++a`

1. Input:  
        1. Read only 
        2. Supports equality/inequality comparisons `a == b`, `a != b`
        3. Can be dereferenced as an rvalue `*a`, `a->m`
2. Output:
        1. Write + all other functions of Input
        2. Can be dereferenced as an lvalue (only for mutable iterator types) `*a = t`, `*a++ = t`
3. Forward 
        1. default-constructible `X a;`, `X()`
        2. Multi-pass: neither dereferencing nor incrementing affects dereferenceability `{ b=a; *a++; *b; }`

4. Bidirectional
        1. Can be decremented `--a` , `a--` , `*a--`

5. Random Access
        1. Supports arithmetic operators + and -
        2. Supports inequality comparisons (<, >, <= and >=) between iterators
        3. Supports compound assignment operations += and -=
        4. Supports offset dereference operator ([])


