#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main() {
	char s_file[20], d_file[20];
	printf("\nEnter source filename: ");
	scanf("%s", s_file);

	int s_desc = open(s_file, O_RDONLY);
	if (s_desc < 0) {
		// unable to open source file
		printf("\nUnable to open source file!");
		return 1;
	}
	printf("\nEnter destination filename: ");
	scanf("%s", d_file);
	int d_desc = open(d_file, O_WRONLY | O_CREAT, 0644);
	if (d_desc < 0) {
		// unable to create new file
		printf("\nUnable to open destination file!");
		return 1;
	}
	char buffer[1024];
	while (1) {
		ssize_t inp = read(s_desc, &buffer, 1024);
		if (inp > 0) {
			write(d_desc, &buffer, inp);
		}
		else {
			break;
		}
	}
	close(s_desc);
	close(d_desc);
	printf("\nFile copy successful");
	return 0;
}
