#include <stdio.h>    
#include <unistd.h>   
#include <signal.h>
void handler_function()
{
	printf("i'm in handler function\n");
}

int main()
{
 	int i = 1;	
	signal(SIGINT,handler_function);
	while(i)
	{
		printf("hello\n");
		sleep(1);
		i++;	
	}
	return 0;

}

/*Execution Procedure:

yash@yash-HP-Pavilion-dv6-Notebook-PC:~$ gcc week3_pgm2b.c
yash@yash-HP-Pavilion-dv6-Notebook-PC:~$ ./a.out
hello
hello
hello
hello (in infinite loop)
Now Press CTRL+C => Interrupt Key
^Ci'm in handler function
hello
hello
Press CTRL+C again, program ignores the signal
To terminate, press CTRL+Z

*/
