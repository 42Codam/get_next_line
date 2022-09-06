/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbulbul <rbulbul@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/16 18:07:34 by rbulbul       #+#    #+#                 */
/*   Updated: 2022/08/25 17:20:56 by rbulbul       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// get_next_line
char	*get_next_line(int fd);
char	*read_and_stash(char *content, int fd);
int		check_newline(char *buffer);
char	*extract_line(char *content);
char	*new_content(char *content);

// utils
char	*free_content(char *content);
char	*ft_strjoin_to_stash(char *content, char *src);
size_t	ft_strlen(const char *s);
void	ft_strlcpy(char *dst, const char *src, size_t dssize);
char	*ft_strchr(const char *s, int c);

#endif