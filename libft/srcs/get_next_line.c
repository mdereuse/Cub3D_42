/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdereuse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:32:29 by mdereuse          #+#    #+#             */
/*   Updated: 2020/04/18 10:25:03 by mariedere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*extract_line(char *line)
{
	char	*new_line;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!(new_line = (char*)malloc(sizeof(*new_line) * (i + 1))))
	{
		free(line);
		return ((void*)0);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

static void	clear_buffer(char *buffer)
{
	size_t	i;
	size_t	n;

	n = 0;
	while (buffer[n] && buffer[n] != '\n')
		n++;
	if (buffer[n] == '\n')
		n++;
	i = 0;
	while (i < BUFFER_SIZE + 1 - n)
	{
		buffer[i] = buffer[n + i];
		i++;
	}
	while (i < BUFFER_SIZE + 1)
	{
		buffer[i] = '\0';
		i++;
	}
}

int			get_next_line(int fd, char **line)
{
	static char		buffer[BUFFER_SIZE + 1] = {'\0'};
	char			*tmp;
	int				ret;

	ret = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (-1);
	if (!(*line = ft_strdup(buffer)))
		return (-1);
	while (!ft_strchr(*line, '\n') && (ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buffer)))
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
	}
	if (!(*line = extract_line(*line)))
		return (-1);
	clear_buffer(buffer);
	return ((bool)ret);
}
