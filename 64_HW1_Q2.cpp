/* A program that uses "execve" to change the code a process executes 

SJSU ID: 010767354
Name : Aaksh Shah

*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>  // for pid_t //
#include <sys/wait.h>  // for wait //
#include <unistd.h>  // for fork() //


int main(int argc, char *argv[]) 
{
int pid_value; 	   
	printf("\n\t\tUnique Process Id of Parent Process :: %d \n\n", getpid());  // Printing the process ID //
	pid_value = fork();  // Creating new process
	
	if(pid_value==0)  // Condition for child process creation //	
	{
		printf("Chid process will now use EXECV to execute summation\n");        
		char *args[]={"64_HW1_Q2_summation","arg1","arg2",NULL};  // Gave Command line arguments //
		execv("64_HW1_Q2_summation", args);  // Calling of Execv function //       
	}
	else if(pid_value<0)  // Condtion for fork failure // 
	{       
		printf("\t\tSorry!! Fork Failed\n");    
	}
//wait(pid_value);
	return 0;
}
