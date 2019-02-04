/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:27:58 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/03 18:40:09 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//проба поставить фигуру на позицию current position
//в конце если не удалось поставить, то crnt_pos уеличивается на х + 1
//будет рекурсивно вызиваться... нужно продумать ключ возврата если
//нет места на карте вообще
int		tryto_put(char  **map, int map_side, t_tetrimino *tetr)
{
	int		goals;
	int		idx;
	int		x; //i
	int		y; //j

	idx = -1;
	goals = 0;
	tetr->crnt_pos.x = 5;
	tetr->crnt_pos.y = 2;
	if (tetr->crnt_pos.x >= map_side || tetr->crnt_pos.y >= map_side)
	{
		printf("X:\t%d\tY:\t%d\t\tmap_side:\t%d\n", x, y, map_side);
		 return (-1);
	}
	while (++idx < 4)
	{
		x = tetr->crnt_pos.x + tetr->points[idx].x;
		y = tetr->crnt_pos.y + tetr->points[idx].y;
		printf("x and y:\t%d\t%d\n", tetr->points[idx].x, tetr->points[idx].y);
		if (x >= map_side || y >= map_side)
			return (0);	
		if (map[y][x] == '.')
			goals++;
	}
	printf("\ngoals:\t%d\n", goals);
	printf("Hello\n");
	x = tetr->crnt_pos.x;
	y = tetr->crnt_pos.y;
	tetr->crnt_pos.x = ++x == map_side ? 0 : x; //варниниг конструкция
	tetr->crnt_pos.y = x == 0 ? y + 1 : y;
	printf("crnt_X:\t%d\tcrnt_Y:\t%d\t\tmap_side:\t%d\n", tetr->crnt_pos.x, tetr->crnt_pos.y, map_side);
	if (y == map_side)
	return (-1);	
	printf("\ngoals:\t%d\n", goals);
	return(goals == 4 ? 1 : 0);
}

void	put_tetr(char **map, t_tetrimino *tetr)
{
	int		idx;
	int		x;
	int		y;

	tetr = tetr->next->next->next;
	idx = -1;
	// x = tetr->crnt_pos.x - 1;
	// y = tetr->crnt_pos.y - 1;
	x = 1;
	y = 1;
	
	while (++idx < 4)
	{
		// x = tetr->points[idx].x;
		// y = tetr->points[idx].y;
		map[y + tetr->points[idx].y][x + tetr->points[idx].x] = tetr->letter;
	}
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
