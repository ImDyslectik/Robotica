#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
    //init file directory
    int fd;

    //set the path where we're opening the pipe
    char * myfifo = "/tmp/myfifo";

    //make the fifo, this is the pipe
    mkfifo(myfifo, 0666);

    //init character arrays where we'll be storing messages
    char arr1[80], arr2[80];

    //do this until the heatdeath of the universe, or until something stops it. whichever is more likely
    while(1){
        //open the pipe in write only
        fd = open(myfifo, O_WRONLY);

        //get the string to send from the console and put it in an array
        fgets(arr2, 80, stdin);

        //write the array to the pipe, addinge space for the null byte terminator at the end
        write(fd, arr2, strlen(arr2)+1);
        //close the pipe becuase we should
        close(fd);

        //open the pipe in read only
        fd = open(myfifo, O_RDONLY);

        //read the pipe for a string and put it in the array
        read(fd, arr1, sizeof(arr1));

        //print the array over to the console
        printf("User2: %s\n", arr1);
        //close the pipe to be nice
        close(fd);
    }
    return 0;

}