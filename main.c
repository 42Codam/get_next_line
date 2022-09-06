/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbulbul <rbulbul@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/16 18:27:25 by rbulbul       #+#    #+#                 */
/*   Updated: 2022/08/25 17:32:42 by rbulbul       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <stdio.h>

void	check_leaks(void)
{	
	system("leaks get_next_line");
}

int	main(int argc, char const *argv[])
{
	int		fd;
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;
	int		i;

	atexit(check_leaks);
	if (argc != 5)
	{
		printf("There is no/(more than one) file to read.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	fd1 = open(argv[2], O_RDONLY);
	fd2 = open(argv[3], O_RDONLY);
	fd3 = open(argv[4], O_RDONLY);
	if (fd == -1 ||fd1 == -1 || fd2 == -1|| fd3 == -1)
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

		line = get_next_line(fd1);
		if (line == NULL)
			break ;
		i++;
		printf("%s", line);
		free(line);
		
		line = get_next_line(fd2);
		if (line == NULL)
			break ;
		i++;
		printf("%s", line);
		free(line);

		line = get_next_line(fd3);
		if (line == NULL)
			break ;
		i++;
		printf("%s", line);
		free(line);
	}
	printf("Total Line: %d\n", i);
	close(fd);
}
