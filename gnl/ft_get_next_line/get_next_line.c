/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinychoi <jinychoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:59:19 by jinychoi          #+#    #+#             */
/*   Updated: 2022/05/13 01:00:28 by jinychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buffer, char *og)
{
	int		count;
	char	*temp_pointer;

	count = 1;
	while (count)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (0);
		else if (count == 0)
			break ;
		buffer[count] = '\0';
		if (!og)
			og = ft_strdup("");
		temp_pointer = og;
		og = ft_strjoin(temp_pointer, buffer);
		if (!og)
			return (NULL);
		free(temp_pointer);
		temp_pointer = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (og);
}

static char	*post_process(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	result = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!result)
		return (NULL);
	if (result[0] == '\0')
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*og;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, og);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	og = post_process(line);
	return (line);
}
