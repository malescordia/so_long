/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:43:57 by gude-cas          #+#    #+#             */
/*   Updated: 2023/10/30 16:31:07 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* checks if the input move by the user is a valid move */
void	check_moves(t_data *game, t_point check)
{
	static int	i;

	if (game->map[check.y][check.x] == '1')
		return ;
	if (game->map[check.y][check.x] == 'E' && game->collectible_count > 0)
		return ;
	else if (game->map[check.y][check.x] == 'E' && game->collectible_count == 0)
	{
		ft_printf("\nYou win!\n");
		close_game(game);
	}
	else if (game->map[check.y][check.x] == 'C')
	{
		game->collectible_count--;
		game->map[check.y][check.x] = '0';
	}
	i++;
	mlx_put_image_to_window(game->mlx, game->window, game->floor.image,
		game->player_position.x * game->floor.size.x, game->player_position.y
		* game->floor.size.y);
	game->player_position = check;
	mlx_put_image_to_window(game->mlx, game->window, game->player.image,
		game->player_position.x * game->player.size.x, game->player_position.y
		* game->player.size.y);
	ft_printf("\rYOUR MOVES: %d", i);
}

/* function to associate the keys with the action required and gives the
input to 'check_moves' so it can validate the move */
int	key_press(int key, t_data *game)
{
	if (key == ESC)
		close_game(game);
	else if (key == UP || key == 'w')
		check_moves(game, (t_point){game->player_position.x,
			game->player_position.y - 1});
	else if (key == DOWN || key == 's')
		check_moves(game, (t_point){game->player_position.x,
			game->player_position.y + 1});
	else if (key == RIGHT || key == 'd')
		check_moves(game, (t_point){game->player_position.x + 1,
			game->player_position.y});
	else if (key == LEFT || key == 'a')
		check_moves(game, (t_point){game->player_position.x - 1,
			game->player_position.y});
	return (0);
}
