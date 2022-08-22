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
}
