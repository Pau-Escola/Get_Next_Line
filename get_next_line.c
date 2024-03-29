/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:29:14 by pescola-          #+#    #+#             */
/*   Updated: 2023/03/06 12:22:43 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
