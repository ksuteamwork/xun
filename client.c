#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<strings.h>

#define PORT  80
#define SERVER_IP "192.168.128.65"

int main()
 {
  int s;
  int addr_len = sizeof(struct sockaddr_in);
  struct sockaddr_in addr;
  char buffer[256];

   if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0 ){
     perror("socket");
     exit(1);
   }

     bzero(&addr, sizeof(addr));
     addr.sin_family = AF_INET;
     addr.sin_port = htons(PORT);
     addr.sin_addr.s_addr = inet_addr(SERVER_IP);

      if(connect(s,(struct sockaddr*) &addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(1);
      }


         recv(s, buffer, sizeof(buffer), 0);
         printf("%s\n",buffer);

        while(1){
            bzero(buffer, sizeof(buffer));

            read(STDIN_FILENO,buffer,sizeof(buffer));
         if(send(s,buffer,sizeof(buffer),0) < 0){
           perror("send");
           exit(1);
           }

        }
  }

