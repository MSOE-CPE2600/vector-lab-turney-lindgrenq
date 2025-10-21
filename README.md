# Vector Calculator
Allows the user to create and store 3d vectors and do various calculations with them. Vector lists can be loaded in or saved in a .csv format.
## How to build
### Makefile
Enter `make` into your command line and the makefile provided will build for you.
### Manual compile
Enter `gcc -o veclab veclab.c vecmath.c -Wall` into your command line. You may include `-g` if you would like to use gdb as well.
## How to run
Enter `./veclab` into your commmand line to run the progam once built. There are not any supported command line arguments
## Supported commands
### Operations supported
- add: +
- subtract: -
- scaler: *
- cross product: x
- dot product: .
### Commands
- quit: quits program
- list: lists all vectors
- clear: clears all saved vectors
- vector name: prints vector info
### New vector
- name = x y: sets vector with z=0 and given x and y
- name = x y z: sets vector with given x y and z
### File IO
- load filename: clears vectors and loads vectors from .csv file
- save filename: saves vector list as a .csv file
## Dynamic Memory
This program uses dynamic memory to store the list of vectors. When the program starts, there is enough memory allocated to store five vectors, and a counter of the vectors stored is initialized to zero. Before every time a vector is added to the list, the counted is checked, and if the couter is a multiple of the default size, more memory is allocated to the array. This reallocation just allocates whatever the default size is on top of the already allocated memory. If needed, this default size can be adjusted at the top of `veclab.c` by chagning the five in `#define DEFAULT_SIZE 5` to any int.