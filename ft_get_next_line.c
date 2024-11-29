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

#define BUFFER_SIZE 50 

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

static char	*purge_string(char *str)
{
	int	i;
	int	y;
	char	*res;

	res = 0;
	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	i++;
	y = i;
	while (str[y])
		y++;
	res = malloc(y + 1);
	y = 0;
	while (str[i])
		res[y++] = str[i++];
	while (res[y])
		res[y++] = 0;
	return (res);
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

char	*ft_strjoin(int count, char *s1, char *buf)
{
	size_t	i;
	size_t	y;
	char	*res;
	i = -1;
	y = 0;

	count++;
	res = malloc((ft_strlen(s1) + ft_strlen(buf)) + 1);
	if (!res)
		return (NULL);
	while (++i < ft_strlen(s1))
		res[i] = s1[i];
	while (y < ft_strlen(buf) && buf[y] != '\n')
		res[i++] = buf[y++];
	res[i] = '\0';
	return (res);
}

char	*xd(char *dest, char *buf)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while(buf[i] != '\n')
		i++;
	if (ft_check_buffer(buf))
	{
		dest = malloc(i + 1);
		while(y < i)
		{
			dest[y] = buf[y];
			y++;
		}
	}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;

	if (!dest && !src)
		return (dest);
	a = dest;
	b = src;
	while (n--)
		*a++ = *b++;
	return (dest);
}

char	*get_next_line(int fd)
{
	char	*res;
	int	count;
//	int	i;

	//TODO GERER LE CAS OU BUFFER_SIZE EST SUPPERIEUR A LA LIGNE
//	i = 0;
	res = NULL;
	count = 1;
	static char	buf[BUFFER_SIZE];
	if (buf[0])
		res = ft_strjoin(count, res, buf);
	while (read(fd, buf, BUFFER_SIZE))
	{

		res = ft_strjoin(count, res, buf);
		if (!res)
			return (NULL);
		if (ft_check_buffer(buf))
		{
			ft_memcpy(buf, purge_string(buf), BUFFER_SIZE);
			//buf = purge_string(buf);
//			res = ft_strjoin(count, res, buf);
			int len = ft_strlen(res);
			res[len] = '\n';
			return (res);
		}
		count++;
	}
	return (res);
}
/*
char	*gnl_bis(int fd)
{
	char	*res;
	int	count;

	count = 0;
	while (read(fd, buf, BUFFER_SIZE))
	{
		
	}
}*/

int main(void)
{
	int	fd;

	fd = open("./test", O_RDONLY);
	printf("1 CALL: %s" , get_next_line(fd));
	printf("2 CALL: %s" , get_next_line(fd));
	printf("3 CALL: %s" , get_next_line(fd));
	return (0);
}
