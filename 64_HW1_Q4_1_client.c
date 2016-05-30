/* TCP Client Side code 

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

	int sockds, newsockds;
	socklen_t ad_size;
	char msg[512];
	
	sockds= socket(PF_INET, SOCK_STREAM, 0);
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
	connect(sockds, (struct sockaddr *) &sockinfo, ad_size);

	recv(sockds, msg, 512, 0);

	printf("\n\tThe data received is : %s\n", msg);

	return 0;
}
