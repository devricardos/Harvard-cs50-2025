# 📂 Week 4 - Recover - Problem Set

The goal of this problem set is to recover JPEGs from a forensic image (damaged file).
The program `recover.c` reads a raw memory card file and extracts JPEG files.

---

## 🛠️ Files

* `recover.c` - main C program for recovering JPEGs.
* `recovered-images/` - folder containing sample recovered JPEGs.
* `card.raw` - “forensic image” of the memory card, provided by CS50.

---

## ✅ Compilation and Execution

Run with:

```bash
./recover card.raw
```

The program outputs recovered JPEGs named:

```
000.jpg, 001.jpg, 002.jpg, ...
```

These will normally appear in the same folder as the executable, but for better organization, they have been moved to the `recovered-images/` folder.

---

## 📸 Example Output

Recovered JPEGs (sample images in `recovered-images/`):

![Recovered Image 1](recovered-images/000.jpg)
![Recovered Image 24](recovered-images/024.jpg)
![Recovered Image 49](recovered-images/049.jpg)

---

## 📝 Notes

* Uses `fopen`, `fread`, and `fwrite` to handle file I/O.
* Detects JPEG file beginnings using file signatures.
* Names files sequentially for easy identification.
* Handles memory carefully to avoid leaks.

---

## 🔗 Resources

* [CS50 Recover PSet](https://cs50.harvard.edu/x/2025/psets/4/recover/)
* [CS50 Docs](https://cs50.readthedocs.io/)

---
