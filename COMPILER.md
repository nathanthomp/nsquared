# The C Squared Programming Language
A modern twist on the C programming language, while keeping system-level functionality.

[//]: # (What is the c squared programming language trying to accomplish?)
## Objective
To make a programming language that mimicks the C programming language, but adds modern programming language features. 
Keeping the system-level functionality but adding features such as abstraction, encapsulation, inheiritance, polymorphism, generics, and type safety.
 
[//]: # (What do we like and dislike about the C programming language?)
### Advantages to the C Programming Language
1. **Code Portability:**
C is highly portable. You can write code on one system and use it on another without major modifications. This portability is essential for cross-platform development.
2. **Ease of Learning and Understanding:**
C has a straightforward syntax, making it easy for beginners to grasp the concepts.
Online tutorials and resources help individuals learn C effectively.
3. **Rich Libraries:**
C provides access to numerous built-in functions and libraries.
These libraries enhance problem-solving abilities and simplify practical programming tasks.
4. **Efficient Execution:**
C executes faster than many other programming languages due to its minimalistic design and fewer instructions.
Developers who prioritize speed often choose C for their applications.
5. **Compile Time Accuracy:**
The C compiler efficiently translates code into machine-level instructions.
It can handle large codebases, compiling thousands of lines of code in seconds.
6. **Backbone for Other Languages:**
C serves as the foundation for many other programming languages, including C++, Java, and Python.
Its flexibility and low-level features make it an ideal choice for building language interpreters and compilers.
7. **System-Level Programming:**
C is well-suited for system-level programming, such as writing operating systems, device drivers, and embedded systems.
Its closeness to hardware allows developers to control low-level details.

### Problems With the C Programming Language

1. **Memory Management Issues:**
C provides low-level memory management through pointers, which can lead to memory leaks, buffer overflows, and other memory-related errors.
Developers need to manually allocate and deallocate memory, which can be error-prone.
2. **Lack of Abstraction:**
C lacks high-level abstractions like classes, objects, and namespaces found in modern languages.
This can make code less modular and harder to maintain.
3. **Unsafe Functions:**
C includes functions like gets() and strcpy() that don’t perform bounds checking, leading to buffer overflows.
Developers need to be cautious when using these functions.
4. **Undefined Behavior:**
C allows undefined behavior, such as accessing uninitialized variables or dereferencing null pointers.
This can lead to unpredictable results and difficult-to-debug issues.
5. **Platform Dependencies:**
C code can be highly platform-dependent due to differences in compilers, libraries, and system calls.
Porting C code across different platforms can be challenging.
6. **No Standard Library for Common Tasks:**
Unlike languages like Python or Java, C lacks a comprehensive standard library for common tasks like string manipulation, file I/O, and networking.
Developers often rely on third-party libraries.
7. **Manual Memory Allocation:**
C requires explicit memory allocation and deallocation using malloc() and free().
Managing memory correctly can be complex and error-prone.
8. **Pointer Arithmetic:**
While powerful, pointer arithmetic can lead to subtle bugs.
Incorrect pointer arithmetic can cause memory corruption or invalid memory access.
9. **Lack of String Safety:**
C strings are null-terminated character arrays, which can lead to buffer overflows if not handled carefully.
String manipulation functions like strcat() and sprintf() can be risky.
10. **Limited Type Checking:**
C’s weak type checking allows implicit type conversions, which can lead to unexpected behavior.
Developers need to be vigilant about type mismatches.

[//]: # (Doesnt C++ do the same thing?)

### Modern Day Programming Languages
