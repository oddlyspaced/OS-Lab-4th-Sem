#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#define BUFFER_SIZE 1

int main(int argc, char *argv[2]) {
	if (argc < 2) {
		printf("\nEnter filename!");
		exit(-1);
	}
	char buffer[BUFFER_SIZE];
	int s_read = open(argv[1], O_RDONLY);
	if (s_read < 0) {
		printf("\nUnable to open source file!");
		exit(-1);
	}
	while (1) {
		ssize_t inp = read(s_read, &buffer, BUFFER_SIZE);
		if (inp > 0) {
			printf("%c", buffer[0]);
		}
		else {
			break;
		}
	}
	close(s_read);
	exit(0);
}
