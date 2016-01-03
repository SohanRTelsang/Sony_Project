#include <stdio.h>    
#include <unistd.h>   
#include <signal.h>
struct sigaction sa;
void handler_function()
{
	printf("i'm in handler function\n");
	sa.sa_handler=SIG_IGN;
	sigaction(SIGINT,&sa,0);
}

int main()
{
	int i = 1;
	sa.sa_flags=0;
	sa.sa_handler=handler_function;
	sigaction(SIGINT,&sa,0);
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
