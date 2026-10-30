#include "history.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#include <readline/readline.h>
#include <readline/history.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif 
static char history_path[PATH_MAX];

void lsh_history_init(void)
{
	const char *home = getenv("HOME");

	if (home == NULL || *home == '\0'){
		history_path[0] = '\0';
		return;
	}


	int written = snprintf(history_path, sizeof(history_path)," %s/.ashutosh_lsh_history", home );

	if (written <0 || (size_t)written >= sizeof(history_path)){
		history_path[0] = '\0';
		return;
	}

	(void)read_history(history_path);
}

char *lsh_history_readline(const char *prompt)
{
	char *line = readline(prompt);

	if ( line != NULL && line[0] != '\0'){
		add_history(line);
		if (history_path[0] != '\0'){
			(void)write_history(history_path);
		}
	}

	return line ;
}

void lsh_history_cleanup(void)
{
	if (history_path[0] != '\0'){
		(void)write_history(history_path);
	}
	clear_history();

}
