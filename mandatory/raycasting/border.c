/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hara <ael-hara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:59:18 by ael-hara          #+#    #+#             */
/*   Updated: 2024/10/28 21:38:12 by ael-hara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_direction(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0')
		return (1);
	return (0);
}

int	border(t_map_data *map, int border_x, int border_y)
{
	int	index_y;
	int	index_x;

	if (map != NULL && map->player != NULL)
	{
		index_y = (int)((map->player->po_y + border_y) / GRID_SIZE);
		index_x = (int)((map->player->po_x + border_x) / GRID_SIZE);
		if (index_y >= 0 && index_y < map->map_height && index_x >= 0
			&& index_x < map->max_width)
		{
			if (map->map[index_y][index_x] == '1')
				return (1);
			if (!is_direction(map->map[index_y][index_x]))
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

int	ft_border(t_map_data *map)
{
	int	player_size;

	player_size = PLAYER_SIZE * (GRID_SIZE / 64);
	if (border(map, player_size / 2 + OFFSET, player_size / 2 + OFFSET)
		|| border(map, -player_size / 2 - OFFSET, player_size / 2 + OFFSET)
		|| border(map, player_size / 2 + OFFSET, -player_size / 2 - OFFSET)
		|| border(map, -player_size / 2 - OFFSET, -player_size / 2 - OFFSET))
		return (1);
	return (0);
}

void	error_handling(int flag, t_map_data *map)
{
	if (flag == 1)
	{
		mlx_terminate(map->mlx);
		error("mlx_init failed\n", map->fd, map);
	}
	if (flag == 2)
	{
		mlx_delete_image(map->mlx, map->img);
		mlx_terminate(map->mlx);
		error("mlx_new_image failed\n", map->fd, map);
	}
	if (flag == 3)
	{
		mlx_delete_image(map->mlx, map->img);
		mlx_terminate(map->mlx);
		error("mlx_texture_to_image failed\n", map->fd, map);
	}
	if (flag == 4)
	{
		mlx_delete_image(map->mlx, map->img);
		mlx_terminate(map->mlx);
		error("mlx_image_to_window failed\n", map->fd, map);
	}
}
