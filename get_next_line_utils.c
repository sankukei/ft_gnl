/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:45:53 by leothoma          #+#    #+#             */
/*   Updated: 2024/12/17 17:45:53 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*res;
	unsigned char	*tmp;
	unsigned long	i;

	res = 0;
	i = 0;
	if (nmemb == 0 || size == 0)
		return (res = malloc(0));
	if (!(nmemb > ((size_t) - 1 / size)))
		res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	tmp = res;
	while (i++ < nmemb * size)
		*tmp++ = 0;
	return (res);
}
