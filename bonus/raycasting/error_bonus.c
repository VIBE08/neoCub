/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hara <ael-hara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:43:29 by ael-hara          #+#    #+#             */
/*   Updated: 2024/10/26 17:00:54 by ael-hara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
		mlx_delete_image(map->mlx, map->img2);
		mlx_terminate(map->mlx);
		error("mlx_texture_to_image failed\n", map->fd, map);
	}
	if (flag == 4)
	{
		mlx_delete_image(map->mlx, map->img);
		mlx_delete_image(map->mlx, map->img2);
		mlx_terminate(map->mlx);
		error("mlx_image_to_window failed\n", map->fd, map);
	}
}

void	ft_mlx_start(t_map_data *map)
{
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->img)
		error_handling(2, map);
	map->def = mlx_load_png("bonus/sprites/idleing/1.png");
	if (!map->def)
		error("mlx_load_png failed\n", map->fd, map);
	map->img2 = mlx_texture_to_image(map->mlx, map->def);
	if (!map->img2)
		error_handling(3, map);
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) < 0)
		error("mlx_image_to_window failed\n", map->fd, map);
	if (mlx_image_to_window(map->mlx, map->img2
			, WIDTH / 2 - map->img2->width / 2
			, HEIGHT - map->img2->height) < 0)
		error("mlx_image_to_window failed\n", map->fd, map);
}

void	ft_close(void *param)
{
	t_map_data	*map;

	map = (t_map_data *)param;
	mlx_delete_image(map->mlx, map->img);
	mlx_terminate(map->mlx);
	free_allocated(&map->collected_data, map);
	exit(0);
}
