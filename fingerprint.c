#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv){

    int nr_keywords;
    if (argc < 2 || argc >3){
        printf("Usage ./fingerprint <filename> [nr_keywords]");
        exit(0);
    }
    
    if (argc == 3){
        nr_keywords = atoi(argv[2]);
    }else{
        nr_keywords = 4;
    }
    
    char * filename = argv[1];

    char *buffer = malloc(128);
    
    // get file size

    FILE *fp = fopen(filename, "r");
    
    int fd_out = open("keywords", O_RDWR|O_CREAT|O_APPEND, 0644);
    
    fseek(fp, 0L, SEEK_END);
    long int sz = ftell(fp);

    int i;
    long int offset;
    //Seek to nr_keywords positions
    for(i = 0; i < nr_keywords;i++){
        offset = rand()%sz;
        fseek(fp, offset, SEEK_SET);
       
        if (!read(fileno(fp), buffer, 128)){
            printf("Read ERROR\n");
            exit(0);
        }
        write(fd_out,buffer,128);
        write(fd_out,"\n",1);
    }
    fclose(fp);
    close(fd_out);
    return 0;
}