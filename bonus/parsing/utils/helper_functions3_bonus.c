/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hara <ael-hara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 05:46:36 by aait-lha          #+#    #+#             */
/*   Updated: 2024/11/26 12:18:51 by ael-hara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n, t_map_data *map)
{
	char	*str;
	int		i;
	int		len;

	len = ft_nbrlen(n);
	str = ft_malloc(sizeof(char) * (len + 1), map);
	i = len - 1;
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_strjoin2(char *s1, char *s2, t_map_data *map)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = ft_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1), map);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}
