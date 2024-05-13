# The C Squared Programming Language
A modern twist on the C programming language, while keeping system-level functionality. 

[//]: # (What is the c squared programming language trying to accomplish?)
## Objective
To make a programming language that mimicks the C programming language, but adds modern programming language features. 
Keeping the system-level functionality but adding features such as abstraction, encapsulation, inheiritance, polymorphism, generics, type safety, standard library support, .
 
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

In summary, C’s simplicity, speed, and versatility make it a powerful language for various applications, from system development to high-performance computing

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

Despite these challenges, C remains a fundamental language for systems programming, embedded systems, and performance-critical applications. It’s essential to understand these issues and adopt best practices to write robust and secure C code

[//]: # (Doesnt C++ do the same thing?)

### Modern Day Programming Languages

1. **Increased Productivity:** Modern languages often come with features that streamline development, such as concise syntax, built-in libraries, and powerful tools. These features allow developers to write code more efficiently and accomplish tasks faster.
2. **Improved Security:** Many modern languages prioritize security by design. They include features like memory safety checks, type systems, and built-in security mechanisms. For example, Rust is known for its strong memory safety guarantees, making it a popular choice for systems programming.
3. **Community Support and Resources:** Popular modern languages have large and active communities. This means you can find extensive documentation, tutorials, and libraries to help you solve problems and learn faster. Python1 and JavaScript2 are excellent examples of languages with robust communities.
4. **Cross-Platform Compatibility:** Modern languages often run on multiple platforms, including desktop, web, and mobile. This flexibility allows developers to write code once and deploy it across different environments. Kotlin3, for instance, is widely used for Android app development.
5. **Easier Maintenance and Refactoring:** Modern languages encourage clean code practices, making it easier to maintain and refactor projects. Features like strong typing, modularization, and package management contribute to code maintainability.
6. **Performance Improvements:** Some modern languages, like Go, are designed for high performance. They optimize resource usage and execution speed, making them suitable for applications that require efficiency.
7. **Concurrency and Parallelism:** Languages like Erlang and Elixir excel in handling concurrent and distributed systems. They provide lightweight processes and built-in support for parallel execution.
8. **Functional Programming:** Many modern languages embrace functional programming concepts. Functional languages like Haskell and Scala allow developers to write concise, expressive code using immutability and higher-order functions.
9. **Integration with Existing Systems:** Modern languages often have robust APIs and libraries for integrating with other technologies. For example, Java remains popular for enterprise applications due to its extensive ecosystem and compatibility with existing systems.
10. **Career Opportunities:** Learning a modern language can enhance your career prospects. Employers value developers who are proficient in languages that align with current industry trends.

## Concept
The idea of the C Squared programming language is to take the existing C syntax and add modern day features to it.
These modern day features include ...

Adding abstraction, encapsulation, inheiritance, and polymorphism increases the programming languages productivity, compared to C.

Creating a standardized library in the C Squared programming language can increase the security of program by allowing for bound checking, memory allocation, and defined behavior.

Utilizing a compiler written in C#, the C Squared programming language can support a wide variety of platforms.

When running C Squared files, the underlying implementation is in C, so the C Squared programming language keeps its original 
