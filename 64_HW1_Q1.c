/*
A concurrent program the starts 3 processes

SJSU ID: 010767354
Name : Aaksh Shah
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>  // for pid_t //
#include <sys/wait.h>  // for wait //
#include <unistd.h>  // for fork() //

main()
{
	pid_t pid_value;  //Process ID
	int i;  // For looping purpose
	
	printf("\n\t\t A Concurrent program that starts three processes.\n");
	printf("The original unique parent Process ID :: %d \n", getppid());	

	for(i=1; i<=3; i++)  // For starting 3 processes
	{
		pid_t pid_value=fork(); // Created new processes
		sleep(2);  // Gave a halt of 2 seconds

		if(pid_value==0)  // child process created successfully
		{
			printf("The new unique child %d process ID :: %d \n", i, getpid());
			fflush(stdout);  //Flush the Buffer
			exit(0);  // Terminate the program
		}
		else if(pid_value<0) // Condition for child is not created successfully
		{
			printf("Child process didn't created and Fork failed");			
			exit(-1);  // terminate the program
		}
	}	
	return 0;
}
