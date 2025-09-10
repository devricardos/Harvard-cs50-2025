# 🗂️ Week 2 - Arrays

In Week 2 of CS50, we focused on arrays, strings, and basic cryptography. Exercises provided hands-on experience with C programming, emphasizing preprocessing, compiling, and debugging.

---

## 💡 **Concepts Learned**  
✓ Arrays: Understanding arrays as contiguous memory blocks for storing multiple values of the same data type, accessed via indices.  
✓ Strings: Recognizing strings in C as arrays of characters terminated by a null character (\0).  
✓ Command-Line Arguments: Learning how argc (argument count) and argv (argument vector) allow programs to process user inputs from the command line.  
✓ Cryptography Basics: Exploring simple cryptographic techniques, such as encoding/decoding text using ciphers.  
✓ Memory Concepts: Understanding how arrays are stored in memory and their relationship to memory allocation in C.  

---

## 🛠️ **Techniques / Skills Practiced**  
✓ Array Manipulation: Declaring, initializing, and accessing array elements in C (e.g., int numbers[] = {1, 2, 3}).  
✓ String Handling: Using string manipulation functions (e.g., strcmp) and processing strings as character arrays.  
✓ Command-Line Input Processing: Writing programs that handle inputs via argc and argv (e.g., printing user-provided arguments).  
✓ Debugging: Applying techniques like print statements, stepping through code with a debugger, and "rubber duck debugging" to identify errors.  
✓ Programming in C: Writing and running C programs, including using libraries like cs50.h and managing return values (e.g., return 0 for success).  
✓ Problem-Solving with Arrays/Strings: Implementing solutions for problem sets like Scrabble (scoring words), Readability (text analysis), Caesar (cipher encryption), and Substitution (complex cipher).  

---

## 📂 Files / Problem Sets

### 🔐 Problem Sets

- [**caesar.c**](week2-arrays/caesar.c) — Implements Caesar cipher encryption.
- [**readability.c**](week2-arrays/readability.c) — Calculates the readability score of a text using the Coleman-Liau index.
- [**scrabble.c**](week2-arrays/scrabble.c) — Computes the Scrabble score of a word.

### 🛠️ Other Files

- [**buggy.c**](week2-arrays/buggy.c) — Contains intentional bugs for debugging practice.
- [**greet.c**](week2-arrays/greet.c) — Greets the user with a personalized message.
- [**hi.c**](week2-arrays/hi.c) — Prints "Hi, world!" to the console.
- [**length.c**](week2-arrays/length.c) — Calculates the length of a string.
- [**scores.c**](week2-arrays/scores.c) — Computes the average score from a list of scores.
- [**status.c**](week2-arrays/status.c) — Evaluates the status of a student based on their score.
- [**string.c**](week2-arrays/string.c) — Demonstrates basic string operations.
- [**uppercase.c**](week2-arrays/uppercase.c) — Converts a string to uppercase.

## 🛠️ Compilation and Execution

To compile and run each program, use the following commands:

```bash
# Problem sets that require arguments

# Caesar cipher requires a numerical key
make caesar
./caesar 3

# Readability requires a text input
make readability
./readability "Your text here."

# Scrabble computes score for a word
make scrabble
./scrabble "word"

# Programs that do not require command-line arguments
make buggy
./buggy

make greet
./greet

make hi
./hi

make length
./length

make scores
./scores

make status
./status

make string
./string

make uppercase
./uppercase

```

## 🔗 Resources
[CS50 Week 2 Lecture](https://cs50.harvard.edu/x/weeks/2/)  
[CS50 Problem Set 2](https://cs50.harvard.edu/x/psets/2/)
