/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hara <ael-hara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:03:04 by ael-hara          #+#    #+#             */
/*   Updated: 2024/11/26 12:21:11 by ael-hara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ft_move_player(t_map_data *map, int direction)
{
	double	old_x;
	double	old_y;

	old_x = map->player->po_x;
	old_y = map->player->po_y;
	if (direction == UP)
		move_up(map, old_x, old_y);
	if (direction == DOWN)
		move_down(map, old_x, old_y);
	if (direction == RIGHT)
		move_right(map, old_x, old_y);
	if (direction == LEFT)
		move_left(map, old_x, old_y);
}

void	ft_rotate_player(t_map_data *map, mlx_key_data_t key)
{
	double	epsilon;

	epsilon = 0.000001;
	if (key.key == MLX_KEY_RIGHT)
	{
		map->player->player_angle += map->player->rotation_speed;
		if (map->player->player_angle > 2 * PI)
			map->player->player_angle = 0;
		ft_move_player(map, 0);
	}
	if (key.key == MLX_KEY_LEFT)
	{
		map->player->player_angle -= map->player->rotation_speed;
		if (map->player->player_angle <= 0)
			map->player->player_angle = 2 * PI - epsilon;
		ft_move_player(map, 0);
	}
}

void	init_player(t_map_data *map, int i, int j)
{
	map->player->po_x = j * GRID_SIZE + GRID_SIZE / 2;
	map->player->po_y = i * GRID_SIZE + GRID_SIZE / 2;
	map->player->player_speed = 10 * (GRID_SIZE / 64);
	map->player->rotation_speed = ROTATION_SPEED;
	if (map->map[i][j] == 'N')
		map->player->player_angle = 90 * (PI / 180);
	else if (map->map[i][j] == 'S')
		map->player->player_angle = 270 * (PI / 180);
	else if (map->map[i][j] == 'E')
		map->player->player_angle = 0;
	else if (map->map[i][j] == 'W')
		map->player->player_angle = 180 * (PI / 180);
}

void	load_and_hook(t_map_data *map)
{
	load_shot_sprites(map);
	load_reload_sprites(map);
	mlx_key_hook(map->mlx, &ft_move, map);
	mlx_cursor_hook(map->mlx, &cursor_func, map);
	mlx_set_cursor_mode(map->mlx, MLX_MOUSE_HIDDEN);
	mlx_close_hook(map->mlx, &ft_close, map);
	mlx_loop_hook(map->mlx, &draw_ray, map);
	mlx_loop_hook(map->mlx, &spirite, map);
}

void	map_init(t_map_data *map)
{
	int				i;
	int				j;

	i = 0;
	ft_mlx_start(map);
	while (i < map->map_height)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
				init_player(map, i, j);
			j++;
		}
		i++;
	}
	load_and_hook(map);
}
