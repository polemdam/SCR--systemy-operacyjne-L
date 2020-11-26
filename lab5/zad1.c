#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 1000
int main(int argc, char* argv[]){
    int fd[2];
    if (pipe(fd) == -1) {
        return 1;
    }
    int pid = fork();
    if (pid != 0){
        close(fd[0]);
        const char* filename = argv[1];
        FILE *fptr;
        if((fptr = fopen(filename, "r")) == NULL){
            fprintf(stderr, "%s\n", "Error: opening file");
            return 1;
        }
        char buffer[BUFFER_SIZE];
        fgets(buffer, BUFFER_SIZE, fptr);
        printf("PARENT: %s", buffer);
        fclose(fptr);
        write(fd[1], buffer ,sizeof(char)*BUFFER_SIZE);
        close(fd[1]);   
    }
    if (pid == 0){
        close(fd[1]);
        char buffer[BUFFER_SIZE];
        read(fd[0],buffer,sizeof(char)*BUFFER_SIZE);
        printf("CHILD: #%s#\n", buffer);
        close(fd[0]);
    }
    return 0;
}
