/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbulbul <rbulbul@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 15:48:42 by rbulbul       #+#    #+#                 */
/*   Updated: 2022/08/25 15:49:55 by rbulbul       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len_s;

	i = 0;
	len_s = ft_strlen(s) + 1;
	while (i < len_s)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}

void	ft_strlcpy(char *dst, const char *src, size_t dssize)
{
	size_t	i;
	int		src_len;

	src_len = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && i < dssize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strjoin_to_stash(char *content, char *src)
{
	char	*s_ptr;
	size_t	total_length;
	int		i;

	total_length = ft_strlen(content) + ft_strlen(src);
	s_ptr = (char *)malloc(sizeof(char) * (total_length + 1));
	if (!s_ptr)
		return (NULL);
	i = 0;
	while (content[i] != '\0')
	{
		s_ptr[i] = content[i];
		i++;
	}
	ft_strlcpy(&s_ptr[i], src, ft_strlen(src) + 1);
	return (free(content), s_ptr);
}
