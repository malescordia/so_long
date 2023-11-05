/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:04:18 by gude-cas          #+#    #+#             */
/*   Updated: 2023/10/30 15:55:42 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define ESC 65307

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_image
{
	void	*image;
	t_point	size;
}			t_image;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	**map;
	t_point	map_size;
	t_image	player;
	t_point	player_position;
	t_image	floor;
	t_image	wall;
	t_image	exit;
	t_image	collectible;
	int		collectible_count;
}			t_data;

/* free */
void		free_map(char **map);
int			close_game(t_data *game);

/* play */
void		check_moves(t_data *game, t_point check);
int			key_press(int key, t_data *game);

/* image */
void		assign_image(t_data *game);
void		print_map(t_data *game);
void		put_image(t_data *game, int i, int j, void *image);

/* flood */
void		flood_fill(char **map, int max_x, int max_y, t_point player);

/* utils */
int			ft_strncmp(char *s1, char *s2, int n);
char		**ft_split(const char *s, char c);

/* check */
int			check_all(char *path);
int			check_ber(char *path);
int			check_rectangular(char **map);
int			check_walls(char **map);
int			check_path(char **map);

/* matrix */
int			count_char(char **map, char c);
int			wrong_char(char **map);
int			map_height(char **map);
t_point		get_position(char **map, char c);

/* read */
char		**read_map(char *path);

/* game */
void		start_game(char *path);

#endif
