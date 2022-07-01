#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int cd_error(char *path)
{
 char *message;

 message = strerror(errno);
 ft_putstr_fd("minishell: ", 2);
 ft_putstr_fd(path, 2);
 ft_putstr_fd(message, 2);
 ft_putchar_fd('\n', 2);
 return (1);
}

if (res < 0)
  return (cd_error(path));