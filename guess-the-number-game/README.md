# Guess the Number – C Project

This is a simple command-line game written in C. The goal is to guess a number randomly chosen by the computer between **1 and 100**.

---

## Rules of the Game

- The computer generates a random number between 1 and 100.
- You have unlimited attempts to guess the number.
- After each guess:
  - If your guess is more than 10 away from the number → **Cold**
  - If your guess is within ±10 of the number → **Hot**
  - If your guess is correct → **You win! 🎉**

---

## Concepts Used

This project demonstrates the following C programming concepts:

- `printf()` / `scanf()` – for input and output
- `rand()` and `srand()` – for generating random numbers
- `time()` – for random seed initialization
- `if/else` and logical operators
- Custom functions and return values
- Loop control using `while (true)`
