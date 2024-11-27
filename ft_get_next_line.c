/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:54:16 by leothoma          #+#    #+#             */
/*   Updated: 2024/11/24 03:54:16 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

#define BUFFER_SIZE 5

char	*ft_strjoin(int count, char *s1, char *s2);
int	ft_check_buffer(char *str);
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		i++;
	}
	return (i);
}

int	ft_check_buffer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(int count, char *s1, char *s2)
{
	size_t	i;
	size_t	y;
	char	*res;
	i = 0;
	y = 0;

	res = malloc((count * BUFFER_SIZE) + 1);
	if (!res)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	while (y < ft_strlen(s2))
	{
		res[i++] = s2[y++];
	}
	res[i] = '\0';
	return (res);
}

char	*ft_get_next_line(int fd)
{
	char	*res;
	int	count;


	//TODO GERER LE CAS OU BUFFER_SIZE EST SUPPERIEUR A LA LIGNE
	res = NULL;
	count = 1;
	static char	buf[BUFFER_SIZE];
	while (read(fd, buf, BUFFER_SIZE) && !ft_check_buffer(buf))
	{
		res = ft_strjoin(count, res, buf);
		if (!res)
			return (NULL);
		count++;
	}
	return (res);
}

int main(void)
{
	int	fd;

	fd = open("./test", O_RDONLY);
	printf("%s" , ft_get_next_line(fd));
	printf("%s" , ft_get_next_line(fd));
	printf("%s" , ft_get_next_line(fd));
	return (0);
}
