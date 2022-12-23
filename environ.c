#include "shell.h"
/**
 * _myenv - prints the current environment
 * @info: structure containing potential arguments
 * Return: Always 0
 */
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}
/**
 * _getenv - gets the value of an environ variable
 * @info: structure containing potential arguments
 * @name: env var name
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
if (_setenv(info, info->argv[2]))
return (0);
return (1);
}
/**
 * _myunsetenv - Remove an environment variable
 * @info: structure containing potential arguments
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
int i;
if (info->argc == 1)
{
_eputs("Too few arguments.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_unsetenv(info, info->argv[i]);
return (0);
}
/**
 * populate_env_list_populates env linked list
 * @info: structure containing potential arguments
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t i;
for (i = 0; environ[i]; i++)
add_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}
