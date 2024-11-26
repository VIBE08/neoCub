/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:45:35 by aait-lha          #+#    #+#             */
/*   Updated: 2024/10/25 02:49:16 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	}
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
