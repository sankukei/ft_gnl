/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <leothoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:30:48 by leothoma          #+#    #+#             */
/*   Updated: 2024/12/18 20:53:49 by leothoma         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_purge(char *str);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_buffer(char *str);
char	*ft_fils(char *str, char *r);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
