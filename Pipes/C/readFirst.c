#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
void readSetup(int* engine_command[]){
	int right_engine;
	int left_engine;
	engine_command[0] = right_engine;
	engine_command[1] = left_engine;
}

int reading(int* engine_command[]){
    /* 
    * @param int fd1, init file directory
    * @param char* myfifo, set the path where we're opening the pipe
    * @param mkfifo, make the fifo, this is the pipe 
    * @param char str1[] & str2[], init character arrays where we'll be storing messages
    */

    int fd1;
    char * myfifo = "/tmp/command";
    mkfifo(myfifo, 0666);
    char str1[80], str2[80];
    //do this until the end of time
        /*
        * @param open(myfifo,O_RDONLY), opens the fifo in read only mode
        * @param read the opened pipe and store 80 characters in the array
        */
        fd1 = open(myfifo, O_RDONLY);
        read(fd1, str1, 80);

        if (strstr(str1,"F1")){
            //printf("Forwards on 1\n");
	        engine_command[0] = 1;
        }
        if (strstr(str1,"B1")){
            //printf("Backwards on 1\n");
	        engine_command[0] = 0;
        }
	    if(strstr(str1,"F2")){
		    //printf("Forwards on 2\n");
		    engine_command[1] = 1;
	    }
	    if(strstr(str1,"B2")){
		    //printf("Backwards on 2\n");
		    engine_command[0] = 0;
	    }
        printf("");
        close(fd1);

   
    return 0;

}
