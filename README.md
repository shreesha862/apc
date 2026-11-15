# Arbitrary-Precision Calculator (APC)

A console-based big-number calculator written in C that performs mathematical operations on arbitrarily large integers and decimal numbers using doubly linked lists.

## Features
- **Supported Operations:** Performs Addition (`+`), Subtraction (`-`), Multiplication (`*`), Division (`/`), Modulus (`%`), and Power (`^`) on numbers exceeding standard 64-bit hardware limits.
- **Linked List Storage:** Slices large input numbers into nodes based on `sizeof(int)` for portable, memory-bounded precision.
- **Decimal & Carry Handling:** Accurately manages carries, borrows, signs, and decimal points across linked list nodes.
- **Edge-Case Optimization:** Optimizes calculations for zero inputs and corner cases to reduce unnecessary computation.
- **Interactive CLI:** Automatically parses expressions entered in the terminal (e.g., `x+y`) and supports continuous calculations via a `[yY | nN]` prompt.

## Tech Stack
- **Language:** C
- **Concepts:** Doubly Linked Lists (ADTs), Dynamic Memory Allocation, String Parsing, Arbitrary-Precision Arithmetic

