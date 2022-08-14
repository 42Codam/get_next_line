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

void ft_strlcpy(char *dst,const char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		if(src[index] == '\n')
		{
			index++;
			break;
		}
		index++;
	}
	dst[index] = '\0';
}

char	*ft_strjoin_to_stash(char *content, char *src)
{
	char	*s_ptr;
	size_t	total_length;
	int		i;
	
	i = 0;
	total_length = ft_strlen(content) + ft_strlen(src);
	if(!content || !src)
		return (NULL);
	s_ptr = (char *)malloc(sizeof(char)*(total_length+1));
	while(content[i] != '\0')
	{
		s_ptr[i] = content[i];
		i++;
	}
	ft_strlcpy(&s_ptr[i],src);
	//free(content);
	return(s_ptr);
}