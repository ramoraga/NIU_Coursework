//*****************************************************
//
//	cat.cc
//	Assignment 3
//
//	Created by Reinaldo Moraga (z1864815)
//
//	Description: Implementation of cat command
//
//*****************************************************

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main(int argc, char *argv[])
{
	int fd;
	int n;
	for (int i = 1; i < argc; i++) { 	//loop created to open, read, & close each file entered
		fd = open(argv[i], O_RDONLY); 	//open file
		if (fd < 0) {
			perror("Invalid File");	//ERROR
			exit(1);
		}

		while (read(fd, &n, 1)) {	//read file
			write(STDOUT_FILENO, &n, 1);	//write bytes
		}
		close(fd); 			//close file
	}

	return 0;
}
