/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbulbul <rbulbul@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/16 18:27:25 by rbulbul       #+#    #+#                 */
/*   Updated: 2022/05/16 18:59:00 by rbulbul       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>


/* size_t ft_total_length(char *s1,char *s2)
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

void ft_strlcpy(char *dst,const char *src)
{
	int index;

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
	ft_strlcpy(&s_ptr[i],buf);
	printf("%s\n",s_ptr);
	//free(content);
	return(s_ptr);
}
 */
int	main(int argc, char const *argv[])
{
	int fd;
	char *line;
	
	if (argc != 2)
	{
		printf("There is no/(more than one) file to read.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("Error while opening the file\n");
		return (0);
	}
	
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break;
		}
		printf("%s",line);
		free(line);
	}
	//while(1){}
	close(fd);

	/* char	*new;
	char	s1[]="12345";
	char	s2[]="678910";
	int		total_length = 0;

	new = ft_strjoin_to_stash(s1,s2);
	total_length = ft_total_length(s1,s2);
	printf("Total Length: %d\n",total_length);
	printf("New char is: %s\n",new);
	printf("%lu\n",strlen(new));
	return (0); */
}
