/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:27:58 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/06 22:09:58 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tryto_put(char **map, int map_side, t_tetrimino *tetr)
{
	int		goals;
	int		idx;
	int		x;
	int		y;

	idx = -1;
	goals = 0;
	if (tetr->crnt_pos.x >= map_side || tetr->crnt_pos.y >= map_side)
		return (0);
	while (++idx < 4)
	{
		x = tetr->crnt_pos.x + tetr->points[idx].x;
		y = tetr->crnt_pos.y + tetr->points[idx].y;
		if (x >= map_side || y >= map_side)
			return (0);
		if (map[y][x] == '.')
			goals++;
	}
	return (goals == 4);
}

void	shift_coordinate(int map_side, t_tetrimino *tetr)
{
	int		x;
	int		y;

	x = tetr->crnt_pos.x;
	y = tetr->crnt_pos.y;
	tetr->crnt_pos.x = ++x == map_side ? 0 : x;
	tetr->crnt_pos.y = tetr->crnt_pos.x == 0 ? y + 1 : y;
}

void	put_tetr(char **map, t_tetrimino *tetr)
{
	int		idx;
	int		x;
	int		y;

	idx = -1;
	x = tetr->crnt_pos.x;
	y = tetr->crnt_pos.y;
	while (++idx < 4)
		map[y + tetr->points[idx].y][x + tetr->points[idx].x] = tetr->letter;
}

void	clean_tetr(char **map, t_tetrimino *tetr)
{
	int		idx;
	int		j;

	idx = -1;
	while (map[++idx])
	{
		j = -1;
		while (map[idx][++j])
			if (map[idx][j] == tetr->letter)
				map[idx][j] = '.';
	}
}
