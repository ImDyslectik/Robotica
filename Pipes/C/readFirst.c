#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
    //init file directory
    int fd1;

    //set the path where we're opening the pipe
    char * myfifo = "/tmp/command";

    //make the fifo, this is the pipe
    mkfifo(myfifo, 0666);

    //init character arrays where we'll be storing messages
    char str1[80], str2[80];

    //do this until the end of time
    while(1){
        //open the fifo in read only mode
        fd1 = open(myfifo, O_RDONLY);

        //read the opened pipe and store 80 characters in the array
        read(fd1, str1, 80);

        if (strstr(str1,"F1")){
            printf("Forwards on 1\n");
        }
        if (strstr(str1,"B1")){
            printf("Backwards on 1\n");
        }
	if(strstr(str1,"F2")){
		printf("Forwards on 2\n");
	}
	if(strstr(str1,"B2")){
		printf(str1,"Backwards on 2\n");
	}
        //print the array to the screen
        printf("");
        
        //open the fifo, this time in write only mode
        //fd1 = open(myfifo, O_WRONLY);

        //get the 80 bytes from the console, and write this into the array
        //fgets(str2, 80, stdin);

        //write the contents of the array into the fifo, and add a byte for the 0 byte to signify end of string
        //write(fd1, str2, strlen(str2)+1);

        //close the fifo
        close(fd1);

    }
    return 0;

}
