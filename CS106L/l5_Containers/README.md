# Lecture 5 Containers

### Highlights
1. `std::vector` does not have a `push_front` function
2. Fast insertion/deletion using `std::deque`; `push_front` and `pop_front` functions
3. An implementation of `std::deque` stores the addresses of front, middle and back parts of a sequence and reserves empty space in front and  back. 
4. If new space is required, it creates a new sequence of memories made of `NULL`s and transfers the old sequence of values into the larger memory sequences. New values are inserted in the front or back, in the same way as before.
5. `std::list` like vector and deque combined, allows `push_front` and `pop_back`, but cannot be indexed unlike them.

### Best practices

1. Consider using [`shrink_to_ﬁt`](https://www.cplusplus.com/reference/vector/vector/shrink_to_fit/) if you don't need the memory.
2. Call `empty()`, rather than check if `size() == 0`.
3. Don't use `vector<bool>` ("noble failed experiment")

### Container Adapters
Container adaptors provide a different interface for sequence containers. You can choose what the
underlying container is. e.g. `std::stack` and `std::queue` use `std::deque` as container. 

            std::stack<int> stack_d;// Container = std::deque
            std::stack<int, std::vector<int>> stack_v;// Container = std::vector
            std::stack<int, std::list<int>> stack_l;// Container = std::list

### Associative Containers

1. The underlying type stored in a `std::map<K, V>` is a `std::pair<const K, V>`. 
2. By default, the type (for sets) or key-type (for maps) must have a comparison (<) operator deﬁned
            
        std::set<int> set1;
        // OKAY - comparable
        std::set<std::ifstream> set2;
        // ERROR - not comparable
        std::map<int, int> map1;
        // OKAY - comparable
        std::map<std::ifstream, int> map2;
        // ERROR - not comparable

3. set, map are ordered. They also have their unordered counterparts.
4. unordered set/map: Instead of a comparison operator, the element (set) or key (map) must have a hash function deﬁned for it. these are generally faster than map/set
5. multimap, multiset (+ unordered siblings): multiple of the same element (set) or key (map).

