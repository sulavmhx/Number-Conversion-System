# Number Conversion and Bitwise Tools

A C programming project that performs number system conversions, bitwise operations, and maintains operation logs using file handling.

---

## Features

### Number Conversion

Supports conversion between:

* Binary
* Decimal
* Octal
* Hexadecimal

Examples:

* Binary → Decimal
* Binary → Octal
* Binary → Hexadecimal
* Decimal → Binary
* Decimal → Octal
* Decimal → Hexadecimal
* Octal → Binary
* Octal → Decimal
* Octal → Hexadecimal
* Hexadecimal → Binary
* Hexadecimal → Decimal
* Hexadecimal → Octal

---

### Bitwise Operations

Supported operations:

* AND
* OR
* NOT
* XOR
* XNOR
* NAND
* Left Shift
* Right Shift
* Count Set Bits

---

### Logging System

The project automatically stores operation history.

#### Number Conversion Logs

Stored in:

```text
NumConvLog.txt
```

Stored information:

* Input Base
* Output Base
* Input Value
* Output Value
* Date and Time

#### Bitwise Operation Logs

Stored in:

```text
BitwiseLog.txt
```

Stored information:

* Operation Type
* Input Values
* Result
* Date and Time

---

## Project Structure

```text
.
├── main.c
├── Input.c
├── Output.c
├── NumConv.c
├── Bitwise.c
├── FileHandle.c
├── Utility.c
├── Global.c
│
├── Input.h
├── Output.h
├── NumConv.h
├── Bitwise.h
├── FileHandle.h
├── Utility.h
├── Global.h
│
├── NumConvLog.txt
├── BitwiseLog.txt
└── README.md
```

---

## How to Compile

Using GCC:

```bash
gcc *.c -o NumberConverter
```

Or use the provided Dev-C++ project files.

---

## How to Run

1. Compile the project.
2. Run the executable.
3. Select a module:

   * Number Conversion
   * Bitwise Tools
4. Follow the on-screen instructions.

---

## Technologies Used

* C Programming Language
* File Handling
* Structures
* Header Files
* Bitwise Operators
* Modular Programming

---

## Notes

* Log files are created automatically when operations are performed.
* Existing log files can be deleted to clear history.
* Bitwise operations use unsigned integer values.
* Input validation should be performed for best results.

---

## Author

Developed as a C Programming Project for learning:

* Number Systems
* Bitwise Operations
* File Handling
* Modular Programming
* Data Structures in C
