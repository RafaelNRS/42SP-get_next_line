/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:40:25 by ranascim          #+#    #+#             */
/*   Updated: 2022/05/29 17:47:33 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_filtered_line(char *line)
{
	char	*filtered_line;
	int		i;

	if (!line[0])
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	filtered_line = malloc(sizeof(char) * (i + 2));
	if (!filtered_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		filtered_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		filtered_line[i++] = '\n';
	filtered_line[i] = '\0';
	return (filtered_line);
}

char	*get_whats_left(char *line)
{
	char	*left;
	int		i;
	int		x;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	left = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!left)
		return (NULL);
	x = 0;
	i++;
	while (line[i])
		left[x++] = line[i++];
	left[x] = '\0';
	free(line);
	return (left);
}

char	*read_line(int fd, char *line)
{
	char	*buffer;
	int		return_code;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	return_code = 1;
	while (return_code != 0)
	{
		return_code = read(fd, buffer, BUFFER_SIZE);
		if (return_code == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[return_code] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*filtered;
	static char	*line[256];

	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
		return (0);
	line[fd] = read_line(fd, line[fd]);
	if (!line[fd])
	{	
		free(line[fd]);
		return (NULL);
	}
	filtered = get_filtered_line(line[fd]);
	line[fd] = get_whats_left(line[fd]);
	return (filtered);
}
