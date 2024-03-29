/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbulbul <rbulbul@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 15:48:37 by rbulbul       #+#    #+#                 */
/*   Updated: 2022/08/25 17:19:01 by rbulbul       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*content;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	if (!content)
	{
		content = malloc(sizeof(char));
		if (!content)
			return (NULL);
		content[0] = '\0';
	}
	content = read_and_stash(content, fd);
	if (!content)
		return (NULL);
	line = extract_line(content);
	if (!line)
		return (free_content(content));
	content = new_content(content);
	return (line);
}
