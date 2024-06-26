# The Nsquared Programming Language
The Nsquared programming language is a statically typed, imperative language that uses the abstraction of *Expressions* and *Statements*. Compiler built in C.

Sub Class: Procedural or Object-Oriented

## Context-Free Grammar (Syntax)
```
Statement - Execution
    statement := declaration | if | ifelse | while | return
      declaration := type label = expression semi
        type := user | primative
          user := [A-Z][a-zA-Z]*
          primative := Int | Char | Bool | Float
        label := [A-Z][a-zA-Z]*
      if := if ( expression ) { statement semi }
      ifelse := if ( expression ) { statement semi } else { statement semi }
      while := while ( expression ) { statement semi }
      return := return expression semi

Expression - Evaluation
    expression := 
```

## Type System

### 1. User Defined Types

- User defined types must start with a capital letter and follow pascal case

### 2. Primative Types

Categories:
Signed, Unsigned, 

| Type | Keyword | Size | Range |
| --- | --- | --- | --- |
| Integer |  | 32 bit | -2,147,483,647 to 2,147,483,647 |
| Long |  | 64 bit | |
| Float |  | 32 bit | 3.4x10^-38 to 3.4x10^38 |
| Boolean |  | 1 bit  | 0 to 1 |
| Character |  | 8 bit | 0 to 255 |

Signed / Unsigned 
Total size of Type

Whole Numbers:
8 bits
16 bits
32 bits
64 bits


The **Integer** type has a size of 32 bit. This data type represents the set of Natural Numbers with a lower bound of -2,147,483,647 and an upper bound of 2,147,483,647.

The **Float** type has a size of 32 bits, 1 bit for the sign, 23 bits for the matissa, and 8 bits for the exponent. This data type represents the set of Real Numbers with a lower bound of 0.000000000000000000000000000000000000034 and an upper bound of 339,999,999,999,999,996,123,846,586,046,231,871,488.

The **Boolean** type has a size of 1 bit. This data type represents propositional logic, where 1 is for true, and 0 for false.

The **Character** type has a size of 8 bits, representing one byte of unsigned data. This data type represents each of the character codes from the ASCII table.

## Scopes

The Nsquared programming language does not have public and private members to a Type, but instead defines these members by their scope.

## Operations

### How to write your Nsquared program
To write a Nsquared program...
Documentation for the Nsquared programming language can be found [here](docs/language/README.md)

### How to compile your Nsquared file
The Nsquared compiler, located [here](docs/compiler/README.md), can be built by the command `$ make` when in the `nsquared/compiler` directory. To use the compiler enter the command:
```
$ nsc -r
``` 
for REPL mode, or
```
$ nsc filename.ns
```
for file mode.

### How to run your Nsquared program
