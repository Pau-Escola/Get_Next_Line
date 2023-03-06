/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:29:14 by pescola-          #+#    #+#             */
/*   Updated: 2023/03/06 12:30:32 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*clean_storage(char *storage)
{
	char	*new_storage;

	new_storage = ft_substr(storage, end_loc(storage)
			+ 1, ft_strlen(storage) + 1);
	if (!new_storage)
	{
		free(storage);
		return (NULL);
	}
	free(storage);
	return (new_storage);
}

char	*get_the_line(char *storage)
{
	char	*line;

	if (storage[0] == '\0')
		return (NULL);
	line = ft_substr(storage, 0, end_loc(storage) + 1);
	if (!line)
		return (NULL);
	if (line[0] == '\0')
	{
		free (line);
		return (NULL);
	}
	return (line);
}

char	*fill_storage(char *storage, int fd)
{
	char		buff[BUFFER_SIZE + 1];
	int			char_read;

	char_read = 1;
	buff[0] = '\0';
	while (char_read > 0 && !is_end_of_line(buff))
	{
		char_read = read(fd, &buff, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(storage);
			return (NULL);
		}
		if (char_read > 0)
		{
			buff[char_read] = '\0';
			storage = ft_strjoin_mod(storage, buff, -1);
		}
	}	
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*storage[OPEN_MAX] = {0};

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!storage[fd] || (storage[fd] && !is_end_of_line(storage[fd])))
		storage[fd] = fill_storage(storage[fd], fd);
	if (!storage[fd])
		return (NULL);
	next_line = get_the_line(storage[fd]);
	if (!next_line)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	storage[fd] = clean_storage(storage[fd]);
	return (next_line);
}
