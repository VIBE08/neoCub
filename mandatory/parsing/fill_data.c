/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hara <ael-hara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:56:43 by aait-lha          #+#    #+#             */
/*   Updated: 2024/11/26 12:26:41 by ael-hara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_open(t_map_data *map, int i, int j)
{
	if (j > get_map_width(map->map[i - 1]) - 1)
		return (1);
	if (j > get_map_width(map->map[i + 1]) - 1)
		return (1);
	if (ft_isspace(map->map[i][j + 1]))
		return (1);
	if (ft_isspace(map->map[i][j - 1]))
		return (1);
	if (ft_isspace(map->map[i + 1][j]))
		return (1);
	if (ft_isspace(map->map[i - 1][j]))
		return (1);
	return (0);
}

void	check_open_spaces(t_map_data *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == '0' || map->map[i][j] == 'N' || \
			map->map[i][j] == 'S' || map->map[i][j] == 'W' || \
			map->map[i][j] == 'E')
				if (check_open(map, i, j))
					error("Open space\n", map->fd, map);
		}
	}
}

char	*skip_elements(t_map_data *map)
{
	char	*line;
	int		j;

	line = get_next_line(map->fd, map);
	j = 0;
	while (line && j < 6)
	{
		if (is_empty_line(line))
		{
			line = get_next_line(map->fd, map);
			continue ;
		}
		line = get_next_line(map->fd, map);
		j++;
	}
	while (is_empty_line(line))
		line = get_next_line(map->fd, map);
	return (line);
}

void	fill_map(t_map_data *map, char *line)
{
	int	i;
	int	j;
	int	l;

	i = -1;
	while (++i < map->map_height)
	{
		l = get_map_width(line);
		map->map[i] = ft_malloc(l + 1, map);
		j = 0;
		while (line[j])
		{
			map->map[i][j] = line[j];
			j++;
		}
		map->map[i][j] = '\0';
		line = get_next_line(map->fd, map);
	}
}

void	fill_matrix(char *file, t_map_data *map)
{
	char	*line;

	map->map = ft_malloc(sizeof(char *) * \
	(map->map_height), map);
	map->fd = open(file, O_RDONLY);
	if (map->fd < 0)
		error("Can't open the file\n", map->fd, map);
	line = skip_elements(map);
	fill_map(map, line);
	check_open_spaces(map);
	close(map->fd);
}
