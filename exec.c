#include "shell.h"
/**
 * exec - Function where each process that a child creates and executes
 * the commands
 * @cmd_argumment: Argument which receives the address and file to be executed
 * @env: Environment Where to look for all Path
 * @M_GC: garbage collector
 * @line: linea dondere
 * Return: Always 0
 */
int exec(M_GC, char *cmd_argumment[], char **env, char *line)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
		return (-1);
	if (child == 0)
	{
		if (execve(cmd_argumment[0], cmd_argumment, env) == -1)
		{
			/*if the execution fails free everything and continue*/
			GC->free_all(GC);
			free_garbage_collector(GC), free(GC), free(line);
			exit(127);
		}
	}
	else
	{
		wait(&status);
		kill(child, SIGKILL);
	}
	return (0);
}
