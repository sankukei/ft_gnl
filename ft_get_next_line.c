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

#define BUFFER_SIZE 10

int	check_backslash(char *ptr);
char	*ft_get_next_line(void)
{

	char 	*res;

	int	fd;
	int 	test;
	char	buf[BUFFER_SIZE];
	int	i;
	int	y;
	i = 0;
	y = 0;
	test = 0;
	res = 0;
	fd = open("./test", O_RDONLY);

	return (res);
}

char	*check_buffer(char *buff, int buff_size)
{
	int	i;
	int	j;
	char	*res;

	i = 0;
	res = 0;
	j = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			break;
		i++;
	}
	if (i == buff_size)
		res = malloc(buff_size);
	else
		res = malloc(i + 1);
	if (!res)
		return (NULL);
	while (j <= i)
	{
		res[j] = buff[j];
		j++;
	}
	return (res);
}

int main(void)
{
	ft_get_next_line();
	return (0);
}
