/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:25:45 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/22 12:59:27 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*str;
	char		*dest;
	size_t		i;
	ssize_t		r;

	i = 0;
	if (fd == -1 || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (free(line), line = NULL, NULL);
	while (line && line[i])
	{
		if (line[i++] == '\n')
			return (check_latest_line(&line, &dest, i));
	}
	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (free(line), line = NULL, NULL);
	r = read(fd, str, BUFFER_SIZE);
	if (r <= 0)
		return (end_read(&line, &str, &dest, r));
	line_treatment(&line, &str, &dest, fd);
	return (dest);
}

void	line_treatment(char **line, char **str, char **dest, int fd)
{
	size_t	i;

	i = 0;
	if ((!*str || !str[0][0]) && (!*line || !line[0][0]))
		return ;
	while (str[0][i] && str[0][i] != '\n')
		i++;
	if (str[0][i] != '\n')
	{
		*line = ft_strnjoin_custom(*line, *str, i);
		free(*str);
		*dest = get_next_line(fd);
	}
	else
	{
		*dest = ft_strnjoin_custom(*line, *str, i + 1);
		*line = ft_substr_custom(*str, i + 1);
	}
}

char	*end_read(char **line, char **str, char **dest, ssize_t r)
{
	free(*str);
	if (r < 0 || !line[0] || !line[0][0])
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	*dest = ft_substr_custom(*line, 0);
	*line = NULL;
	return (*dest);
}

char	*check_latest_line(char **line, char **dest, size_t i)
{
	*dest = ft_strndup(*line, i);
	if (!(*dest))
		return (free(*line), *line = NULL, NULL);
	if (i < ft_strlen(*line))
		*line = ft_substr_custom(*line, i);
	else
	{
		free(*line);
		*line = NULL;
	}
	return (*dest);
}
