/* TCP Server Side code 

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

	int sockds, newsockds, listening;
	socklen_t ad_size;
	char msg[512];
	
	sockds= socket(PF_INET, SOCK_STREAM, 0);
	if(sockds== -1)
	{
		printf("\n\t\tCreation of socket failed.\n");
		exit(1);
	}
	else
		printf("\n\tSocket function executed from server side for TCP.\n\n");
	
	struct sockaddr_in sockinfo;
	
	sockinfo.sin_family= AF_INET;
	sockinfo.sin_addr.s_addr= inet_addr("127.0.0.1");
	sockinfo.sin_port= htons(7000);
	
	memset(sockinfo.sin_zero, '\0', sizeof sockinfo.sin_zero);
	
	bind(sockds, (struct sockaddr *) &sockinfo, sizeof(sockinfo));
	
	listening= listen(sockds, 3);
	
	if(listening== 0)
		printf("\tListening...\n");
	else
		printf("\tError in listening.\n");
	
	struct sockaddr_storage sockstor;
	ad_size= sizeof sockstor;
	newsockds= accept(sockds, (struct sockaddr *) &sockstor, &ad_size);
	
	if(sockds>0)
		printf("\n\n\tRequest accepted\n\n");
	
	strcpy(msg, "\t1st Packet.\n\n");
	
	send(newsockds, msg, 30, 0);
	
	return 0;
}
	
