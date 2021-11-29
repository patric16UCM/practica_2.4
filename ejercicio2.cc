#include <unistd.h>
#include <stdlib.h>


using namespace std;
int n_mensajes=0;
int main(int argc, char * argv[]){
    int p_h[2];
    int h_p[2];
    char *buffer[100];
    pipe (p_h);
    pipe (h_p);
    pid_t pid = fork();
    if(pid == 0){ //hijo
       //recibimos el mensaje, lo escribimos por la pantalla 
        read(h_p[], buffer,100);
         n_mensajes++;
        close(fd[1]);
        dup2(fd[0],0);
        close(fd[0]);
        if(n_mensajes==10){
            //usando write avisamos de que termine
            write(p_h[],'q', strlen(char)+1); 
        }

        //escribimos en la h_p una l
       write(h_p[],'l', strlen(char)+1); 
    }
    else{
        read(p_h[],buffer,100):
        if(buffer == 'q'){
            //se finaliza
            return 0;
        }
        else{
            //enviamos mensajito
             write(h_p[],buffer, strlen(buffer));
        }
        close(h_p[1]);
        dup2(h_p[0],0);
        close(h_p[0]);
        //escribimos en la p_h el mensaje recibido.
        

        close();//cerrramos los descriptores otra vez.
    }
    return 0;
}
