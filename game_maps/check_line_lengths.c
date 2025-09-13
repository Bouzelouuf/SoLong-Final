/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_lengths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhefif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:49:39 by abkhefif          #+#    #+#             */
/*   Updated: 2025/01/30 12:40:51 by abkhefif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_next_lines(int fd, int width)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		if (width != len)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	check_line_lengths(char *filename, int *width)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd) * 0);
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		*width = len - 1;
	else
		*width = len;
	free(line);
	if (!check_next_lines(fd, *width))
	{
		close(fd);
		return (0);
	}
	return (close(fd) * 0 + 1);
}
