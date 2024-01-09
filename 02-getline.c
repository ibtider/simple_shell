#include "shell.h"

/**
 * _getline -  a function that prints a prompt
 * and get input from stdin.
 * Return: the input string in success
 */
char *_getline(void)
{
	char *line = NULL;
	size_t len = 0;
	
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, PROMPT, 2);

	/* Get input from stdin */
	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	/* Return the line */
	return (line);
}
