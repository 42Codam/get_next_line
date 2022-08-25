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

char *read_and_stash(char *content, int fd)
{
	int		readed;
	char	buf[BUFFER_SIZE+1];
	//printf("Content giris |%s|\n", content);

	buf[0] = '\0';
	readed = 1;
	if(ft_strchr(content, '\n'))
		return (content);
	while(!ft_strchr(buf, '\n') && readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == 0)
			break;
		buf[readed] = '\0';
		content = ft_strjoin_to_stash(content, buf);	
	}
	if (*content == 0)
	{
		free (content);
		return NULL;
	}
	//printf("Content cikis |%s|\n\n", content);
	return (content);
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
	int		nl_index;

	nl_index = 0;
	if (ft_strchr(stash, '\n'))
	{
		char	*temp;
		nl_index = check_newline(stash) + 2;
		temp = malloc(sizeof(char) * (nl_index));
		if(!temp)
			return (NULL);
		ft_strlcpy(temp, stash, (nl_index));
		free (stash);
		stash = temp;
	}
	return (stash);
}

char *new_content(char *content)
{
	char	*temp;
	int		i;
	int		nl_index;

	i = 0;
	
	nl_index = check_newline(content);
	//printf("nl index: %d\n",nl_index);
	temp = malloc(sizeof(char) * (ft_strlen(content) - nl_index));
	if(!temp)
		return NULL;
	while (content[nl_index] != '\0')
	{
		temp[i] = content[nl_index+1];
		i++;
		nl_index++;
	}
	temp[i] = '\0';
	//printf ("temp: |%s|\n",temp);
	return (temp);
}

char *get_next_line(int fd)
{
	char		*line;
	static char	*content;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return NULL;
	if (!content)
	{
		content = malloc(sizeof(char)); //malloc #1
		if (!content)
			return (NULL);
		content[0] = '\0';
	}
	content = read_and_stash(content, fd);
	if (!content)
		return(NULL);
	line = extract_line(content);
	if (!line)
		free (content);
	content = new_content(content);
	// while (1){}
	return (line);
}
