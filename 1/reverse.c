#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
int main()
{
	int file = open("myfile.txt",O_RDWR);
	lseek(file,0,SEEK_END);
	char da[1];
		while((lseek(file,-2,SEEK_CUR))>=0)
		{
		read(file,da,1);
		write(1,da,1);
		}
	if(close(file)<0)
		printf("Not");
	printf("\n");
	return 0;
}
