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
  struct sockaddr_in addr;
  char buffer[1024];
  char var[]="GET /1.txt HTTP/1.1\r\n"
             "User-Agent:Wget/1.15.1(linux-gnu)\r\n"
             "Accept:*/*\r\n"
             "Accept-Encoding: identity\r\n"
             "Host: 192.168.128.65\r\n"
             "Connection: Keep-Alive\r\n\r\n";
 // char buf[1024];

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
        // memset(buffer,0,sizeof(buffer));
          sprintf(buffer,"%s",var);
          printf("%s\n",buffer);

           write(s,buffer,sizeof(buffer));
           bzero(buffer, sizeof(buffer));
         recv(s, buffer, sizeof(buffer), 0);
         printf("%s\n",buffer);

        // FILE*fp = fopen("1.txt","r");
        // while(fgets(buffer,1024,fp)!=NULL){
        // printf("%s\n",buffer);}

        //while(1){
          //  bzero(buffer, sizeof(buffer));
           // sprintf(buffer,"%s",var);
           // printf("%s\n",buffer);
            //read(STDIN_FILENO,buffer,sizeof(buffer));
          // sendto(s,buffer,len,0,(struct sockaddr*)&addr,addr_len);
           //len = recvfrom(s,buffer,sizeof(buffer),0,(struct sockaddr*)&addr,&addr_len);
          // printf("receive: %s",buffer);
        // if(send(s,buffer,sizeof(buffer),0) < 0){
          // perror("send");
          // exit(1);
          // }

         // fclose(fp);

       // }
       close(s);
  }

