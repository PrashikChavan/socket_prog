#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char msg[1024];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
     printf("invalid address\n");
     return 1;
    }

    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
     printf("connection failed");
     return 1;
    }
    for(int i=0;i<10;i++)
    {
     scanf("%s",msg);
     send(sock, msg, strlen(msg), 0);
    }
    close(sock);
    return 0;
}
