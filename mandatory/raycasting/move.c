/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:03:32 by ael-hara          #+#    #+#             */
/*   Updated: 2024/10/27 04:45:44 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_up(t_map_data *map, double old_x, double old_y)
{
	old_x = map->player->po_x;
	old_y = map->player->po_y;
	map->player->po_y = old_y - map->player->player_speed
		* sin(map->player->player_angle);
	map->player->po_x = old_x - map->player->player_speed
		* cos(map->player->player_angle);
	if (ft_border(map))
	{
		map->player->po_y = old_y;
		map->player->po_x = old_x;
	}
}

void	move_down(t_map_data *map, double old_x, double old_y)
{
	old_x = map->player->po_x;
	old_y = map->player->po_y;
	map->player->po_y = old_y + map->player->player_speed
		* sin(map->player->player_angle);
	map->player->po_x = old_x + map->player->player_speed
		* cos(map->player->player_angle);
	if (ft_border(map))
	{
		map->player->po_y = old_y;
		map->player->po_x = old_x;
	}
}

void	move_left(t_map_data *map, double old_x, double old_y)
{
	double	temp_angle;

	old_x = map->player->po_x;
	old_y = map->player->po_y;
	temp_angle = map->player->player_angle + M_PI / 2;
	map->player->po_y = old_y + map->player->player_speed * sin(temp_angle);
	map->player->po_x = old_x + map->player->player_speed * cos(temp_angle);
	if (ft_border(map))
	{
		map->player->po_y = old_y;
		map->player->po_x = old_x;
	}
}

void	move_right(t_map_data *map, double old_x, double old_y)
{
	double	temp_angle;

	old_x = map->player->po_x;
	old_y = map->player->po_y;
	temp_angle = map->player->player_angle - M_PI / 2;
	map->player->po_y = old_y + map->player->player_speed * sin(temp_angle);
	map->player->po_x = old_x + map->player->player_speed * cos(temp_angle);
	if (ft_border(map))
	{
		map->player->po_y = old_y;
		map->player->po_x = old_x;
	}
}

void	ft_close(void *param)
{
	t_map_data	*map;

	map = (t_map_data *)param;
	mlx_delete_image(map->mlx, map->img);
	free_allocated(&map->collected_data, map);
	close(map->fd);
	mlx_terminate(map->mlx);
	exit(0);
}
