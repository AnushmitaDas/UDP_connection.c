#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include<arpa/inet.h>
#include<string.h>
int main()
{
       int sock,n,l;
       char buff[100],c[100];
       struct sockaddr_in reciever, sender;
       sock=socket(AF_INET,SOCK_DGRAM,0);
       if(sock<0)
               printf("error");
       else
                       printf("socket-%d", sock);
       reciever.sin_family=AF_INET;
       reciever.sin_port=htons(4242);
       reciever.sin_addr.s_addr=inet_addr("127.0.0.1");
       if (bind(sock, (struct sockaddr *)&reciever,
                   sizeof(struct sockaddr_in)) == -1)
               printf("bind error");
       sender.sin_family=AF_INET;
       sender.sin_port=htons(4200);
       sender.sin_addr.s_addr=inet_addr("127.0.0.1");
       l=sizeof(struct sockaddr_in);
       n=recvfrom(sock, buff, 100, 0,  (struct sockaddr *)&sender,&l);
        if(n<0)
                printf("recieve error");
       buff[n]='\0';
       printf("Client said-%s \n", buff);
       printf("enter the message from reciever");
       scanf("%s", c);
       sendto(sock, c, strlen(c), 0,  (struct sockaddr *)&sender,l);

}
 
