# PI-Calculator
Calculating PI with the help of probability and multiprocessing.

NOTICE: This program only works on linux.
After compiling the main.c file, to run main, in the first argument pass the number of processes which are going to help to calculate the PI number and in the second argument pass the number of dots we are going to try.
It is obvious that the number of processes helps to speed up the program and the number of dots helps accuracy.
put the  ```-lm``` beacuse of ```math.h``` is used in linux.

For example:

```
gcc main.c -o main -lm
./main 20 10000
```
Which means I compiled the program and the runable file is ```main``` and I'm going to calculate the PI number with the help of 20 processes and 10000 dots.
