/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:30:43 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/02 21:23:08 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**map_creator(int figures)
{
	char	**map;
	int		idx;
	int		j;
	int		side;

	side = ft_sqrt(figures) * 2;
	idx = -1;
	map = (char **)malloc(sizeof(char**) * side + 1);
	map[side] = NULL; // Чистить ли нулл?
	while (++idx < side)
	{
		j = -1;
		map[idx] = ft_strnew(side);
		while (++j < side)
			map[idx][j] = '.';
	}
	return (map);
}

void	free_map(char **map)
{
	int		idx;
	
	idx = -1;
	while(map[++idx])
		free(map[idx]);
	free(map);
}

void	show_map(char **map)
{
	while(*map)
	{
		printf("%s\n", *map);
		map++;
	}
}

int		ft_sqrt(int nb)
{
	int	re;

	re = 1;
	while (re * re < nb)
		re++;
	return (re * re == nb ? re : ++re);
}
