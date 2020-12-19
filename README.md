<h1 align="center">MiniC</h1>

  <p align="center">
    A simple toy language
    <br />
    <a href="https://github.com/ajainuary/minic-compiler/blob/main/docs.md"><strong>Explore the docs »</strong></a>
    <br />
    ·
    <a href="https://github.com/ajainuary/minic-compiler/issues">Report Bug</a>
    ·
    <a href="https://github.com/ajainuary/minic-compiler/issues">Request Feature</a>
  </p>

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#build-process">Build Process</li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

This project contains an LLVM Frontend for MiniC, a toy language similar to the C Programming language.

### Built With

* [ANTLR](https://www.antlr.org/)
* [LLVM](https://llvm.org/)


<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

#### ANTLR4

Follow the guide at [https://github.com/antlr/antlr4/blob/master/doc/getting-started.md](https://github.com/antlr/antlr4/blob/master/doc/getting-started.md)

#### ANTLR4-CPP Runtime

Follow the guide at [https://github.com/antlr/antlr4/tree/master/runtime/Cpp](https://github.com/antlr/antlr4/tree/master/runtime/Cpp)

#### LLVM Project

Get the source code and build LLVM by following the guide at [https://llvm.org/docs/GettingStarted.html#getting-the-source-code-and-building-llvm](https://llvm.org/docs/GettingStarted.html#getting-the-source-code-and-building-llvm)

### Build Process

1. Clone the repo
   ```sh
   git clone https://github.com/ajainuary/minic-compiler.git
   ```
2. Move to the source code directory
```sh
  cd src/
   ``` 
3. Compile the project 
```sh
   make
   ```

### Usage

In order to compile your miniC code simply run the executable with the source code file as the argument.

```sh
./minic <source-code>
```
A few sample programs to test could be found [here](sample-codes/)

<!-- LICENSE -->
## License

Distributed under the MIT License. See [`LICENSE`](license.md) for more information.

## Acknowledgements

This project was built as a part of the Compilers Course at IIIT, Hyderabad. I am grateful to Prof. Suresh Purini and the TAs for guiding me through the project.
