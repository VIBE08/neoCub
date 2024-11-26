/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:02:39 by aait-lha          #+#    #+#             */
/*   Updated: 2024/10/25 04:09:30 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_scene(t_map_data *map)
{
	map->collected_data = NULL;
	map->map = NULL;
	map->map_height = 0;
	map->elements = 0;
	map->count_colors = 2;
	map->count_textures = 4;
	map->player = ft_malloc(sizeof(t_player_data), map);
	map->textures = malloc(sizeof(t_texture_data));
	if (!map->textures)
		error("Malloc failed\n", map->fd, map);
	map->textures->texture_n = NULL;
	map->textures->texture_s = NULL;
	map->textures->texture_w = NULL;
	map->textures->texture_e = NULL;
	map->fd = 0;
	map->max_width = 0;
	map->count_directions = 0;
	map->floor = NULL;
	map->ceiling = NULL;
	map->comp1 = NULL;
	map->comp2 = NULL;
	map->player_x = 0;
	map->player_y = 0;
}
