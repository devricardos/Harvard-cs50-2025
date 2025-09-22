# 📂 **Week 5 – Data Structures**



---

## 💡 **Concepts Learned**

✓ 

---

## 🛠️ **Techniques / Skills Practiced**

✓ 

---

## 📂 Files / Problem Sets

### 🔐 Problem Sets

* 

### 🔗 **Lecture Files / Demos**

* 

---

## 🛠️ **Compilation and Execution**



---

## 📝 **Notes**

✓ Topics: arrays, queues, stacks, linked lists, trees, hash tables, and tries
* Emphasis on building more sophisticated memory management using pointers
✓ Queues: FIFO (First In, First Out) structures
* Bank lines, printer
* Enqueue (add) and dequeue (remove)
✓ Stacks: LIFO (Last In, First Out) structures
* Stack of clothes, email inbox
* Push (add) and pop (remove)

✓ Resizing Arrays
* Fixed-size arrays have limitations: must specify size in advance, leading to issues when needing to grow/shrink.
* Code complexity trade-offs: time (O(n) for copying) vs. space (over-allocating wastes memory).

✓ Linked Lists (alternative to arrays)
* Non-contiguous storage using nodes (structs with data + pointer to next node).
* Operations: insertion/deletion at head/tail/middle (O(1) or O(n) depending on position).
* Advantages: dynamic sizing without resizing; efficient inserts/deletes.
* Disadvantages: no random access (O(n) search); extra space for pointers.

✓ Trees
* Hierarchical structures: nodes with children (binary trees with left/right pointers).
* Binary search trees: left child < parent < right child for efficient searching (O(log n)).
* Operations: insertion, search, deletion; balancing for optimal performance.
* Trade-offs: faster than linked lists for sorted data; risk of imbalance (devolves to O(n)).

✓ Dictionaries
* Abstract data type for key-value pairs (phonebooks: name → number).
* Implementation options: arrays, linked lists, or more efficient structures.
* Goal: fast lookups; introduction to need for better than O(n) or O(log n) time.

✓ Hashing and Hash Tables
* Hash functions: map input (key) to output (index) in a fixed range (bucketization).
* Hash tables: array of linked lists (or arrays) for handling collisions (chaining).
* Collision resolution: linked lists at each bucket; average O(1) with good hash function.
* Trade-offs: theoretical O(n) worst-case but practical near-constant time O(1); On average O(n/k)

✓ Tries (tree of arrays)
* Each node is an array of pointers (26 for A-Z), representing string prefixes.
* Efficient for string lookups: O(length of key) time, independent of total elements (n) (true O(1) relative to n).
* Operations: insertion/search by traversing letters; sentinel for word ends.
* Trade-offs: high space usage (many unused pointers); ideal for prefix-based data like dictionaries.

---

## 🔗 **Resources**

[CS50 Week 5 Lecture](https://cs50.harvard.edu/x/weeks/5/)  
[CS50 Problem Set 5](https://cs50.harvard.edu/x/psets/5/)
