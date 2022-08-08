#include "get_next_line.h"

/* Uses read() to add characters to the stash */
char *read_and_stash(char *line, char *buffer, int fd)
{
	int	flag;
	int	ret;

	flag = 1;
	
	while(flag)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		printf("%d\n",ret);
		if (ret > 0)
		{
			
			buffer[ret] = '\0';
		}
		else
		{
			printf("there is nothing in the file or error (-1)\n");
			flag = 0;
			line = NULL;
		}
	}

	return line;

}

/*  Adds the content of our buffer to the end of our stash */
char	*add_stash(char *buffer,char *line)
{
	int i;

	printf("Add to stash");
	i = 0;
	while(buffer[i])
	{
		if (buffer[i] == '\n')
		{
			line = (char *)malloc(i * sizeof(char) + 1);
			if (!line)
				line = NULL;
			line = ft_memmove(line,buffer,(i+1));
			line[i] = '\n';
		}
		i++;
	}
	return (line);
}

/* 
** Extract all characters from our stash and stores them in out line
** Stopping after the first \n it encounters
*/
void extract_line()
{

}

/* 
** After extracting the line that was read, we don't need those characters anymore.
** this function clears the stash so only the characters that have not been returned at
** the end of get_next_line() remain in our static stash */
void clean_stash()
{

}

char *get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line = NULL;

	if(fd < 0 || BUFFER_SIZE < 0)
		return NULL;
	printf("This is coming from get_next_line() function\n");
	line = read_and_stash(line, buffer, fd);
	return (line);
}