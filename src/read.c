/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:04:31 by gude-cas          #+#    #+#             */
/*   Updated: 2023/10/28 19:40:39 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* opens the file specified by 'path' and reads it
in an infinite loop until it reaches the end, using split
to make separate lines and build the square/rectangular map format */
char	**read_map(char *path)
{
	char	**map;
	char	*tmp;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = malloc(1);
	line[0] = '\0';
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		line = ft_strjoin(line, tmp);
		free(tmp);
	}
	map = ft_split(line, '\n');
	free(line);
	return (map);
}
