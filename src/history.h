#ifndef LSH_HISTORY_H
#define LSH_HISTORY_H

void lsh_history_init(void);
char *lsh_history_readline(const char *prompt );
void lsh_history_cleanup(void);

#endif 
