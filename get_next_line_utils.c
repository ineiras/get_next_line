/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineiras- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:15:25 by ineiras-          #+#    #+#             */
/*   Updated: 2025/02/13 17:35:01 by ineiras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*free_null(char	*ptr)
{
	if (ptr == NULL || ptr[0] == '\0')
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}

int	ft_strlen_cond(const char *str, int line_condition)
{
	int	i;

	i = 0;
	if (line_condition == 0)
	{
		while (str[i] != '\0')
			i++;
	}
	else
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *) malloc(ft_strlen_cond(s1, 0) + ft_strlen_cond(s2, 0) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
