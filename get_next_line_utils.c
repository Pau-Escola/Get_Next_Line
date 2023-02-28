/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:29:31 by pescola-          #+#    #+#             */
/*   Updated: 2023/02/28 12:09:12 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int line_writer(char *line, int length, int file)
{
    int     i;
    char    c;

    i = 0;
    while (i < length)
    {
        if (read(file, &c, 1) != 0)
            line[i] = c;
        i++;
    }
    line[i] = '\0';
    return (1);    
}