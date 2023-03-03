/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:29:14 by pescola-          #+#    #+#             */
/*   Updated: 2023/03/03 03:03:54 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>
#include<fcntl.h>

//Una funcio que agafi la estatica, i em crei una nova estatica, a la que se li ha eliminat la primera linea
char	*clean_storage(char *storage)
{
	char	*new_storage;

	new_storage = ft_substr(storage, end_loc(storage) + 1, ft_strlen(storage) + 1);
	if(!new_storage)
	{
		free(storage);
		return(NULL);
	}
	free(storage);
	return (new_storage);
}

//Una funcio que de l estorage m agafi una linea, i em retorni una linea
//Qeu es una linea, pos trobar un \n, o si no \n arribar fins el \0
char	*get_the_line(char *storage)
{
	char	*line;
	if(storage[0] == '\0')
		return(NULL);
	line = ft_substr(storage, 0, end_loc(storage) + 1);
	if(!line)
		return(NULL);
	if (line[0] == '\0')
		return (NULL);
	return (line);
}

//Aquesta funcio m ha domplir la estatics, fins que i hagi un \n dins, o hagi arribat al final del archiu
//comn se si he arribat al final del archiu? perque el read em retorna 0
char	*fill_storage(char *storage, int fd)
{
	char		buff[BUFFER_SIZE + 1];
	int			marc;

	marc = 1;
	buff[0] = '\0';
	while (marc > 0 && !is_end_of_line(buff))
	{
		marc = read(fd, &buff, BUFFER_SIZE);
		if (marc == -1)
		{
			free(storage);
			return (NULL);
		}
		if (marc > 0)
		{
			buff[marc] = '\0';
			storage = ft_strjoin_mod(storage, buff);
		}
	}	
	return (storage);
}


char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*storage = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage || (storage && !is_end_of_line(storage)))
		storage = fill_storage(storage, fd);
	if (!storage)
		return (NULL);
	next_line = get_the_line(storage);
	if (!next_line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = clean_storage(storage);
	return (next_line);
}
/*
int   main(void)
{
    char    *line;
    int     fd_1;
    int     i;
    fd_1 = open("test2.txt", O_RDONLY);
    i = 1;
    while (i < 10)
    {
        line = get_next_line(fd_1);
        if (!line)
            return (0);
        printf("Line %d for fd %d: %s <%u>\n", i, fd_1, line, ft_strlen(line));
        free(line);
        i++;
    }
}*/