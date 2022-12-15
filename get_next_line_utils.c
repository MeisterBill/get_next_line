/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:44:47 by artvan-d          #+#    #+#             */
/*   Updated: 2022/10/25 12:09:19 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*joinedstrs;

	if (!str1 || !str2)
		return (NULL);
	joinedstrs = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (joinedstrs == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
	{
		joinedstrs[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		joinedstrs[i + j] = str2[j];
		j++;
	}
	joinedstrs[ft_strlen(str1) + ft_strlen(str2)] = '\0';
	free(str1);
	return (joinedstrs);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = malloc(sizeof(void) * count * size);
	if (!result)
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}
