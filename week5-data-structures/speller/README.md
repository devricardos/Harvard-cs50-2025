# 📂 Week 5 – Data Structures - Speller Problem Set

This week’s problem set implements a spell checker that uses a **hash table** to store words from a dictionary and quickly check if words in a text are spelled correctly.  

---

## 🔐 Files
- [dictionary.c](dictionary.c) – my implementation  
- [dictionary.h](dictionary.h) – provided header  
- [speller.c](speller.c) – provided driver  
- [Makefile](Makefile) – build configuration  
- [texts/](texts/) – sample test files (provided by CS50)  
- [dictionaries/](dictionaries/) – optional dictionary files (provided by CS50)  

---

## 🛠️ Compilation and Execution
```bash
# Build the program
make speller

# Run speller with a text file and a dictionary
./speller texts/lalaland.txt
./speller dictionaries/small texts/cat.txt
```

---

## ✅ Notes
- Implemented the required functions: `check`, `hash`, `load`, `size`, and `unload`.  
- Inserted nodes at the **head of linked lists** for O(1) insertion.  
- Converted words to lowercase for **case-insensitive checks**.  
- Freed all memory with `unload()` to avoid leaks.  

---

## 🔗 Resources
- [CS50 Week 5 Lecture](https://cs50.harvard.edu/x/2025/weeks/5/)  
- [Speller Problem Set](https://cs50.harvard.edu/x/2025/psets/5/speller/)  


