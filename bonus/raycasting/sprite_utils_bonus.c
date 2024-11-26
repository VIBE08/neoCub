/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hara <ael-hara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:47:41 by aait-lha          #+#    #+#             */
/*   Updated: 2024/11/26 12:24:26 by ael-hara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	load_shot_sprites(t_map_data *map)
{
	int		i;
	char	*join1;
	char	*join2;
	char	*nbr;

	map->shot_sprites = malloc(sizeof(t_texture_data *) * SHOT_FRAMES);
	if (!map->shot_sprites)
		error("Memory allocation failed\n", map->fd, map);
	ft_memset(map->shot_sprites, 0, sizeof(t_texture_data *) * SHOT_FRAMES);
	i = 0;
	while (i < SHOT_FRAMES)
	{
		nbr = ft_itoa(i + 1, map);
		join1 = ft_strjoin2("bonus/sprites/fireing/", nbr, map);
		join2 = ft_strjoin2(join1, ".png", map);
		map->shot_sprites[i] = (t_texture_data *)mlx_load_png(join2);
		if (!map->shot_sprites[i])
		{
			mlx_delete_image(map->mlx, map->img);
			mlx_delete_image(map->mlx, map->img2);
			mlx_terminate(map->mlx);
			error("Mlx load png failed\n", map->fd, map);
		}
		i++;
	}
}

void	load_reload_sprites(t_map_data *map)
{
	int		i;
	char	*join1;
	char	*join2;
	char	*nbr;

	map->reload_sprites = malloc(sizeof(t_texture_data *) * RELOAD_FRAMES);
	if (!map->reload_sprites)
		error("Memory allocation failed\n", map->fd, map);
	i = 0;
	while (i < RELOAD_FRAMES)
	{
		nbr = ft_itoa(i + 1, map);
		join1 = ft_strjoin2("bonus/sprites/reloading/", nbr, map);
		join2 = ft_strjoin2(join1, ".png", map);
		map->reload_sprites[i] = (t_texture_data *)mlx_load_png(join2);
		if (!map->reload_sprites[i])
		{
			mlx_delete_image(map->mlx, map->img);
			mlx_delete_image(map->mlx, map->img2);
			mlx_terminate(map->mlx);
			error("Mlx load png failed\n", map->fd, map);
		}
		i++;
	}
}
