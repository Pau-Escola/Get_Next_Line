/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:29:43 by pescola-          #+#    #+#             */
/*   Updated: 2023/03/06 12:32:23 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
char	*ft_strjoin_mod(char *s1, char *s2, int j);
char	*ft_substr(char const *s, int start, int len);
#endif