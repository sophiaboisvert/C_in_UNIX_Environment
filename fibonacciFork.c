#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void err_sys(const char* c)
{
	perror(c);
	exit(1);
}

void fibonacciFunction(int x0, int x1, int num)
{
	if(num == 0)
		return;
	printf(" %d", x0+x1);
	fibonacciFunction(x1, x0+x1, num-1);
}


int main()
{

	int num = -1;
	
	while(num <= 0)
	{
	printf("Enter the number of members in the sequence: ");
	scanf("%d", &num);
	}
	
	pid_t pid = fork();
	if(pid < 0)
	{
		err_sys("Error creating child proccess\n");
	}
	else if(pid == 0)
	{
		if(num == 1)
			printf("0\n");
		else
		{
			printf("0 1");
			fibonacciFunction(0, 1, num-2);	
			printf("\n");
		}
	}
	else
	{
	wait();
	printf("The child and parent process ids are: %d and %d.\n", pid, getpid()); 
	}
	return 0;
}
