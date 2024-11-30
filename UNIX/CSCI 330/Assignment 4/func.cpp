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

void rotation(int f, int rotate, int size, int b, char* s)
{
	char buf[size]; //declare bufffer and buffer size is passed by argument
	int l;
	int nresult; //number result
	int lresult; //letter result
	int i = 0;
	while ((l = read(f, buf, sizeof(buf)))) { //open file
		while (i < l - 1) {
			if (0 <= buf[i] && buf[i] <= 9) { //if number (0-9) is in buf, convert to binary and rotate
				nresult = (buf[i] + 48) + rotate;
				buf[i] = nresult;
				i++;
			} else {
				lresult = int(buf[i]) + rotate; //else, character in buf is converted to binary and rotated
				buf[i] = lresult;
				i++;
			}
		}
		if (b == -1) {
			write(1, buf, l); //if default bytes, then write from l
			cout << endl;
		} else {
			write(1, buf, b); //if bytes are changed, then write that number
			cout << endl;
		}	
	}
	return;	
}

void cipher(int f, int shift, int size, int b, char* s)
{
	char buf[size];
	int l;
	char cresult;
	char lresult;
	int i = 0;
	while ((l = read(f, buf, sizeof(buf)))) {
		while (i < l - 1) {
			if (isupper(buf[i])) {
				cresult = char(int(buf[i] + shift - 97) % 26 +97);
				buf[i] = cresult;
				i++;
			} else {
				if (int(buf[i]) == 32) {
					i++;	
				} else {
					lresult = char(int(buf[i] + shift - 97) % 26 + 97);
					buf[i] = lresult;
					i++;
				}
			}
		}
		if (b == -1) {
			write(1, buf, l);
		} else {
			write(1, buf, b); 
			cout << endl;
		}
	}
	return;	
}

void cat(int f, int size, int b, char *s)
{
	char buf[size];
	int n;

	while ((n = read(f, buf, sizeof(buf))) > 0) {
		if (b == -1) {
			write(1, buf, n);
		} else {
			write(1, buf, b); 
			cout << endl;
		}
	}
	return;	
}
