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

char	*ft_get_next_line(int fd)
{
	char	*res;
	int	i;

	i = 0;
	res = 0;
	static char	buf[BUFFER_SIZE];
	while (read(fd, buf, BUFFER_SIZE))
	{
		if (ft_check_buffer(buf))
		{
			//JOIN LE STASH MAGIQUE
		}
	}
	return (res);
}

int main(void)
{
	int	fd;

	fd = open("./test", O_RDONLY);
	ft_get_next_line(fd);

}
