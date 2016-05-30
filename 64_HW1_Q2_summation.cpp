/* A summation seperate file associated with the execve program used in the Q2

SJSU ID: 010767354
Name : Aaksh Shah
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  // for getpid() and sleep() //

int main() 
{
    
	int sum=0, i;  
	printf("\n\t\tUnique Process ID of Child Process ::%d\n\n", getpid());
	sleep(2);  // Making a halt for 2 Seconds //    

	for(i=1;i<=5;i++) 
	{
     		printf("The argument number %d in the summation :: %d\n", i, i);   
		fflush(stdout);  // Clear the buffer space //
		sum=sum+i;
	}
	printf("\t\t\nThe total summation :: %d\n", sum);
 
	exit(0);
}
