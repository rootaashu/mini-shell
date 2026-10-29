#define MAX_HISTORY 100
#define MAX_COMMAND 256

char history[MAX_HISTORY][MAX_COMMAND];
int history_count = 0;

void add_history(const char *command)
{
	if (command[0] == '\0')
		return ;
	if (history_count < MAX_HISTORY){
		strcpy(history[history_count], command);
		history_count++;
	}
}

int history_index;
history_index = history_count;


printf("\033[2K\r");
printf("root@os> %s", history[history_index]);

void show_history(void)
{
	for(int i=0; i<history_count; i++){
		printf("%d %s\n", i +1 , history[i]);
	}
}
