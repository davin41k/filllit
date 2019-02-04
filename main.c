/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 22:37:45 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/04 04:47:36 by dshereme         ###   ########.fr       */
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
		map_side = 5;
		map = map_creator(map_side);
		//put_tetr(map, head);
		show_map(map);

		// map_side += 4;
		// map_resize(&map, map_side);
		// if (tryto_put(map, map_side, head))
		//  	put_tetr(map, head);

		while (!fill_map(map, map_side, head))
		{
			map_resize(&map, map_side);
			list_reset(head);
			show_map(map);
		}

		//put_tetr(map, head);
		//printf("try to put:\t%d\n", tryto_put(map, 8, head));
		show_map(map);
		//free_map(map);
		//system("leaks a.out");
	}
	return (0);
}

int		fill_map(char **map, int map_side, t_tetrimino *tetr)
{
	if (tetr == NULL)
		return (1);
	while(tetr->crnt_pos.y < map_side)
	{
		if (tryto_put(map, map_side, tetr))
		{
			put_tetr(map, tetr);
			//printf("%c\n", tetr->letter);
			if (fill_map(map, map_side, tetr->next))
			{
				return (1);
				//printf("CYCLE\n");
			}
			else
				clean_tetr(map, tetr);
		}
		shift_coordinate(map_side, tetr);
	printf("X and Y:\t%d\t%d\n", tetr->crnt_pos.x, tetr->crnt_pos.y);
	}
	return (0);
}
