#include<stdio.h>
#include<unistd.h>

int main() {
	int p = fork();
	if (p == 0) {
		// child
		printf("\nPID of child is: %d", getpid());
	}
	else if (p == -1) {
		// error
		printf("\nUnable to create child process!");
	}
	else {
		printf("\nPID of parent is: %d", getpid());
	}
}
