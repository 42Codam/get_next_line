#include "get_next_line.h"
#include <limits.h>

/* Uses read() to add characters to the stash */
/*  Adds the content of our buffer to the end of our stash */
/* 
** Extract all characters from our stash and stores them in out line
** Stopping after the first \n it encounters
*/
/* 
** After extracting the line that was read, we don't need those characters anymore.
** this function clears the stash so only the characters that have not been returned at
** the end of get_next_line() remain in our static stash */
/* Uses read() to add characters to the stash */
char *read_and_stash(char *stash, int fd)
{
	int	readed;
	char		buf[BUFFER_SIZE+1];

	readed = 1;
	while(!ft_strchr(stash,'\n') && readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if(readed == 0)
			break;
		buf[readed] = '\0';
		stash = ft_strjoin_to_stash(stash,buf);
		if(ft_strchr(buf,'\n'))
			break;
	}
	if (!*stash && readed == 0)
		return NULL;
		// printf("New stash |%s|\n",stash);
	return (stash);
}

int check_newline(char *str)
{
	int offset_nl;

	offset_nl = 0;
	while(str[offset_nl] != '\0')
	{
		if (str[offset_nl] == '\n')
			break;
		offset_nl++;
	}
	return (offset_nl);
}

char *extract_line(char *stash)
{
	if (ft_strchr(stash,'\n'))
	{
		int		nl_index;
		char	*temp;
		nl_index = check_newline(stash)+2;
		temp = malloc(sizeof(char) * (nl_index));
		ft_strlcpy(temp,stash,(nl_index));
		stash = temp;
	}
	return(stash);
}

char *new_content(char *content)
{
	char	*temp;
	int		i;
	int		nl_index;

	i = 0;
	nl_index = check_newline(content) + 1;
	temp = malloc(sizeof(char) * (ft_strlen(content) - nl_index + 1));
	if(!temp)
		return NULL;
	while (content[nl_index] != '\0')
	{
		temp[i] = content[nl_index];
		i++;
		nl_index++;
	}
	temp[i] = '\0';
	free(content);
	// printf("New Content: |%s|\n",temp);
	return (temp);
}

char *get_next_line(int fd)
{
	
	char		*line;
	static char	*content;

	if(!content)
	{
		content = malloc(sizeof(char)*1);
		content = "";
	}
	if(fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT32_MAX)
		return NULL;
	content = read_and_stash(content, fd);
	// printf("Content: |%s|\n",content);
	if (!content)
		return(NULL);
	line = extract_line(content);
	content = new_content(content);
	// printf("New Content: |%s|\n",content);
	// printf("Line: |%s|\n",line);
	return (line);
}
