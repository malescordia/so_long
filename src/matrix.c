/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:39:06 by gude-cas          #+#    #+#             */
/*   Updated: 2023/11/02 14:31:25 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* iterates through each line of the map to count the amount of 'c' found */
int	count_char(char **map, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

/* iterates through each line of the map to check for wrong characters
and returns '1' if one is found */
int	wrong_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* returns the position of 'c' in the matrix */
t_point	get_position(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return ((t_point){j, i});
			j++;
		}
		i++;
	}
	return ((t_point){-1, -1});
}

/* iterate through map lines and return the number of lines */
int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
