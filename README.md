# Postfix Calculator

This program is a command-line postfix calculator that uses a stack-based approach to evaluate expressions in postfix notation (Reverse Polish Notation). It reads an expression containing operands and operators separated by spaces, then calculates the result by evaluating the expression from left to right.

### How It Works

1. **Stack Structure**: The program uses a custom stack structure to push and pop operands. Each node in the stack stores a `double` value and a pointer to the next node.
2. **Operations**: Supported operations are addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`). The calculator follows postfix evaluation rules:
   - When an operator is encountered, two operands are popped from the stack.
   - The operation is performed, and the result is pushed back onto the stack.
3. **Result Display**: After processing all characters in the expression, the final result is displayed.

---

### Features

- Handles basic arithmetic operations: `+`, `-`, `*`, `/`
- Supports multiple-digit numbers and spaces between tokens
- Stack implementation using linked list nodes

---

### Prerequisites

- **Compiler**: Requires a C compiler (such as GCC or Clang).
- **Platform**: Cross-platform (Windows, Linux, macOS).

---

### Getting Started

#### 1. Clone the Repository
```bash
git clone https://github.com/yourusername/yourrepository.git
cd yourrepository
```

#### 2. Compile the Program
Compile the program using a C compiler.
```bash
gcc postfix_calculator.c -o postfix_calculator
```

#### 3. Run the Program
Execute the compiled binary.
```bash
./postfix_calculator
```

---

### Usage

1. **Input the Expression Size**: Enter the number of characters in the postfix expression (including spaces).
2. **Input the Postfix Expression**: Enter a postfix expression where each number and operator is separated by a single space.

#### Example

```plaintext
Enter the size of the expression: 17
Enter the expression:9 3 4 * 8 + 4 / -
Result: 4.000000
```

#### Sample Postfix Expression

- `9 3 4 * 8 + 4 / -` evaluates to `-3`.
- Explanation:
  - `3 * 4 = 12`
  - `9 - (12 + 8) / 4 = 4`

---

### Code Overview

- **`main`**: Main function that handles user input, initializes the stack, and iterates over the expression.
- **`instructions`**: Displays instructions for input format.
- **`doOperation`**: Performs arithmetic operations based on the operator and two operands.
- **`push`**: Adds a new element onto the stack.
- **`pop`**: Removes the top element from the stack and returns its value.
- **`substringToDouble`**: Converts a substring to a double.
- **`isOperator`**: Checks if a character is a valid operator (`+`, `-`, `*`, `/`).

---

### Notes

- For a more detailed, commented version of this program, refer to the `dataStructure` repository.
- The program assumes that the postfix expression is valid and does not handle errors related to incorrect input formatting or division by zero.
