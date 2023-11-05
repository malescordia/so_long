/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:07:29 by gude-cas          #+#    #+#             */
/*   Updated: 2023/10/28 16:44:20 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* checks if there is a connecting path between the 'P' and 'E',
it recursively checks the points next to the 'P' until it finds 'E' */
void	flood_fill(char **map, int max_x, int max_y, t_point player)
{
	if (player.x < 0 || player.y < 0 || player.x >= max_x || player.y >= max_y
		|| map[player.y][player.x] == '1')
		return ;
	if (map[player.y][player.x] == 'E')
	{
		map[player.y][player.x] = '1';
		return ;
	}
	map[player.y][player.x] = '1';
	flood_fill(map, max_x, max_y, (t_point){player.x + 1, player.y});
	flood_fill(map, max_x, max_y, (t_point){player.x - 1, player.y});
	flood_fill(map, max_x, max_y, (t_point){player.x, player.y + 1});
	flood_fill(map, max_x, max_y, (t_point){player.x, player.y - 1});
}
