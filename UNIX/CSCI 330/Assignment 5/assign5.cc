//********************************
// 
// Pipes Assignment
//
// Reinaldo Moraga (z1864815)
//
// ******************************

#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


using namespace std;

int main()
{

	int rs;
	int pipefd[2];

	rs = pipe(pipefd);
	if (rs < 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	rs = fork();

	if (rs < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (rs == 0) {
		close(pipefd[1]);
		close(0);
		dup(pipefd[0]);
		close(pipefd[0]);
		
		rs = execl("/usr/bin/wc", "wc", (char *) NULL);
		if (rs < 0) {
			perror("execl peh");
			exit(EXIT_FAILURE);
		}
	} else {
		close(pipefd[0]);
		close(1);
		dup(pipefd[1]);
		close(pipefd[1]);

		rs = execl("/bin/ls", "ls", (char *) NULL);
		if (rs < 0) {
			perror("execl");
			exit(EXIT_FAILURE);
		}
	}


	return 0;
}


