#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * main - entry point of our monty program
 * @argc: the amount of arguments given to the program
 * @argv: the array of arguments given to the program
 * Return: EXIT_SUCCESS if no error has occures, otherwise EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	exit_code = run_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
