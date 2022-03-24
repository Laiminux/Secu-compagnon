#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("file to copy");
    char * fn;
    scanf("%s",fn);
    FILE * f = fopen(fn,"rb"); //we try to open the actual file executed
    if (f==NULL){
        printf("\n pas read");
        }
    printf("name of the copy");
    char * cp;
    scanf("%s",cp);
    FILE * g = fopen(cp,"wb"); //we try to create and open for writing a new file with the pointed program name
    if (f==NULL){
        printf("\n pas ecrire");
    }
    fseek(f, 0L, SEEK_END); //we place the reading pointer to the last character
    int sz = ftell(f); //we recover the position of the reading pointer to know the size of the file
    printf("\t size :%d \t",sz);
    char buf[sz]; //creating a buffer with the size of the file
    int x; 
    fseek(f, 0L, SEEK_SET); //we replace the reading pointer to the beginning of the file
    while((x = fread(buf, 1, sz, f) != 0)){  // we iterate threw each character of the file and recover the block number
        if(fwrite(buf, 1, sz, g) != x){ //if the block number returned by fwrite is different from fread we break the loop 
            break; 
        } 
    }

    return 0;
}
