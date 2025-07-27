# Mini Malloc Tracker

This is a simple C program to explore and better understand **dynamic memory management** using `malloc()` and `free()`.

## What I learned

- In C, memory management is manual. You have to explicitly request memory with `malloc()` and release it with `free()`.
- When you use `malloc()`, it returns a **pointer to a memory address** in the heap.
- You can assign values to that memory using the pointer, like `*a = 42;`.
- The addresses returned by `malloc()` are usually aligned in memory (e.g., 0x20 or 32 bytes apart), depending on the system.
- If you forget to call `free()`, the memory is not returned to the system → this is called a **memory leak**.
- C does **not warn you** if you forget to free memory – your program might still run fine, but the leak is real.
- You can detect such issues using tools like **Valgrind**, which shows leaked memory and other memory-related bugs.

## Example output

```bash
Adresse von a: 0x5556920442a0, Wert: 42
Adresse von b: 0x5556920442c0, Wert: 1337
Adresse von c: 0x5556920442e0, Wert: 7
```
