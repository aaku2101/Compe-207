/* UDP Client Side code 

SJSU ID: 010767354
Name : Aaksh Shah
*/

#include<stdio.h>
#include<cstdlib>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{

	int sockds, count;
	socklen_t ad_size;
	char msg[512];
	
	sockds= socket(PF_INET, SOCK_DGRAM, 0);
	if(sockds== -1)
	{
		printf("\n\t\tCreation of socket failed.\n");
		exit(1);
	}
	else
		printf("\n\tSocket function executed from client side for TCP.\n");
	
	struct sockaddr_in sockinfo;
	
	sockinfo.sin_family= AF_INET;
	sockinfo.sin_addr.s_addr= inet_addr("127.0.0.1");
	sockinfo.sin_port= htons(7000);
	
	memset(sockinfo.sin_zero, '\0', sizeof sockinfo.sin_zero);
	
	ad_size= sizeof sockinfo;

//	{
		printf("\n\tClient, Please type your message to server: \n");
		fgets(msg, 512, stdin);
		printf("\n\tThe message is %s\n", msg);

		count= strlen(msg)+1;

		sendto(sockds, msg, count, 0, (struct sockaddr *) &sockinfo, ad_size);

		count= recvfrom(sockds, msg, 512, 0, NULL, NULL);

		//printf("\n\n\tMessage received from server side is : %s\n", msg);
//	}
	return 0;
}
