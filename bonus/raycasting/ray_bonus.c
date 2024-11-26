/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hara <ael-hara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:11:14 by ael-hara          #+#    #+#             */
/*   Updated: 2024/11/26 12:23:05 by ael-hara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
	ft_memset(map->img->pixels, 0, map->img->width
		* map->img->height * sizeof(int32_t));
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
