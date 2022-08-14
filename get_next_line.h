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
#  define BUFFER_SIZE 42
# endif

typedef struct
{
	char	*content;
	int		readed;
}new_line;

// get_next_line.c
char	*get_next_line(int fd);
char	*read_and_stash(new_line *stash, int fd);
int		check_newline(char *buffer,int ret);
// size_t	ft_strlen(const char *s);
// Utils
char	*ft_strjoin_to_stash(char *content, char *src);
size_t	ft_strlen(const char *s);
void	ft_strlcpy(char *dst,const char *src);
char	*ft_strchr(const char *s, int c);


#endif