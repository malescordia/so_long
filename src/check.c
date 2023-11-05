/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:20:22 by gude-cas          #+#    #+#             */
/*   Updated: 2023/11/02 14:33:23 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* returns 0 if map is covered in 1's, in the first loop 'i' is the left wall
and 'j' is the right wall, in the second loop 'i' becomes the bottom line
and 'j' becomes the top line */
int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map[0]) - 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j] != '1')
			return (1);
		i++;
	}
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

/* returns 0 if every line of the map is the same size */
int	check_rectangular(char **map)
{
	int	i;
	int	size;

	i = 1;
	size = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != size)
			return (1);
		i++;
	}
	return (0);
}

/* return 0 if .ber is the extension */
int	check_ber(char *path)
{
	char	*extension;

	extension = ft_strchr(path, '.');
	if (extension)
	{
		if (ft_strncmp(extension, ".ber", 5) == 0)
			return (0);
	}
	return (1);
}

/* return 0 if there is a correct path for the player to play the game */
int	check_path(char **map)
{
	int	i;
	int	j;

	flood_fill(map, ft_strlen(map[0]), map_height(map), get_position(map, 'P'));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* return 0 if map input passes all the check tests */
int	check_all(char *path)
{
	char	**map;

	if (check_ber(path) == 0)
	{
		map = read_map(path);
		if (map == NULL)
			return (1);
		if (wrong_char(map) == 1 || check_rectangular(map) || check_walls(map)
			|| count_char(map, 'P') != 1 || count_char(map, 'E') != 1
			|| count_char(map, 'C') < 1 || check_path(map))
		{
			free_map(map);
			return (1);
		}
		free_map(map);
	}
	else
		return (1);
	return (0);
}
