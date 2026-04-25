#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);



#define LSH_RL_BUFSIZE 1024

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM "\t\r\n\a"


/*
char *lsh_read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	if(getline(&line, &bufsize, stdin) == -1){
	if (feof(stdin)){
	exit(EXIT_SUCCESS);
	}else{
	perror("readline:");
	exit(EXIT_FAILURE);
	}
	}
	return line;
	}
*/
// the above command runs good if I use it for reading the line using getline()
char **lsh_split_line(char *line)
{
	int bufsize = LSH_TOK_BUFSIZE, POSITION = 0;
	
char *lsh_read_line(void)
{
	int bufsize = LSH_RL_BUFSIZE ;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c ;

	if(!buffer){
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	while(1){
		c = getchar();
		if (c==EOF || c == '\n'){
			buffer[position] = '\0';
			return buffer;
		}else{
			buffer[position] = c;
		}
		position++;

		if (position >= bufsize){
			bufsize += LSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer){
				fprintf(stderr, "lsh : allocation error\n");

				exit(EXIT_FAILURE);
			}
		}
	}
}


void lsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do{
		printf(">");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
	}while (status);
}






int main(int argc, char **argv){
	lsh_loop();
	return EXIT_SUCCESS;

}
