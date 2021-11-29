#include <unistd.h>
#include <stdlib.h>


using namespace std;
int main(int argc, char * argv[]){
    int fd[2];
     pipe(fd);
    pid_t pid = fork();
    if(pid == 0){
        //hijo
     
         close(fd[1]);
        dup2(fd[0],0);
        close(fd[0]);
        execlp(argv[3],argv[3],argv[4],0);
        
    }
    else{
        //padre
       close(fd[0]); 
        dup2(fd[1],1);
        close(fd[1]); 
        execlp(argv[1],argv[1],argv[2],0);


    }
    return 0;
}
