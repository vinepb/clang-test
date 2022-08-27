# clang-test

Template project to explore the funcionalities of clang, clang-format, make, cmocka, and gdb.

### Project structure

```
- main.c
- src
  - foo.c
  - bar.c
- include
  - foo.h
  - bar.h
- tests
  - foo_test.c
  - bar_test.c
```

### Usage instructions

The first thing one needs to do is specify the compiler and cmocka lib and include paths in the `Makefile`:
```
CC=path/to/compiler
CMOCKA_INC=path/to/cmocka/include
CMOCKA_LIB=path/to/cmocka/lib
```
