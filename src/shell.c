#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SimpleCommand{
	int _numberOfAvailableArguments;
	int _numberOfArguments;
	char ** _arguments;
	SimpleCommand();
	void insertArgument( char*argument);
};

struct Command{
	int numberOfAvailableSimpleCommands;
	int numberOfSimpleCommands;
	SimpleCommand ** _simpleCommands;
	char * _outFile;
	char * _inputFile;
	char * _errFile;
	int _background;
	
	void prompt();
	void print();
	void execute();
	void clear();

	Command();
	void insertSimpleCommand (SimpleCommand*simplecommand);

	static Command _currentCommand;
	static SimpleCommand *_currentSimpleCommand;


};

