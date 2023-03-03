/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:29:43 by pescola-          #+#    #+#             */
/*   Updated: 2023/03/03 02:22:26 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(int)1
# endif

int		ft_strlen(const char *s);
char	*get_next_line(int fd);
int		is_end_of_line(char	*ptr);
int		end_loc(char *ptr);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*ft_substr(char const *s, int start, int len);
#endif