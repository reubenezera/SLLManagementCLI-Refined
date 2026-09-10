# [WORK IN PROGRESS] SLL Management CLI - Refined
A refined version of my SLL Management CLI project, where I implement more professional programming practices.

## How to run

### Option 1: Run online with Programmiz

1. Copy the code in `main.c`.
2. Open [Programmiz's Online C Compiler](https://www.programiz.com/c-programming/online-compiler/).
3. Paste the code into the compiler.
4. Run the code.

### Option 2: Run locally in VS Code or another IDE

Make sure a C compiler is installed. macOS includes Clang with the Xcode Command Line Tools. In VS Code or your IDE, open a terminal in the folder containing `main.c`, then run:

```bash
clang -std=c11 -Wall -Wextra -pedantic main.c -o sll
./sll
```

The first command compiles `main.c` into an executable named `sll`. The second command runs it. On Windows, use a compiler such as GCC or Clang and replace `./sll` with `sll.exe` if necessary.
