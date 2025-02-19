/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineiras- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:15:03 by ineiras-          #+#    #+#             */
/*   Updated: 2025/02/13 17:31:16 by ineiras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H	
# define GET_NEXT_LINE_H

// Liberias:
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

// Get_next_line util functions
int		ft_strlen_cond(const char *str, int line_condition);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*free_null(char	*ptr);

// Get_next_line real functions
char	*ft_joinfree(char *temp, char *buffer);
char	*new_start(char *temp, int len);
char	*extract_line(char *temp);
char	*read_file(char *temp, int fd);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
