#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "readFirst.h"

/*
* @param unreachable needs to be a number we are not using within our command array
* this is since C automaticly assing 0 as a standard array value messing up our commands
*/

void readSetup(int* engine_command[]){
    printf("hallo_setup \n");
    int unreachable = 9999;
	engine_command[0] = unreachable;
	engine_command[1] = unreachable;
    engine_command[2] = unreachable;
    engine_command[3] = unreachable;

}

int* reading(int* engine_command[]){
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
    int Forward = 900;
    int Backward = 0;
    while(1){
        /*
        * @param open(myfifo,O_RDONLY), opens the fifo in read only mode
        * @param read the opened pipe and store 80 characters in the array
        */
        fd1 = open(myfifo, O_RDONLY);
        read(fd1, str1, 80);
    
        if (strstr(str1,"F1")){
            //printf("Forwards on 1\n");
   	        engine_command[0] = Forward;
        }
        if (strstr(str1,"B1")){
            //printf("Backwards on 1\n");
	        engine_command[0] = Backward;
        }
	    if(strstr(str1,"F2")){
		    //printf("Forwards on 2\n");
		    engine_command[1] = Forward;
	    }
	    if(strstr(str1,"B2")){
		    //printf("Backwards on 2\n");
		    engine_command[1] = Backward;
	    }
        if(strstr(str1, "S1")){
            engine_command[2] = 0;
        }
        if(strstr(str1, "S2")){
            engine_command[2] = 1;
        }
        if(strstr(str1, "S3")){
            engine_command[2] = 2;
        }
        if(strstr(str1, "A1")){
            engine_command[3] = 0;
        }
        if(strstr(str1, "A2")){
            engine_command[3] = 1;
        }
        printf("");

        close(fd1);

    }
    int thread_ids = 3;
    pthread_join(&thread_ids, NULL);
    return 0;
}
