#include "main.h"
/**
 * _split - function to cut into pieces the line that sent us
 * and organize them as pointers to each string of the line
 * @line: The command line that sent us
 * @M_GC: parameter to make release of mallocs
 * Return: tokens that is a double pointer pointing to each string
 **/
char **_split(M_GC, char *line)
{
	/*tokens will be a pointer to every string in line*/
	char **tokens, *tmp_line;
	int i;

	tokens = GC->malloc(GC, sizeof(char *) * 64);
	if (tokens == NULL)
	{
		perror("Error");
		return (NULL);
	}
	tmp_line = strtok(line, " ");
/*if tmp_line is == NULL it means that there are no more strings to copy*/
	for (i = 0; tmp_line != NULL; i++)
	{
		tokens[i] = tmp_line;
		tmp_line = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}
