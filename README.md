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
   
## my-sed
The my-sed program searches the given document(s) for a given term and replaces that phrase with another given term. If no file is specified, the user can input their own text to be searched. both outputs are sent to stdout. The program will only replace the first instance of the given word to find. The program will print the contents of the file to stdout. Arguements for find and replace are required for program to run.
  ### Running Program:
    $ ./my-sed <find> <replace> <file(s)>
    Program will replace <find> with <replace> in one or more files.
    
    $ ./my-sed <find> <replace>
    Program will read from stdin and replace <find> with <replace> in the given string.
    
    $ ./my-sed <find> "" <file(s)>
    Program will find <find> in one or multiple files and remove it. The argument <file(s)> is optional, 
    if there are no specified files it will remove the word from the string read from stdin.
    
    $ ./my-sed <find> <file>
    Program will replace <find> with the given file in the string read from stdin.
    
    $ ./my-sed <file1> <file2> <file3>
    Program will replace <file1> with <file2> in <file3>
    
    $ ./my-sed <file1> <file2>
    Program will replace <file1> with <file2> in the string read from stdin.
    
## my-uniq
The program my-uniq will find adjacent duplicate lines from a specified file, removes them, writes it to an output file, and writes the line to stdout.
  ### Running Program:
    $ ./my-uniq <file1> <file2>
    Program will remove adjacent duplicate lines from both files and write them to stdout. There can be many files.
    
    $ ./my-uniq
    Program will take user input to parse.
    
    
