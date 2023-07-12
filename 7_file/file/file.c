#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	
	int fd = 0;

	char str_write[4] = "test", str_read;

	if(-1 == (fd = open("test_file", O_RDWR))){
		printf("ERROR OPEN FILE\n");
		exit(1);
	}

	write(fd, str_write, sizeof(char)*4);

	for(int i = 0; i < strlen(str_write); i++){
		lseek(fd, i + 1, SEEK_SET);
		read(fd, str_read, sizeof(char));
		printf("%c",str_read);
	}

	close(fd);

	return 0;
}
