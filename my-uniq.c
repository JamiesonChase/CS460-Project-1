/*Group: Antonio Maniscalco, Chase Jamieson, Josh Sedig
* CS460 Assignment_1
* Instructor: Dr. Xuechen Zhang
* my-uniq.c file
* */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void parse(FILE *fp);

int main(int argc, char **argv) {
    FILE *fp;
    int i;
    if (argc == 1) {
        parse(stdin); //read through stdin
        return 1;
    }
    for (i = 1;i<argc;i++) { //iterate through each command line argument
     if ((fp = fopen(argv[i],"r")) != NULL) {
        parse(fp);
        fclose(fp);
     }
     else { //error if file cannot be opened
        printf("my-uniq: cannot open file\n");
        exit(1);
    }
  }
}
//parse through for adjecent duplicate lines
void parse(FILE *fp) {
    char current[500];
    char next[500];

    while(fgets(next, 500, fp) != NULL) {
        if (strcmp(current, next) != 0) {
            printf("%s",next); //if different
            strcpy(current,next); //current line checking updated
        }

    }
  current[0]='\0'; //reset current so doens't filter next files
}