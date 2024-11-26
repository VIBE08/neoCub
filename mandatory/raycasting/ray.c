/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hara <ael-hara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:53:13 by ael-hara          #+#    #+#             */
/*   Updated: 2024/11/26 12:16:01 by ael-hara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rendering_logic(t_map_data *map, double *angle, int i)
{
	double			wall_height;
	double			start;
	int				*image_px;

	min_intersection(map, map->player->po_x, map->player->po_y, *angle);
	map->player->distance = correct_distance(map->player->distance,
			*angle, map->player->player_angle);
	wall_height = wall_projection(map);
	start = floor(HEIGHT / 2 - wall_height / 2);
	map->choosen_texture = choose_texture(map, *angle);
	image_px = (int *)map->choosen_texture->pixels;
	get_xcord(map, map->choosen_texture);
	draw_line(map, i, wall_height, image_px);
	*angle += map->player->ray_distance;
}

void	draw_ray(void *param)
{
	t_map_data	*map;
	int			i;
	double		angle;

	map = (t_map_data *)param;
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (map->img == NULL)
		error_handling(2, map);
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) < 0)
		error_handling(4, map);
	i = 0;
	angle = map->player->player_angle - ((FOV / 2) * (PI / 180));
	if (angle < 0)
		angle = 2 * PI + angle;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	background(map);
	while (i < WIDTH)
	{
		rendering_logic(map, &angle, i);
		i++;
	}
}
