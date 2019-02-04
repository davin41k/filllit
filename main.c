/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 22:37:45 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/03 18:25:14 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetrimino		*head;
	char			**map;
	
	if (argc == 2)
	{
		head = read_file(argv[1]);
		//show_tetrlist(head);
		map = map_creator(6);
		//put_tetr(map, head);
		printf("try to put:\t%d\n", tryto_put(map, 6, head));
		show_map(map);
		free_map(map);
		//system("leaks a.out");
	}
	return (0);
}
