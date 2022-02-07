# CS460Project1
### Group Members: Antonio Maniscalco, Chase Jamieson, Josh Sedig
### Group ID: 21
### Instructor: Dr. Xuechen Zhang

## Introduction
This project implements simple versions of the Unix utilities "cat", "sed", and "uniq" developed in C. To compile all the files, on the command line simply type "make". To remove all object files type "make clean".

## my-cat
Just as the utility "cat" my-cat.c reads the contents of a file and writes them to stdout. When running the program you may specify many files but at the very least one. If no file is specified, the program will imediately exit. If the file specified does not exist, the program will print an error message and exit the program.
  ### Running Program:
    $ ./my-cat <file(s) name>
    
