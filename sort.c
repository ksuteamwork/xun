#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void com (int arr[], int data[], int start, int end, int index, int r){
   int j,i;
     if(index == r){
    for( j = 0; j < r; j++)
       printf("%d ",data[j]);
       printf("\n");

   }
    for( i = start; i <= end && end-i+1 >= r-index; i++){
      data[index] = arr[i];
       com(arr,data,i+1,end,index+1,r);
    }

  }

void print(int arr[], int n, int r){
  int data[r];
  com(arr,data,0,n-1,0,r);
 }

int main(){
int arr[]={2,5,31,1,7,0,6,8,4};
int r,n;
  r = 8;
   n = sizeof(arr)/sizeof(int);
    print(arr,n,r);
}
