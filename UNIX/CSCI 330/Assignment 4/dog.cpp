//*****************************************************
//
//	dog.cc
//	Assignment 4
//
//	Created by Reinaldo Moraga (z1864815)
//
//	Description: cat command improved
//
//*****************************************************

#include "func.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{	
	int opt;
	char optstring[] = "s:n:c:r:xb"; //declar command options
	int size = 1024; //default buffer size
	int bytes = -1; //default test bytes
	int shift = 0; //default caesar shift
	int rotate = 0; //default binary rotation
	int k;

	while ((opt = getopt(argc, argv, optstring)) != -1) { //when comman option is recognized, program starts here
		switch(opt) {
			case 's':
				size = atoi(optarg); //change buffer size
				break;
			case 'n':
				bytes = atoi(optarg); //change bytes read
				break;
			case 'c':
				shift = atoi(optarg); //change caesar shift
				for (int m = optind; m < argc; m++) { //loops through each input file
					k = open(argv[m], O_RDONLY); //opens file
					if (k < 0) { //ERROR
						cout << "File could not be opened.\n";
						perror("open");
						return 1;
					} else {
						cipher(k, shift, size, bytes, argv[m]);	 //call cipher function			
						close(k); //close file
					}
				}
				return 0;
			case 'r':
				rotate = atoi(optarg); //change binary rotation
				for (int m = optind; m < argc; m++) {
					k = open(argv[m], O_RDONLY);
					if (k < 0) {
						cout << "File could not be opened.\n";
						perror("open");
						return 1;
					} else {
						rotation(k, rotate, size, bytes, argv[m]); //call rotation function				
						close(k);
					}
				}
				return 0;
			case 'x':
				break;
			case 'b':
				break;
		}

	}

	// IF NO COMMAND OPTIONS RECOGNIZED || NO SHIFTING OPTIONS CALLED
	int f;
	int i;
	for (i = optind; i < argc; i++) { //loop through input files
		f = open(argv[i], O_RDONLY);
		if (f < 0) {
			cout << "File could not be opened.\n" << endl;
			perror("open");
			return 1;
		} else {
			cat(f, size, bytes, argv[i]); //call cat function
			close(f);
		}
	}
	return 0;
}
