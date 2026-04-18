#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // I am using this for unix system calling 
#include <fcntl.h> // using this for the file controlling 
#include <errno.h> // gives proper error msg if found 
#include <signal.h> // it controls and prevents the shell from exiting 
#include <sys/wait.h> // process synchronization 
#include <sys/types.h> // defines the system data types

#define MAX_INPUT 1024; 
#define MAX_ARGS 128;
#define MEX_HISTORY 100;
#define MAX_PIPES 16;

int main (){

	return 0;
}

