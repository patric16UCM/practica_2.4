#include <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int mensajes=0;
int main(int argc, char * argv[]){
char * home = getenv("HOME");
char * tuberia = strcat(home,"/fichero");
mkfifo(tuberia,O_RDONLY);
int fd=open(tuberia,O_WRONLY);
write(fd,argv[1],strlen(argv[1]));
close(fd);

    return 1;
}
