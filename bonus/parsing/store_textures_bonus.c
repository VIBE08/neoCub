/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:37:03 by aait-lha          #+#    #+#             */
/*   Updated: 2024/10/25 18:48:09 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	store_we_ea(char *type, char *path, t_map_data *map)
{
	if (ft_strncmp(type, "WE", 2) == 0)
	{
		if (map->textures->texture_w)
			mlx_delete_texture(map->textures->texture_w);
		map->textures->texture_w = mlx_load_png(ft_strdup(path, map));
		if (!map->textures->texture_w)
			error("Texture not found\n", map->fd, map);
	}
	else if (ft_strncmp(type, "EA", 2) == 0)
	{
		if (map->textures->texture_e)
			mlx_delete_texture(map->textures->texture_e);
		map->textures->texture_e = mlx_load_png(ft_strdup(path, map));
		if (!map->textures->texture_e)
			error("Texture not found\n", map->fd, map);
	}
}

void	store_no_so(char *type, char *path, t_map_data *map)
{
	if (ft_strncmp(type, "NO", 2) == 0)
	{
		if (map->textures->texture_n)
			mlx_delete_texture(map->textures->texture_n);
		map->textures->texture_n = mlx_load_png(ft_strdup(path, map));
		if (!map->textures->texture_n)
			error("Texture not found\n", map->fd, map);
	}
	else if (ft_strncmp(type, "SO", 2) == 0)
	{
		if (map->textures->texture_s)
			mlx_delete_texture(map->textures->texture_s);
		map->textures->texture_s = mlx_load_png(ft_strdup(path, map));
		if (!map->textures->texture_s)
			error("Texture not found\n", map->fd, map);
	}
}
