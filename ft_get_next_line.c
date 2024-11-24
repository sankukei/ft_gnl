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

char	*ft_get_next_line(void)
{

	char 	*res;
	int	buf_size;

	buf_size = 50;
	res = 0;
	int	fd;
	int 	test;
	char	buf[100];
	int	count;

	count = 0;
	test = 0;
	fd = open("./test", O_RDONLY);
	test = read(fd, buf, 10);
	int 	i = 0;
	while(!check_backslash(buf))
	{
		count += read(fd, buf, buf_size);
	}
	return (res);
}

int	check_backslash(char *ptr)
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

int main(void)
{
	ft_get_next_line();
	return (0);
}
