#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

int main()
{
 int server_fd, new_socket;
 struct sockaddr_in address;
 int addrlen=sizeof(address);
 char buf[1024]={0};

 srv_fd=socket(AF_INET,SOCK_STREAM,0);

 address.sin_family= AF_INET;
 address.sin_addr.s_addr=INADDR_ANY;
 address.sin_port= htons(8080);

 bind(server_fd,(struct sockaddr *)&address, sizeof(address));
 listen(server_fd, 3);
 
 new_socket =accept(server_fd,(struct sockaddr *)&address, (socklen_t*)&addrlen);

 while(int i=0;i<10;i++)
 {
  char msg=read(new_socket,buf,1024);
  if(msg!='\0')
	  printf("Message is:%s\n",buf);
  else
	  break;
 }

 close(new_socket);
 close(server_fd);
}
