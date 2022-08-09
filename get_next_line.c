#include "get_next_line.h"

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
char *read_and_stash(t_list *stash, char *buffer, int fd)
{
	int		ret = 1;
	char	*new_line;

	while(1)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		
		if (ret <= 0)
			return (NULL);
		check_newline(buffer,stash);
		if(stash->check_newline == 0)
		{
			buffer[ret] = '\0';
			stash->content = ft_strjoin(stash->content,buffer);
		}
		else if(stash->check_newline == 1)
		{
			extract_line(stash,buffer);
			new_line = stash->content;
			break;
		}
	}
	return (new_line);
}

void check_newline(char *buffer,t_list *stash)
{
	int offset_nl;

	stash->check_newline = 0;
	offset_nl = 0;
	while(offset_nl <= BUFFER_SIZE)
	{
		if (buffer[offset_nl] == '\n')
		{
			stash->check_newline = 1;
			stash->new_line_index = offset_nl;
		}
		offset_nl++;
	}
}

void extract_line(t_list *stash, char *buf)
{
	char *extract_from_buffer;

	extract_from_buffer = malloc(sizeof(char) * (stash->new_line_index+1));
	if (BUFFER_SIZE == 1)
		stash->new_line_index++;
	ft_strlcpy(extract_from_buffer,buf,(stash->new_line_index+1));
	stash->content = ft_strjoin(stash->content,extract_from_buffer);
}

char *get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*buffer;
	char			*line;

	stash = malloc(sizeof * stash);
	stash->content = malloc(sizeof(char *) * 1);
	stash->content = "";
	buffer = malloc(sizeof * buffer * (BUFFER_SIZE + 1));
	if(fd < 0 || BUFFER_SIZE <= 0 || !buffer || !stash->content)
		return NULL;
	line = read_and_stash(stash, buffer, fd);
	return (line);
}
