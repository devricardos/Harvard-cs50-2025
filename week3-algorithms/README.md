# 📂 **Week 3 – Algorithms**  

This week, I learned about algorithms, focusing on iteration, recursion, searching, and problem-solving strategies in C. I practiced implementing different approaches to solve algorithmic problems efficiently.  

---

## 💡 **Concepts Learned**  
✓ Algorithms: Understanding algorithms as step-by-step procedures for solving problems efficiently.  
✓ Big O Notation: Learning to describe algorithm efficiency in terms of time and space complexity (e.g., O(n), O(n²)).  
✓ Linear Search: Exploring a simple search algorithm that checks each element sequentially until a match is found or the list ends.  
✓ Binary Search: Understanding a faster search algorithm for sorted arrays, dividing the search space in half each step.  
✓ Sorting Algorithms: Studying algorithms like bubble sort, selection sort, and merge sort to arrange data in order.  
✓ Algorithmic Trade-offs: Recognizing the balance between time complexity, space complexity, and code simplicity.  

---

## 🛠️ **Techniques / Skills Practiced**  
✓ Implementing Search Algorithms: Writing C code for linear search and binary search to find elements in arrays.
✓ Debugging Algorithms: Using debugging techniques to troubleshoot issues in search and sort implementations.

---

## 📂 Files / Problem Sets

### 🔐 Problem Sets
-
-
-

### 🔗 **Lecture Files**  
- [iteration.c](week3-algorithms/iteration.c) – Practiced loops and iterative problem-solving  
- [phonebook.c](week3-algorithms/phonebook.c) – Implemented a simple phonebook using arrays and structs  
- [recursion.c](week3-algorithms/recursion.c) – Solved problems recursively, understanding the stack flow  
- [search.c](week3-algorithms/search.c) – Implemented linear and binary search algorithms  

## 🛠️ **Compilation and Execution**  
For files with no arguments:  
```bash
make iteration
./iteration
```
---
 
## 📝 **Notes / Best Practices**  
✓ Always test with edge cases to ensure correctness  
✓ Trace recursive calls carefully to understand the program flow  
✓ Use clear variable names for readability  
✓ Compare iterative vs. recursive solutions for performance  
✓ Debugging recursive and iterative solutions  
✓ Understanding algorithm efficiency (Big O notation) is crucial: 
- The best complexities are O(1) and O(log n) (nice graph here: https://www.bigocheatsheet.com/).  
- The O(log n) complexity is associated with algorithms using the divide-and-conquer technique, such as in binary trees, which are data structures where each node can have up to two children, it uses the divide and conquer techinique we learned on week 1.  
- Worst-case scenario is O(n!) factorial

---
  
##🔗 **Resources**  
[CS50 Week 3 Lecture](https://cs50.harvard.edu/x/weeks/3/)  
[CS50 Problem Set 3](https://cs50.harvard.edu/x/psets/3/)
