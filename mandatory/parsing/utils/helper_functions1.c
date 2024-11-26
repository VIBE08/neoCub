/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hara <ael-hara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:49:52 by aait-lha          #+#    #+#             */
/*   Updated: 2024/11/26 12:13:45 by ael-hara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2, t_map_data *map)
{
	char	*s;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (s1 = NULL, NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = ft_malloc(s1_len + s2_len + 1, map);
	ft_strlcpy(s, s1, s1_len + s2_len + 1);
	ft_strlcpy(s + s1_len, s2, s1_len + s2_len + 1);
	return (s);
}

char	*ft_strdup(char *s1, t_map_data *map)
{
	int		len;
	int		i;
	char	*s2;

	len = ft_strlen(s1);
	s2 = ft_malloc(len + 1, map);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_atoi(char *number, t_map_data *map)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (ft_isdigit(number[i]))
	{
		nbr = nbr * 10 + number[i] - '0';
		i++;
	}
	if (number[i] || nbr < 0 || nbr > 255)
		error("Invalid number\n", map->fd, map);
	return (nbr);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
