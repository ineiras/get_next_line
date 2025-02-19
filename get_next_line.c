/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineiras- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:14:20 by ineiras-          #+#    #+#             */
/*   Updated: 2025/02/17 12:18:25 by ineiras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*ft_joinfree(char *temp, char *buffer)
{
	char	*ptr;

	ptr = ft_strjoin(temp, buffer);
	if (ptr == NULL)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (ptr);
}

char	*new_start(char *temp, int len)
{
	char	*buffer;
	int		i;

	i = 0;
	if (temp == NULL || temp[0] == '\0')
		return (free_null(temp));
	if (temp[len] == '\n')
		len++;
	while (temp[len + i] != '\0')
		i++;
	buffer = malloc((i + 1) * sizeof(char));
	if (buffer == NULL)
	{
		free(temp);
		return (NULL);
	}
	i = 0;
	while (temp[len + i] != '\0')
	{
		buffer[i] = temp[len + i];
		i++;
	}
	buffer[i] = '\0';
	free(temp);
	return (buffer);
}

char	*extract_line(char *temp)
{
	int		size;
	int		i;
	char	*line;

	size = ft_strlen_cond(temp, 1);
	line = malloc((size + 2) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*read_file(char *temp, int fd)
{
	char	*buffer;
	int		bytes_readed;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (buffer);
	bytes_readed = 1;
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (bytes_readed < 0)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_readed] = '\0';
		temp = ft_joinfree(temp, buffer);
		if (ft_strchr(temp, '\n') != NULL)
			break ;
	}
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (temp == NULL)
	{
		temp = malloc(1 * sizeof(char));
		if (temp == NULL)
			return (NULL);
		temp[0] = '\0';
	}
	temp = read_file(temp, fd);
	if (temp == NULL)
		return (NULL);
	line = extract_line(temp);
	temp = new_start(temp, ft_strlen_cond(temp, 1));
	return (line);
}
/*
int	main(int argc, char *argv[])
{
	int		open_funct;
	char	*line;

	open_funct = open(argv[1], O_RDONLY);
	while ((line = get_next_line(open_funct)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(open_funct);
	return (0);
}*/
