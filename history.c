#include "shell.h"
/**
 * get_history_file - gets the history file
 * @info: parameter struct
 * Return: allocated string containing history file
 */
char *get_history_file(info_t *info)
{
char *buf, *dir;
dir = _getenv(info, "HOME=");
if (!dir)
return (NULL);
buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
if (!buf)
return (NULL);
buf[0] = 0;
_strcpy(buf, dir);
_strcat(buf, "/");
_strcat(buf, HIST_FILE);
return (buf);
}
/**
 * write_history - creates a file, or appends an existing file
 * @info: the parameter struct
 * Return: 1 on success, else -1
 */
int write_history(info_t *info)
{
ssize_t fd;
char *filename = get_history_file(info);
list_t *node = NULL;
if (!filename)
return (-1);
fd = open(filename, O_CREAT | O_TRUN | O_RDWR, 0644);
free(filename);
if (fd == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_putsfd(node->str, fd);
_putfd('\n', fd);
}
_putfd(BUF_FLUSH, fd);
close (fd);
return (1);
}
/**
 * read_history - rads history form file
 * @info: the parameter struct
 * Return: histcount on success, 0 otherwise
 */
rdlen = read(fd, buf, fsize);
buf[fsize] = 0;
if (rdlen <= 0)
return (free(buf), 0);
close (fd);
for (i = 0; i < fsize; i++)
if (buf[i] == '\n')
{
buf[i] = 0;
build_history_list(info, buf + last, linecount++);
free(buf);
info->histcount = linecount;
while (info-> histcount-- >= HIST_MAX)
delete_node_at_index(&(info->history), 0);
renumber_history(info);
return (info->histcount);
}
/**
 * build_history_list - adds entry to a history linked list
 * @info: structure containing potentail arguments
 * @buf: buffer
 * @linecount: the history linecount
 * Return: Always 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;
if (info->history)
node = info->history;
add_node_end(&node, buf, linecount);
if (!info->history)
info->history = node;
return (0);
}
/**
 * renumber_history - renumbers the history linked list after changes
 * @info: structure containing potential arguments
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
list_t *node = info->history;
int i = 0;
while (node)
{
node->num = i++;
node = node->next;
}
return (info->histcount = i);
}
