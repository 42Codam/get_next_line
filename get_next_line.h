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
#  define BUFFER_SIZE 14
# endif

// get_next_line.c
char	*get_next_line(int fd);
char	*read_and_stash(char *stash, int fd);
int		check_newline(char *buffer);
char	*extract_line(char *stash);
char	*new_content(char *content);

// size_t	ft_strlen(const char *s);
// Utils
char	*ft_strjoin_to_stash(char *content, char *src);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dssize);
char	*ft_strchr(const char *s, int c);


#endif