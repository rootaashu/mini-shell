#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // I am using this for unix system calling 
#include <fcntl.h> // using this for the file controlling 
#include <errno.h> // gives proper error msg if found 
#include <signal.h> // it controls and prevents the shell from exiting 
#include <sys/wait.h> // process synchronization 
#include <sys/types.h> // defines the system data types

#define MAX_INPUT 1024
#define MAX_ARGS 128
#define MAX_HISTORY 100
#define MAX_PIPES 16

static char hostory[MAX_HISTORY][MAX_INPUT];
static int history_count = 0;
static pid_t foreground_pid = -1;

static void sigint_handler( int sig){
	(void)sig;
	if (foreground_pid > 0)
		kill(foreground_pid, SIGINT);
}

static void sigchld_handler(int sig){
	(void)sig;
	while (waitpid(-1, NULL, WNOHANG) > 0);
}

static void add_history(const char *line){
	if(strlen(line) == 0) return ;
	if(history_count < MAX_HISTORY){
		strncpy(history[history_count++], line, MAX_INPUT - 1);
	}else {
		memmove(history[0], history[1], sizeof(history[0] * (MAX_HISTORY - 1)));
		strncpy(history[MAX_HISTORY - 1], line , MAX_INPUT - 1)
	}
}

static void print_history( void){
	for (int i=0; i<history_count; i++)
		printf("%3d  %s/n", i+1, history[i]);
}


int main (){

	return 0;
}

