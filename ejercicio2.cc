#include <unistd.h>
#include <stdlib.h>


using namespace std;
int n_mensajes=0;
int main(int argc, char * argv[]){
    int p_h[2];
    int h_p[2];
    char *buffer[100];
    pipe (p_h); //escribe el padre y lee el hijo
    pipe (h_p);//escribe el hijo y lee el padre
    pid_t pid = fork();
    if(pid == 0){ //hijo
       //recibimos el mensaje, lo escribimos por la pantalla 
        close(fd[1]);
        n_mensajes++;
        dup2(p_h[0],0);
        read(p_h[0], buffer,100);
        close(p_h[0]);
         close();
        dup2(h_p[1],1);
        if(n_mensajes==10){
            //usando write avisamos de que termine
          
            write(h_p[1],'q', strlen(char)+1); 
        }
        else{
            write(h_p[],'l', strlen(char)+1); 
        }
   
       close();
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
