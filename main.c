#include "main.h"
/**
 * main - main donde llamamos a todas las funciones necesarías
 *
 * @VOID_ARC: arc void
 * @VOID_ARV: arv void
 * @env: enviromment donde traemos todos los formatos necesarios
 * Return: Always 0
 */
int main(VOID_ARC, VOID_ARV, char **env)
{
	char *line = NULL, **tokens, path[1024];
	garbage_collector_t *GC;
	dir_t *head;
	size_t bufsize = 0, count = 1;
	ssize_t char_read;

	GC = create_garbage_collector();
	copy_path_from_env(env, path);
	head = dir_list(GC, path);
	signal(SIGINT, handle_sigint); /* <-- ctrl + c */

	while (1)
	{write(0, "$ ", 2);
		char_read = getline(&line, &bufsize, stdin);
		if (char_read == -1) /* EOF -> Ctrl+d */
		{	GC->free_all(GC);
			free_garbage_collector(GC), free(GC), free(line);
			/* _putchar('\n'); */
			return (0);
		}
		line[char_read - 1] = '\0';
		tokens = _split(GC, line);
		if (compare_str(tokens[0], "env") && (_strlen(tokens[0]) <= 3))
		{	print_env(env);
			continue;
		}
		if (compare_str(tokens[0], "exit"))
		{	GC->free_all(GC);
			free_garbage_collector(GC), free(GC), free(line);
			exit(0);
			return (0);
		}
		tokens[0] = register_token(GC, tokens[0], head, count++);
		if (tokens[0] == NULL)
			continue;
		exec(GC, tokens, env, line);
	}
	return (0);
}
