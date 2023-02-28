/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:29:14 by pescola-          #+#    #+#             */
/*   Updated: 2023/02/28 12:31:14 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*next_line;
	int		length;
	int		end_of_line;
	char	c;
	int		success;

	end_of_line = 0;
	length = 0;
	c = 0;
	success = 0;
	while (read(fd, &c, BUFFER_SIZE) != 0 && end_of_line == 0)
	{
		if (c == '\n')
			end_of_line = 1;
		else
			length++;		
	}
	next_line = malloc(sizeof(char) * (length + 1));
	success = line_writer(next_line, length, fd);
	if (success < 1)
		return ("ERROR");
	else
		return (next_line);
}
