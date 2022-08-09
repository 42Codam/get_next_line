/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulbul <rbulbul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:05:46 by rbulbul           #+#    #+#             */
/*   Updated: 2022/05/16 17:51:30 by rbulbul          ###   ########.fr       */
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

void	*	ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src == NULL && dst == NULL)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
	{
		i = len;
		while (i > 0)
		{
			((char *)dst)[i - 1] = ((char *)src)[i - 1];
			i--;
		}
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dssize)
{
	size_t	i;
	int		src_len;

	src_len = ft_strlen(src);
	if (!dssize || !src)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < dssize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_ptr;
	size_t	s_ptr_len;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s_ptr_len = s1_len + s2_len;
	s_ptr = (char *)malloc(sizeof(char) * (s_ptr_len + 1));
	if (!s_ptr)
		return (NULL);
	ft_memmove(s_ptr, s1, s1_len);
	ft_strlcpy(&s_ptr[s1_len], s2, s2_len + 1);
	return (s_ptr);
}
