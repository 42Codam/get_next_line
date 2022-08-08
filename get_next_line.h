/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbulbul <rbulbul@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/16 18:07:34 by rbulbul       #+#    #+#                 */
/*   Updated: 2022/05/16 18:35:05 by rbulbul       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

char	*get_next_line(int fd);
char	*read_and_stash(char *line, char *buffer, int fd);
char	*add_stash(char *buffer,char *line);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);


#endif