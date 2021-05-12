#include "monty.h"

char number = '0';
/**
* main - Entry point
* @argc: argument counter
* @argv: argument string array
* Return: 0
*/
int main(int argc, char **argv)
{
	FILE *monty_file;
	long int file_size = 0;
	int i;
	char *monty_content = NULL, **commands = NULL;

	if (argc == 1 || argc > 2)
		return (1);

	monty_file = fopen(argv[1], "r");

	/* Get monty file content */
	fseek(monty_file, 0, SEEK_END);
	file_size = ftell(monty_file);
	fseek(monty_file, 0, SEEK_SET);
	monty_content = malloc(file_size + 1);
	fread(monty_content, 1, file_size, monty_file);

	commands = _split(monty_content, " ");
	printf("before cmds cleaner\n");
	for (i = 0; commands[i]; i++)
	{
		printf("index: %d, %s\n", i, commands[i]);
	}
	cmds_cleaner(commands);
	printf("before cmds cleaner\n");
	for (i = 0; commands[i]; i++)
	{
		printf("index: %d, %s\n", i, commands[i]);
	}

	fclose(monty_file);
	exit(EXIT_SUCCESS);
}
