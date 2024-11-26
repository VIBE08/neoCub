/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:02:39 by aait-lha          #+#    #+#             */
/*   Updated: 2024/10/25 19:19:13 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	init_scene(t_map_data *map)
{
	map->map = NULL;
	map->collected_data = NULL;
	map->def = NULL;
	map->map_height = 0;
	map->elements = 0;
	map->count_colors = 2;
	map->count_textures = 4;
	map->player = ft_malloc(sizeof(t_player_data), map);
	map->textures = malloc(sizeof(t_texture_data));
	if (!map->textures)
		error("Memory allocation failed\n", map->fd, map);
	(1) & (map->fd = 0) && (map->max_width = 0);
	map->count_directions = 0;
	map->textures->texture_n = NULL;
	map->textures->texture_s = NULL;
	map->textures->texture_w = NULL;
	map->textures->texture_e = NULL;
	map->shot_sprites = NULL;
	map->reload_sprites = NULL;
	map->floor = NULL;
	map->ceiling = NULL;
	map->comp1 = NULL;
	map->comp2 = NULL;
	map->player_x = 0;
	map->player_y = 0;
}

void	*ft_lstnew(void *content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_node **list, t_node *new)
{
	t_node	*last;

	if (!*list)
	{
		*list = new;
		return ;
	}
	last = *list;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	free_allocated(t_node **garbage_collector, t_map_data *map)
{
	t_node	*tmp;

	while (*garbage_collector)
	{
		tmp = (*garbage_collector)->next;
		free((*garbage_collector)->content);
		free(*garbage_collector);
		*garbage_collector = tmp;
	}
	free_textures(map);
	free_shot_sprites(map);
	free_reload_sprites(map);
}

void	*ft_malloc(size_t size, t_map_data *map)
{
	void	*ptr;
	t_node	*new_node;

	ptr = malloc(size);
	if (!ptr)
		error("malloc", map->fd, NULL);
	new_node = ft_lstnew(ptr);
	if (!new_node)
	{
		free(ptr);
		error("malloc", map->fd, NULL);
	}
	ft_lstadd_back(&map->collected_data, new_node);
	return (ptr);
}
