/*Group: Antonio Maniscalco, Chase Jamieson, Josh Sedig
* CS460 Assignment 1
* Instructor: Dr. Xuechen Zhang
* my-sed.c file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFF_SIZE 2048

static void readContents(const char *path, const char *find, const char *replace);
static int replaceContent(char *str, const char *find, const char *replace);

int main(int argc, char *argv[]) {
  //printf("%d\n", argc);

  if(argc < 3) {
    printf("my-sed: [find_term] [replace_Term] [file ...] \n");
    exit(1);
  }


  //if no source files specified, take manual input
  if(argc == 3){
    readContents(NULL, argv[1], argv[2]);
  }


  //read through files specified in command line
  for(int fileNum = 3; fileNum < argc; fileNum++) {
    int fd;
    if((fd = open(argv[fileNum], O_RDONLY)) < 0) {
      printf("\nmy-sed: cannot open file\n");
      exit(1);
    }

    readContents(argv[fileNum], argv[1], argv[2]);
    printf("\n");
  }

  return(0);
}




//function to read through the entire file
static void readContents(const char *filename, const char *find, const char *replace) {
  //catches immediate contradictions
  if(strcmp(find, replace) == 0){ printf("my-sed: Identical words, no change.\n"); return; }

  int hitFlag = 0;
  char buffer[BUFF_SIZE];

  //if filename is not specified, manual input
  if(!filename){
    printf("No file specified. Manual text input: \n");
    fgets(buffer, BUFF_SIZE, stdin);
    printf("\nIN : %s", buffer);
    replaceContent(buffer, find, replace);
    printf("OUT: %s\n", buffer);
    return;
  }

  //Grab 1 line of the file at a time and process it,
  //if there is a replacement, stop processing and just copy the rest
  FILE *ptr;
  ptr = fopen(filename, "r");

  while(fgets(buffer, BUFF_SIZE, ptr) != NULL){
    if(!hitFlag){
      if(replaceContent(buffer, find, replace)){hitFlag = 1;}
    }
    printf("%s", buffer);
  }
  fclose(ptr);
}


//takes a string and replaces X with Y, returns 1 if replacement occurs, else 0
static int replaceContent(char *str, const char *find, const char *replace){
  char *currentPosition;
  char storage[BUFF_SIZE];
  int foundPosition = 0;
  int foundLength;
  foundLength = strlen(find);

  //if word X doesnt exist in string, return 0
  if((currentPosition = strstr(str, find)) == NULL){return 0;}

  //cut string, replace word X with word Y, paste rest of string back on
  strcpy(storage, str);
  foundPosition = currentPosition - str;

  str[foundPosition] = '\0';
  strcat(str, replace);
  strcat(str, storage + foundPosition + foundLength);
  return 1;
}
