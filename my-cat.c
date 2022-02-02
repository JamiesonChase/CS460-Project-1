/*Group: Antonio Maniscalco, Chase Jamieson, Josh Sedig
* CS460 Project 1
* Instructor: Dr. Xuechen Zhang
* my-cat.c file */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

static void readContents(int fd);

int main(int argc, char *argv[]) {

	if(argc < 2) {
		printf("Specify a file\n");
		exit(1);
	}

	int fd;

	//read through files specified in command line
	for(int fileNum = 1; fileNum < argc; fileNum++) {
		//attempt to open file
		
		if((fd = open(argv[fileNum], O_RDONLY)) < 0) {
			//fprintf(stderr, "%s\n", strerror(errno));
			printf("\nmy-cat: cannot open file\n");
			exit(1);
		}

		readContents(fd);
	}
	
	return(0);
}

//function to print contents of file
static void readContents(int fd) {
	int bytesRead;
	char buff[1];	

	//read character by character in file
	while((bytesRead = read(fd, &buff, 1)) > 0) {

		//write to stdout and check for errors
		if((write(1, &buff, 1)) < 0) {
			fprintf(stderr, "%s\n", strerror(errno));
			close(fd);
			exit(1);
		}
	}

	//if read returns negative we have an error
	if(bytesRead < 0) {
			fprintf(stderr, "%s\n", strerror(errno));
			close(fd);
			exit(1);
	}

	//close file descriptor
	if(close(fd) < 0) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(1);
	}
}
