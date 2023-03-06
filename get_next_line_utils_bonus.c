/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pescola- <pescola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:29:31 by pescola-          #+#    #+#             */
/*   Updated: 2023/03/06 12:31:17 by pescola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	is_end_of_line(char	*ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	end_loc(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin_mod(char *s1, char *s2, int j)
{
	int		sj;
	char	*nwstr;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	nwstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!nwstr)
	{
		free (s1);
		return (NULL);
	}
	sj = -1;
	while (s1[++j] != 0)
		nwstr[j] = s1[j];
	while (s2[++sj] != 0)
		nwstr[j++] = s2[sj];
	nwstr[j] = '\0';
	free(s1);
	return (nwstr);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	char	*res;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		res = malloc(sizeof(char) * 1);
		if (!res)
			return (0);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	while (start < ft_strlen(s) && i < len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
