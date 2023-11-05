/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:05:01 by gude-cas          #+#    #+#             */
/*   Updated: 2023/10/30 16:07:24 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* free allocated memory */
void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/* free allocated memory for the game, destroy the window and the images */
int	close_game(t_data *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->player.image);
	mlx_destroy_image(game->mlx, game->floor.image);
	mlx_destroy_image(game->mlx, game->wall.image);
	mlx_destroy_image(game->mlx, game->exit.image);
	mlx_destroy_image(game->mlx, game->collectible.image);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

/* starts the game using mlx_init() and mlx_new_window(),
	then it keeps the game open with mlx_loop() */
void	start_game(char *path)
{
	static t_data	game;

	game.map = read_map(path);
	game.collectible_count = count_char(game.map, 'C');
	game.player_position = get_position(game.map, 'P');
	game.map_size = (t_point){ft_strlen(game.map[0]), map_height(game.map)};
	game.mlx = mlx_init();
	assign_image(&game);
	game.window = mlx_new_window(game.mlx, game.wall.size.x * game.map_size.x,
			game.wall.size.y * game.map_size.y, "so_long");
	print_map(&game);
	mlx_hook(game.window, 2, 1, key_press, &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (check_all(av[1]) == 0)
			start_game(av[1]);
		else
			ft_printf("Error\nMap not correct.\n");
	}
	else
		ft_printf("Error\nInvalid amount of args.\n");
}
