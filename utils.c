#include "get_next_line.h"
/* size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
} */

size_t ft_total_length(char *s1,char *s2)
{
	size_t total_length;
	int i;

	i = 0;
	total_length = 0;
	while (s1[i++] != '\0')
		total_length++;
	i = 0;
	while (s2[i++] != '\0')
		total_length++;
	return (total_length);
}

void ft_move_from_buffer(char *dst,const char *src,int index)
{
	int temp;

	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
}

char	*ft_strjoin_to_stash(char *content, char *buf)
{
	char	*s_ptr;
	size_t	total_length;
	int		i;
	int		temp;
	
	i = 0;
	total_length = ft_total_length(content,buf);
	if(!content || !buf)
		return (NULL);
	s_ptr = (char *)malloc(sizeof(char)*(total_length+1));
	while(content[i] != '\0')
	{
		s_ptr[i] = content[i];
		i++;
	}
	ft_move_from_buffer(&s_ptr[i],buf,i);
	free(content);
	return(s_ptr);
}