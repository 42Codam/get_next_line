/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbulbul <rbulbul@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/16 18:27:25 by rbulbul       #+#    #+#                 */
/*   Updated: 2022/08/25 15:51:39 by rbulbul       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	int		fd;
	char	*line;
	int		i;

	if (argc != 2)
	{
		printf("There is no/(more than one) file to read.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error while opening the file\n");
		return (0);
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i++;
		printf("%s", line);
		free(line);
	}
	printf("Total Line: %d\n", i);
	close(fd);
}
