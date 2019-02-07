/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 22:37:45 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/06 22:09:59 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetrimino		*head;
	char			**map;
	int				map_side;
	
	if (argc == 2)
	{
		head = read_file(argv[1]);
		//show_tetrlist(head);
		map_side = ft_sqrt(figures_count(head) * 4);
		//map_side = 5;
		map = map_creator(map_side);
		while (!fill_map(map, map_side, head))
		{
			map_resize(&map, ++map_side);
			list_reset(head);
		}
		show_map(map);
		free_map(map);
	}
	return (0);
}

int		fill_map(char **map, int map_side, t_tetrimino *tetr)
{
	if (tetr == NULL)
		return (1);
	list_reset(tetr);
	
	while(tetr->crnt_pos.y < map_side)
	{
		if (tryto_put(map, map_side, tetr))
		{
			put_tetr(map, tetr);
			if (fill_map(map, map_side, tetr->next))
				return (1);
			else
				clean_tetr(map, tetr);
		}
		shift_coordinate(map_side, tetr);
	}
	return (0);
}
