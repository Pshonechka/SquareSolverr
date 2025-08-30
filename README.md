
[![Typing SVG](https://readme-typing-svg.herokuapp.com?color=%2336BCF7&lines=Program+solves+quadratic+equations)](https://git.io/typing-svg)

## Structure of project
```
square-solver/
├── documentation/              # in Doxygen
├── headers/                    # Header files
│   ├── CompareFunctions.h
│   ├── InputFunctions.h
│   ├── PrintFunctions.h
│   ├── SolverFunctions.h
│   ├── structs.h
│   └── TestFunctions.h
├── main.cpp
├── Makefile                    # Makefile for build
├── README.md                   # This file
├── src/
│   ├── CompareFunctions.cpp
│   ├── InputFunctions.cpp
│   ├── main_test.cpp
│   ├── PrintFunctions.cpp
│   ├── SolverFunctions.cpp
│   └── TestFunctions.cpp
└── tests/
    └── test.txt          # Test data
```

## Mathematical formulas
$ ax^2 + bx + c = 0 $

$ D=b^2 - 4ac $

$ x_{1,2} =\frac{ - b\pm \sqrt(D)} {2a}$

## Unit Tests
One test in each line
The first three numbers in line are the coefficients a, b, c, then the number of roots and roots x1, x2 (if there are any)


># Cases
>Zero roots
>One root
>Two roots
>Infinity roots



![POLTORASHKA](d6f37d55-b544-4970-a52a-3dca0acc884b.jpg)
