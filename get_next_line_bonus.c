/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbulbul <rbulbul@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 15:48:37 by rbulbul       #+#    #+#                 */
/*   Updated: 2022/08/25 17:28:33 by rbulbul       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

char	*read_and_stash(char *content, int fd)
{
	int		bytes_read;
	char	buf[BUFFER_SIZE + 1];

	buf[0] = '\0';
	bytes_read = 1;
	if (ft_strchr(content, '\n'))
		return (content);
	while (!ft_strchr(buf, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_content(content));
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		content = ft_strjoin_to_stash(content, buf);
		if (!content)
			return (NULL);
	}
	if (*content == 0)
		return(free_content(content));
	return (content);
}

int	check_newline(char *str)
{
	int	offset_nl;

	offset_nl = 0;
	while (str[offset_nl] != '\0')
	{
		if (str[offset_nl] == '\n')
			break ;
		offset_nl++;
	}
	return (offset_nl);
}

char	*extract_line(char *content)
{
	int		nl_index;
	char	*temp;

	nl_index = 0;
	if (ft_strchr(content, '\n'))
	{
		nl_index = check_newline(content) + 2;
		temp = malloc(sizeof(char) * (nl_index));
		if (!temp)
			return (NULL);
		ft_strlcpy(temp, content, (nl_index));
		free (content);
		content = temp;
	}
	return (content);
}

char	*new_content(char *content)
{
	char	*temp;
	int		i;
	int		nl_index;

	i = 0;
	nl_index = check_newline(content);
	temp = malloc(sizeof(char) * (ft_strlen(content) - nl_index));
	if (!temp)
		return (free_content(content));
	while (content[nl_index] != '\0')
	{
		temp[i] = content[nl_index + 1];
		i++;
		nl_index++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*content[OPEN_MAX + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	if (!content[fd])
	{
		content[fd] = malloc(sizeof(char));
		if (!content[fd])
			return (NULL);
		content[fd][0] = '\0';
	}
	content[fd] = read_and_stash(content[fd], fd);
	if (!content[fd])
		return (NULL);
	line = extract_line(content[fd]);
	if (!line)
		return (free_content(content[fd]));
	content[fd] = new_content(content[fd]);
	return (line);
}
