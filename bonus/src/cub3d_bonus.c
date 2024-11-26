/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:25:11 by aait-lha          #+#    #+#             */
/*   Updated: 2024/10/31 17:26:45 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_map_data	map;

	if (argc != 2)
	{
		write (2, "Error\n", 6);
		write (2, "Usage: ./cub3d map.cub\n", 22);
		return (1);
	}
	init_scene(&map);
	check_file_extention(argv[1], &map);
	load_file(argv[1], &map);
	fill_matrix(argv[1], &map);
	raycasting_scene(&map);
	return (0);
}
