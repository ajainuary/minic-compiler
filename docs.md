<h1 align="center">MiniC Language Manual</h1>

# Lexical Considerations

miniC is a case sensitive language and all keywords are in lowercase.

## Identifiers

Identifiers are terminals used for naming functions and variables, they
can consist of alphanumeric characters and underscores but they must not
begin with a digit. Since miniC is case sensitive, `foo` and `FOO` are
treated as distinct identifiers.

![8a98c58e73bacb087f8f363665c8fddc](https://user-images.githubusercontent.com/30972152/102685346-fd7c8d00-4205-11eb-85a2-645856799b4d.png)


## Keywords

Keywords are special sequences used as a part of the language itself.
The following keywords are reserved in miniC:

`if`

`else`

`for`

`integer`

`bool`

`float`

`char`

`while`

## Macro Syntax

![325af66604f5cfc42f02d9bb418e17fa](https://user-images.githubusercontent.com/30972152/102685381-2e5cc200-4206-11eb-9adf-4058d6b90763.png)


# Data Types

The language will contain the following primitive data types:

## Numbers

In order to reduce diversity of data types, we introduce only one data
type per format.

### Integers

We assume that maximum input while testing an algorithm would be
10^18 but the calculation can involve multiplication so maximum
value can be 10^36. There is only one data type called `integer`
which is 128-bit wide and stores signed numbers.

#### Boolean Operations

Integers would also support bitwise boolean operations such as `and`,
`or`, `xor`, `not` by using words themselves in lowecase as the operator
name.

### Floating Point

We would also need floating point numbers, we call this data type
`float` and it would store floating point numbers in the IEEE format.
This would correspond to a `long double` in C.

### Arithmetic Operations

Arithmetic operations can be done by using their respective symbols, `+`
for addition, `-` for subtraction, `*` for multiplication and `/` for
division.

| **Operator**  | **Note**             |
| :------------ | :------------------- |
| `+`,`-`       | Unary Operators      |
| `*`,`/`,`mod` | Multiplicative Group |
| `+`,`-`       | Additive Group       |

## Boolean

We call this data type `bool` that stores only `true` or `false` values.

#### Boolean Operations

This data type would also support boolean operations such as `and`,
`or`, `xor`, `not` by using words themselves in lowecase as the operator
name.

## Characters

We call this data type `char` which stores UTF-8 8-bit wide characters,
capable of supporting most languages.

## Arrays

Fixed-size arrays could be declared by appending size in square brackets
(`[SIZE]`) at the end of the data type itself. Note that this is
different from C/C++ where `[]` are appended at the end of the
identifier. For example, `int a[100]` in C/C++ would be `integer[100]
a`. 2-D arrays could also be declared similarly like `integer[100][100]
b`.

## Macro Syntax for Data Types

### Declaration

![9f99a0beab502676ae2448ded3b6d103](https://user-images.githubusercontent.com/30972152/102685426-767be480-4206-11eb-96f6-f94fee2d1cbe.png)

### Assignment

![188ac220c4fca3907b6a836c3d06d8ba](https://user-images.githubusercontent.com/30972152/102685440-901d2c00-4206-11eb-9309-5dd5b1103c0e.png)

# Control Statements

The control statements could be used to make decisions.

## if-then

``` 
    if(x > 0) {
        // Code block enclosed in curly braces
        x = 3;
    }
```

The `if` command is followed by parentheses, which contain the
comparison that the if keyword tests. The comparison should result in a
`bool` output. The statements that follow if the comparison is true are
enclosed in the curly braces. It can be referred to as a *code block*.

### Macro Syntax

![135809da1dbbfc5eda16fe9986c606fa](https://user-images.githubusercontent.com/30972152/102685452-af1bbe00-4206-11eb-977d-47de8db623a1.png)

## if-then-else

We introduce the `else` keyword for this. The `else` keyword is a
second, optional part of an `if` cluster of statements. It groups
together statements that are to be executed when the condition that `if`
tests for isn’t true.

``` 
    if(x > 0) {
        // Code block enclosed in curly braces
        x = 3;
    } else {
        x = -3;
    }
```

### Macro Syntax

![2c6521ec384945ad057151ec8082d2d6](https://user-images.githubusercontent.com/30972152/102686981-91078b00-4211-11eb-9676-44e4f0d62054.png)


### Ternary Operator

Similar, to the if-then-else there is an inline alternative called the
*Ternary Operator*. It is of the form `condition ? option1 :option2`
where the result of the operator is `option1` if the condition is true
and `option2` otherwise.

## Loops

A loop repeats a code block certain number of times or until a condition
is true.

### for-loop

The `for`-loop is generally used for repeating a code several times in
conjunction with a counter. The `for` keyword defines a starting
condition, an ending condition, and the statement that is run on while
the loop is being executed over and over.

``` 
    for(starting; while_true; do_this)
        statement;
```

#### Macro Syntax

![63b2d7d797955bf8d87dcfa51b84057d](https://user-images.githubusercontent.com/30972152/102685460-c9ee3280-4206-11eb-853c-8c6b1976dd53.png)

### while-loop

Similar to the `for`-loop, the `while`-loop also repeats a block of code
several times. However, it only comes with one conditional statement

``` 
    while(condition)
        statement;
```

#### Macro Syntax

![47800ae3be85a80bef78c210f932713f](https://user-images.githubusercontent.com/30972152/102686948-48e86880-4211-11eb-9e36-c576121f2d42.png)

# Functions

## Declaration

A function can be declared by specifying the return type, the name of
the function and arguments in parenthesis preceded by their respective
data types. A function declared without a return type returns nothing.

``` 
    integer foo(integer x, integer y) {
        // statements
        return x+y;
    }
```

#### Macro Syntax

![e3765f279d0328a74f70386936e140b7](https://user-images.githubusercontent.com/30972152/102685474-e68a6a80-4206-11eb-99be-1f98e1d43c77.png)

# Semantics

The program consists of two parts: *preamble* and *main*.

## Preamble

The preamble consists of headers that tell the compiler which library to
import (we assume that the miniC language has similar libraries as C)
and contain function definitions.

## Main

The main section is written inside the function `main()` which can
optionally take two arguments, first the count of command line arguments
and second the respective arguments. Its return type is `integer`, the
exit code of the program. When a program starts its execution it
executes the code inside the `main()` function.

## Checks

1.  The program must contain exactly one `main()` function which must
    return an exit code.

2.  A variable must be explicitly declared in the *same context* before
    being referred.

3.  Check for ambiguity such as the *Dangling Else*

4.  Anytime the index of an array is accessed the index must be of type
    `integer`.

5.  All the included header files must exist in the current system.

<!-- end list -->

1.  This programming language is designed to be similar to C but has a
    few modifications to make it more suitable for quick *problem
    solving* such as testing algorithms etc. In order to do this, there
    is less diversity of data types (like `int`, `unsigned int`,
    `int64_t` etc.) so that the programmer can focus on the logic of the
    code.
