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

#define BUFFER_SIZE 2

int	ft_check_buffer(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_fils(char *str);
void	ft_purge(char *str);

char	*get_next_line(int fd)
{
	char	*res;
	int	count;
	int	bol;
	res = 0;
	count = 0;
	bol = 0;
	static char	buf[BUFFER_SIZE];
 
	 while (!ft_check_buffer(buf))
	{
		count = read(fd, buf, BUFFER_SIZE);
		res = ft_strjoin(res, buf);
		res = ft_fils(res);
	}
	if (count > 0)
		ft_purge(buf);
	 while (count == 0 && buf[0] && bol != 1)
	{
		res = ft_fils(buf);
		ft_purge(buf);
		bol = 1;
	}
	return (res);
}

void	ft_purge(char *str)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
			i++;
		while (str[++i])
			str[y++] = str[i];
		while (y <= i)
			str[y++] = '\0';
		
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	y;
	char	*res;

	i = 0;
	y = 0;
	res = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	while (i < ft_strlen(s1))
		res[y++] = s1[i++];
	i = 0;
	while (i < ft_strlen(s2))
		res[y++] = s2[i++];
	res[y] = '\0';
	return (res);
}

int	ft_check_buffer(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_fils(char *str)
{
	int	i;
	int	y;
	char	*res;

	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	res = malloc(i + 1);
	while (y <= i)
	{
		res[y] = str[y];
		y++;
	}
	return (res);
}

int main(void)
{
	int	fd;

	fd = open("./test", O_RDONLY);
	printf("1 CALL: %s" , get_next_line(fd));
	printf("2 CALL: %s" , get_next_line(fd));
	printf("3 CALL: %s" , get_next_line(fd));
	return (0);
}
