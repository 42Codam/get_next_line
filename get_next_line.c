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
	int		readed;
	char	*line;
	char	buf[BUFFER_SIZE+1];

	readed = 1;
	while(readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		buf[readed] = '\0';
		if(!ft_strchr(buf,'\n'))
			line = ft_strjoin_to_stash(stash,buf);
		else if(ft_strchr(buf,'\n'))
		{
			line = ft_strjoin_to_stash(stash,buf);
			break;
		}
	}
	if (readed == 0)
		return NULL;
	return (line);
}

int check_newline(char *buffer,int ret)
{
	int offset_nl;

	offset_nl = 0;
	while(offset_nl <= ret)
	{
		if (buffer[offset_nl] == '\n')
		{
			return (offset_nl);
		}
		offset_nl++;
	}
	return (0);
}

char *extract_line(char *stash)
{
	char	*extract_from_buffer;
	char	*temp;
	int		nl_index;

	nl_index = check_newline(buf,ret);
	temp = malloc(sizeof(char) * (ret - nl_index - 1));
		printf("Ret %d, nl_index %d\n",ret,nl_index);
	while (ret - nl_index > 0)
	{
		temp[ret - nl_index - 2] = buf[ret-1];
		ret--;
	}
	extract_from_buffer = malloc(sizeof(char) * nl_index + 1);
	ft_strlcpy(extract_from_buffer, buf);
	extract_from_buffer = ft_strjoin_to_stash(stash,extract_from_buffer);
	stash = temp;
	return(extract_from_buffer);
}

char *get_next_line(int fd)
{
	
	char		*line;
	static char	*content;
	char		buf[BUFFER_SIZE+1];

	if(fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT32_MAX)
		return NULL;
	content = read_and_stash(content, fd);
	if (!content)
		return(NULL);
	line = extract_line(content);
	content = update_stash(content);
	return (line);
}

	/* if(*stash->content)
		line = stash->content; */
