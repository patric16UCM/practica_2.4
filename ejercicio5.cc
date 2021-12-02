#include <sys/types.h>
#include<sys/stat.h>
#include<sys/select.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
 int max(int a,int b){
     if(a>b)
     return a;
     else return b;
 }
int main(int argc, char * argv[]){
char * buffer[512];
char * home = getenv("HOME");
char * tuberia1 = strcat(home,"/tuberia1");
mkfifo(tuberia1,O_RDONLY);
char * tuberia2 = strcat(home,"/tuberia2");
mkfifo(tuberia2,O_RDONLY);

int tub1 = open(tuberia1, O_NONBLOCK | O_WRONLY);
int tub2 = open(tuberia2,O_NONBLOCK | O_WRONLY );

fd_set *conjunto;
FD_ZERO(conjunto);
FD_SET(tub1,conjunto);
FD_SET(tub2,conjunto);
int maximo = max(tub1,tub2);
int cambios;
int pipeusado;
cambios = select(maximo,conjunto,NULL,NULL, NULL);
if(cambios > 0){
   if(tub1 !=-1 && FD_ISSET(tub1,conjunto) == 1 ){
      read(tub1,buffer,512);
      printf("tuberia desde la que se lee: tuberia1, datos leidos: %s \n" ,buffer);
   }
    else if(tub2 !=-1 && FD_ISSET(tub2,conjunto) == 1){
        read(tub2,buffer,512);
        printf("tuberia desde la que se lee: tuberia2, datos leidos: %s \n" ,buffer);
   }
}


close(tub1);
close(tub2);
    return 1;
}
