#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>

/* MACROS */
#define M_GC garbage_collector_t *GC
#define VOID_ARC int arc __attribute__((unused))
#define VOID_ARV char **arv __attribute__((unused))


/**
 * struct dir_t - structure for the directories
 * @directory: directory to get
 * @next: var to change of node
 **/
typedef struct dir_t
{
	char *directory;
	struct dir_t *next;
} dir_t;

/**
 * struct _garbage - struct
 * @subscriptions: subscriptor
 * @subscriptions_free: subscriptions frees
 * @malloc: malloc
 * @free_all: free
 * @malloc_acumulator: acumulator
 * @free_acumulator: free acomulator
 */
typedef struct _garbage
{
	void **subscriptions;
	void **subscriptions_free;
	unsigned int malloc_acumulator;
	long int free_acumulator;

	void *(*malloc)(struct _garbage *GC, size_t size);
	void (*free_all)(struct _garbage *GC);
} garbage_collector_t;

garbage_collector_t *create_garbage_collector(void);

void free_garbage_collector(M_GC);

/*IMPORTANT FUNCTIONS*/
/* dir_list - make a liked list with the directories*/
dir_t *dir_list(M_GC, char *path);
/* register_token - looks for the existence of a command*/
char *register_token(M_GC, char *argument, dir_t *head, size_t count);
/* find_command - find if the pateh exists*/
char *find_command(M_GC, dir_t *nodo, char *command);
/* _split - function to cut into pieces the line that sent us */
/* and organize them as pointers to each string of the line */
char **_split(M_GC, char *line);
/* exec - creates a child process and executes the file mentioned */
int exec(M_GC, char *cmd_argumment[], char **env, char *line);
/* get_error -  Function that prints errors */
void get_error(size_t count, char *line_argument);

/*TOOLS*/
/* add_nodeint_end - adds a new node at the end of a dir_t list*/
dir_t *add_nodeint_end(M_GC, dir_t **head, char *directory);
/* str_concat - concatenates two strings*/
char *str_concat(M_GC, char *s1, char *s2);
/* copy_path_from_env - This function copies the content of PATH to the env*/
void copy_path_from_env(char **env, char *path);
/* handle_sigint - Function to handle Ctrl + C */
void handle_sigint(int sig);
/* _putchar2 -Function to print a character on standard output*/
int _putchar2(char character);

/*TOOLS 2*/
/* compare_str - compare two strings*/
int compare_str(char *str1, char *str2);
/* _putchar -Function to print a character on standard error*/
int _putchar(char character);
/* strlen - function to count the length of a string */
int _strlen(char *str);
/* print_number - function that prints numbers only */
void print_number(size_t counter);
/*print_env - function to print env*/
int print_env(char **env);

#endif
