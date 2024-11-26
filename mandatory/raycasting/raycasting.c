/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hara <ael-hara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:07:55 by ael-hara          #+#    #+#             */
/*   Updated: 2024/10/31 21:28:12 by ael-hara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	max_width(t_map_data *map)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < map->map_height)
	{
		if (ft_strlen(map->map[i]) > max)
			max = ft_strlen(map->map[i]);
		i++;
	}
	return (max);
}

void	raycasting_scene(t_map_data *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", 0);
	if (map->mlx == NULL)
		error("mlx_init failed\n", map->fd, map);
	map->max_width = max_width(map);
	map->player->player_speed = 10;
	map->player->ray_distance = (FOV * (PI / 180)) / (WIDTH);
	map_init(map);
}
