/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:24:29 by gude-cas          #+#    #+#             */
/*   Updated: 2023/10/29 21:19:46 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* uses minilibx to put an image in a certain point of the 2D matrix */
void	put_image(t_data *game, int i, int j, void *image)
{
	int	x;
	int	y;

	x = game->wall.size.x;
	y = game->wall.size.y;
	mlx_put_image_to_window(game->mlx, game->window, image, j * x, i * y);
}

/* assign each xmp texture to its variable, image itself and also
the 'x' and 'y' size of it */
void	assign_image(t_data *game)
{
	game->player.image = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &game->player.size.x,
			&game->player.size.y);
	game->floor.image = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &game->floor.size.x, &game->floor.size.y);
	game->wall.image = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->wall.size.x, &game->wall.size.y);
	game->exit.image = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->exit.size.x, &game->exit.size.y);
	game->collectible.image = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &game->collectible.size.x,
			&game->collectible.size.y);
}

/* reads the game map and visually represents it by placing images on the game
screen based on the characters in the map*/
void	print_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				put_image(game, i, j, game->wall.image);
			else if (game->map[i][j] == '0')
				put_image(game, i, j, game->floor.image);
			else if (game->map[i][j] == 'P')
				put_image(game, i, j, game->player.image);
			else if (game->map[i][j] == 'E')
				put_image(game, i, j, game->exit.image);
			else if (game->map[i][j] == 'C')
				put_image(game, i, j, game->collectible.image);
			j++;
		}
		i++;
	}
}
