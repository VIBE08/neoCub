/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hara <ael-hara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:03:04 by ael-hara          #+#    #+#             */
/*   Updated: 2024/11/26 12:13:00 by ael-hara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	ft_move(mlx_key_data_t key, void *param)
{
	t_map_data	*map;

	map = (t_map_data *)param;
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_delete_image(map->mlx, map->img);
		free_allocated(&map->collected_data, map);
		close(map->fd);
		mlx_terminate(map->mlx);
		exit(0);
	}
	if (key.key == MLX_KEY_W)
		ft_move_player(map, DOWN);
	if (key.key == MLX_KEY_S)
		ft_move_player(map, UP);
	if (key.key == MLX_KEY_A)
		ft_move_player(map, RIGHT);
	if (key.key == MLX_KEY_D)
		ft_move_player(map, LEFT);
	if (key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_LEFT)
		ft_rotate_player(map, key);
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

void	map_init(t_map_data *map)
{
	int	i;
	int	j;

	i = -1;
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->img)
		error_handling(2, map);
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) < 0)
		error_handling(4, map);
	while (++i < map->map_height)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' \
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
				init_player(map, i, j);
			j++;
		}
	}
	mlx_close_hook(map->mlx, &ft_close, map);
	mlx_key_hook(map->mlx, &ft_move, map);
	mlx_loop_hook(map->mlx, &draw_ray, map);
	mlx_loop(map->mlx);
}
