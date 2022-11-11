/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:34:28 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/11 10:32:48 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*string;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = malloc(size * sizeof(char));
	if (!string)
		return (0);
	j = 0;
	i = -1;
	while (s1[++i])
		string[i] = s1[i];
	while (s2[j])
		string[i++] = s2[j++];
	string[i] = '\0';
	free(s1);
	return (string);
}

static char	*allocate_help(char *string, int i)
{
	char	*new;
	int		size;

	size = i + 1;
	if (string[i] == '\n')
		size = i + 2;
	new = malloc(size * sizeof(char));
	return (new);
}

char	*get_new_line(char *string)
{
	char	*line;
	int		i;

	i = 0;
	if (!string[i])
		return (NULL);
	while (string[i] != '\n' && string[i])
		i++;
	line = allocate_help(string, i);
	if (!line)
		return (NULL);
	i = 0;
	while (string[i] != '\n' && string[i])
	{
		line[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		line[i] = string[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_left_string(char	*string)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	new_string = malloc((ft_strlen(string) - i + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	if (string[i] == '\n')
		i++;
	j = 0;
	while (string[i])
		new_string[j++] = string[i++];
	new_string[j] = '\0';
	free(string);
	return (new_string);
}
