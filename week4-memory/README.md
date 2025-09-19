# 📂 **Week 4 – Memory**

This week I learned how computers manage and manipulate memory. I explored pointers, hexadecimal notation, dynamic allocation, and how files are stored and accessed. I also practiced memory-safe programming, debugging with `valgrind`, and solved real-world problems like recovering deleted images from a forensic memory card.

---

## 💡 **Concepts Learned**

✓ Pointers and memory addresses  
✓ Hexadecimal notation and base-16  
✓ Bytes and bit representation  
✓ Dynamic memory allocation (`malloc`, `free`)  
✓ Buffer overflows and memory safety  
✓ Data structures in memory (arrays, strings)  
✓ File I/O (`fopen`, `fread`, `fwrite`, `fclose`)  
✓ JPEG signatures and forensic recovery

---

## 🛠️ **Techniques / Skills Practiced**

✓ Using pointers to manipulate variables and memory directly  
✓ Traversing arrays and strings with pointers  
✓ Allocating/freeing memory on the heap with `malloc` and `free`  
✓ Debugging with `valgrind` to detect memory leaks and invalid reads/writes  
✓ Reading and writing binary data from files  
✓ Implementing `recover.c` to extract JPEGs from a raw memory card

---

## 📂 Files / Problem Sets

### 🔐 Problem Sets

* [`volume.c`](./volume.c) → modifies the volume of an audio WAV file
* [`filter-more/`](./filter-more) → applies filters to BMP images
* [`recover/`](./recover) → recovers JPEGs from a raw forensic image file

### 🔗 **Lecture Files / Demos**

* [`addresses.c`](./addresses.c) – working with memory addresses
* [`compare.c`](./compare.c) – comparing strings with pointers
* [`copy.c`](./copy.c) – copying memory with pointers
* [`cp.c`](./cp.c) – file copy program
* [`garbage.c`](./garbage.c) – uninitialized variables
* [`get.c`](./get.c) – using `get_string` and input
* [`memory.c`](./memory.c) – memory allocation examples
* [`phonebook.c`](./phonebook.c) – building a phonebook with structs
* [`swap.c`](./swap.c) – demonstrates pointer swapping

---

## 🛠️ **Compilation and Execution**

For `recover.c`:

```bash
./recover card.raw
```

For `volume.c`:

```bash
./volume input.wav output.wav 2.0
```

For `filter-more`:

```bash
./filter -r input.bmp output.bmp
./filter -e input.bmp output.bmp
./filter -b input.bmp output.bmp
./filter -g input.bmp output.bmp
```

---

## 📝 **Notes**

✓ Hexadecimals (base-16): 0 1 2 3 4 5 6 7 8 9 A B C D E F

* Highest we can go: FF = 15*16 + 15*1 = 255
* RGB colors (Red Green Blue) = FFFFFF = 255 for every color = Lots of colors (all of them)
* Bit = smallest possible, can be 0 or 1
* Byte = group of 8 bits (11001011 = 8 bits = 1 byte)
* Base-16 = 2⁴ every digit always uses 4 bits, so it is perfect for computers that store info with bytes (8 bits)
* When humans write hexadecimal numbers we should use 0x1F (sample for 32 in decimal)

✓ Pointer is just a Value (memory spot) that happens to be a location (0X100C)

* `int * pX = &x;` = (english meaning) "integer pointer named pX is set to the address of x"
* `int y = *px;` = (english meaning) "integer named y is set to the value pointed to by the adress inside pX"

✓ `malloc` allocates memory on the heap, must be `freed` later  
✓ `valgrind ./program` checks memory leaks  
✓ JPEG file signatures (0xff 0xd8 0xff) identify file start  
✓ Always check return values from `fopen`, `malloc`

---

## 🔗 **Resources**

[CS50 Week 4 Lecture](https://cs50.harvard.edu/x/weeks/4/)  
[CS50 Problem Set 4](https://cs50.harvard.edu/x/psets/4/)
