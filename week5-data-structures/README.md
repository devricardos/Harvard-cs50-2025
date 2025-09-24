# 📂 **Week 5 – Data Structures**
This week I learned how computers use **data structures** to organize and process information efficiently. I practiced building **linked lists, hash tables, and tries**, and saw the trade-offs between time and memory. Implementing the **Speller** project helped me understand hashing, pointers, memory management, and project organization in practice.

---

## 💡 **Concepts Learned**

✓ Dynamic memory management with pointers  
✓ Arrays vs. Linked Lists trade-offs  
✓ Queues (FIFO) and Stacks (LIFO)  
✓ Binary Trees for ordered data storage and lookup  
✓ Dictionaries as abstract data types (key → value mapping)  
✓ Hashing and Hash Tables for faster lookups  
✓ Tries for efficient prefix-based word storage  

---

## 🛠️ **Techniques Practiced**

✓ Implementing custom data structures in C language  
✓ Working with `struct`  
✓ Creating and traversing linked lists  
✓ Using hash functions to distribute data across buckets  
✓ Inserting nodes at the head of a linked list for O(1) insertion  
✓ Managing memory with `malloc` and `free`  
✓ Designing algorithms with trade-offs between time and memory space  

---

## 📂 Files / Problem Sets

### 🔐 Problem Sets

* **Speller** – Spell checker using a dictionary data structure
  
  * [`speller/dictionary.c`](speller/dictionary.c) → Dictionary implementation with hash table + linked lists (my solution)
  * [`speller/dictionary.h`](speller/dictionary.h) → Header file with dictionary function prototypes (cs50 provided)
  * [`speller/speller.c`](speller/speller.c) → Program to test the dictionary (cs50 provided)
  * `speller/texts/` → Sample text files for testing (cs50 provided)

* **Inheritance** – Simulated family tree inheritance of blood types using structs and recursion

  * [`inheritance.c`](inheritance.c)

### 🔗 **Lecture Files**

* [`list.c`](list.c) – Demonstration of building a linked list step by step

---

## 🛠️ **Compilation and Execution**

To build **Speller**:

```bash
cd speller
make speller
```

To run with a sample dictionary and text file:

```bash
./speller dictionaries/large texts/lorem.txt
```

To build **Inheritance**:

```bash
make inheritance
```

To run:

```bash
./inheritance
```

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

✓ Linked Lists

* Non-contiguous storage using nodes (structs with data + pointer to next node).
* Operations: insertion/deletion at head/tail/middle (O(1) or O(n) depending on position).
* Advantages: dynamic sizing without resizing; efficient inserts/deletes.
* Disadvantages: no random access (O(n) search); extra space for pointers.

✓ Trees

* Hierarchical structures: nodes with children (binary trees with left/right pointers).
* Binary search trees: left child < parent < right child for efficient searching (O(log n)).
* Operations: insertion, search, deletion; balancing for optimal performance.
* Trade-offs: faster than linked lists for sorted data; risk of imbalance (devolves to O(n)).

✓ Dictionaries & Hash Tables

* Abstract data type for key-value pairs (phonebooks: name → number).
* Hash functions map input to an index in a fixed range.
* Linked lists at each bucket handle collisions; average O(1) access with good hash.

✓ Tries

* Each node is an array of pointers representing string prefixes.
* Efficient for string lookups: O(length of key).
* High space usage but ideal for prefix-based data like dictionaries.

---

## 🔗 **Resources**

[CS50 Week 5 Lecture](https://cs50.harvard.edu/x/weeks/5/)  
[CS50 Problem Set 5](https://cs50.harvard.edu/x/psets/5/)
