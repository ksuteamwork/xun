#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
void smalltobig(char *src, int len){
  int a,b,c;
    for(a = 0 ; a < len ; a++ ){
     for(b = 0 ; b< len-a-1; b++){
       if(src[b] > src[b+1]){
          c = src[b];
          src[b]=src[b+1];
    	  src[b+1]=c;
        }
      }
    }
}
void bigtosmall(char *src, int len){
  int a,b,c;
    for(a = 0 ; a < len ; a++ ){
     for(b = 0 ; b< len-a-1; b++){
       if(src[b] < src[b+1]){
          c = src[b];
          src[b]=src[b+1];
    	  src[b+1]=c;
        }
      }
    }
}

int main(){
char a[5];
char buffer[10];
//int fd, size;

    //fd = open("/home/text/ab.txt", O_RDONLY);
     /*if(fd){
       printf("true\n");
     }else{
       printf("false\n");
          }*/
   // size = read(fd, buffer, sizeof(buffer));
    //close(fd);
    FILE *fp = fopen("ab.txt","r");
     FILE *fd = fopen("aa.txt","w");
    // printf("how many number = %d\n",sizeof(buffer)/4);

int b,i=0;
int e;
 /* for(i=0;i<5;i++){
      a[i]='\0';

    }*/
   memset(a,0,sizeof(a));
 // if(fp){

     while(fgets(buffer , 10, fp)!= NULL)
           {

              e = atoi(buffer);
              a[i] = e ;
              i++;
              printf("%d\n",e);
             // fprintf(fd,"%d\n",e);
            }
    // fprintf(fd,"%d\n",a[i]);
//     memset(a,0,5);

       //a[5]= e;
       //fscanf(fp,"%s",&a[5]);
    /* for(e = 0 ; e < 5 ; e++){
       printf("%d\n",a[e]);
    }*/
    printf("how many number = %d\n",sizeof(a));
    printf("select bigtosmall or smalltobig\n");
    printf("Enter 1 or 2\n");
    scanf("%d", &b);
     if(b==1)
     {
        bigtosmall(a,5);
      for(i = 0 ;i < 5; i++)
        {
         // fgets(a,5,fp);
         // e = atoi(buffer);
         // a[i]= e;
         //   e = a[i];
         // printf("%d\n",e);
          fprintf(fd,"%d\n",a[i]);
          printf("%d\n", a[i]);
        }
        // printf("%s\n",buffer);
        // fprintf(fd,"%d",a[i]);
      }
   // fprintf(fd,"%d\n",a[i]);
     if(b==2)
     {
       smalltobig(a,5);
      for(i = 0 ;i < 5; i++)
        {
          //fgets(a,5,fp);
          // e = atoi(buffer);
          //printf("%d\n",e);
         // a[i]=e;
          // e = a[i] ;
          fprintf(fd,"%d\n",a[i]);
          printf("%d\n",a[i]);
         // itoa(a[i],a,2);
       // printf("%s\n",buffer);
       // fprintf(fd,"%d\n",a[i]);
       }
     }

    //fd = open("/home/text/ab.txt", O_WRONLY);
    //write(fd, buffer, sizeof(a));
    //close(fd);
  // fprintf(fd,"%s",a);

// FILE *fd = fopen("ab.txt","w");
   fclose(fd);
   fclose(fp);

 //  }
    }

