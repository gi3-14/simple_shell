#include "main.h"
/**
 * register_token - this function must return a pointer
 * to the command if it exists or NULL if it does not.
 * @argument: the token sended
 * @head: head of the node
 * @M_GC: parameter to make release of mallocs
 * @count: count
 * Return: the right path or NULL if the token does not exist
 **/
char *register_token(M_GC, char *argument, dir_t *head,
size_t count)
{
	int existing = 0;
	char *question;

	if (argument == NULL)
		return (NULL);

	if (argument[0] == '/' || argument[0] == '.')
	{
		/*interactive mode*/
		existing = access(argument, X_OK);
		if (existing == 0)
			return (argument);
		else
			return (NULL);
	}
	else if (argument[0] >= 'a' || argument[0] <= 'z')
	{
		/*non-interactive mode*/
		question = find_command(GC, head, argument);
		if (question != NULL)
		{
			return (question);
		}
		else
		{
			get_error(count, argument);
			return (NULL);
		}
	}
	return (NULL);
}
