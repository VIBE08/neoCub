/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hara <ael-hara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:45:35 by aait-lha          #+#    #+#             */
/*   Updated: 2024/11/26 12:18:43 by ael-hara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	free_shot_sprites(t_map_data *map)
{
	int	i;

	i = 0;
	while (map->shot_sprites && i < SHOT_FRAMES)
	{
		if (map->shot_sprites[i])
			mlx_delete_texture((mlx_texture_t *)map->shot_sprites[i]);
		i++;
	}
	free(map->shot_sprites);
}

void	free_reload_sprites(t_map_data *map)
{
	int	i;

	i = 0;
	while (map->reload_sprites && i < RELOAD_FRAMES)
	{
		if (map->reload_sprites[i])
			mlx_delete_texture((mlx_texture_t *)map->reload_sprites[i]);
		i++;
	}
	free(map->reload_sprites);
}

void	free_textures(t_map_data *map)
{
	if (map->textures)
	{
		if (map->textures->texture_n)
			mlx_delete_texture(map->textures->texture_n);
		if (map->textures->texture_s)
			mlx_delete_texture(map->textures->texture_s);
		if (map->textures->texture_w)
			mlx_delete_texture(map->textures->texture_w);
		if (map->textures->texture_e)
			mlx_delete_texture(map->textures->texture_e);
		map->textures->texture_n = NULL;
		map->textures->texture_s = NULL;
		map->textures->texture_w = NULL;
		map->textures->texture_e = NULL;
		free(map->textures);
		map->textures = NULL;
	}
}
