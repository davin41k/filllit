/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_coordinate_tetrimino.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 21:35:00 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/03 04:24:35 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	create_tetrlist(t_tetrimino **head, char *line)
{
				
	t_tetrimino		*node;
	t_tetrimino 	*start;

	start = *head;
	if (*head == NULL)
		*head = to_coordinate(line);
	else
	{
		node = to_coordinate(line);
		while(start->next)
			start = start->next; // Правельное разыменовывание?
		start->next = node;
	}
}

//полностью с строки тетримино вовращает полноценную
//структуру с правильными координатами
t_tetrimino		*to_coordinate(char *tetr)
{
	t_tetrimino		*newtetr;
	int		idx;
	int		newline;
	int		point;

	shift_figure(tetr);
	newtetr = ft_tetrnew();
	idx = -1;
	newline = 0;
	point = 0;
	while (tetr[++idx])
	{
		if (point == 4) // чтобы не шел по пустым точкам, спорно
			break;
		if (tetr[idx] == '\n')
			newline++;
		if (tetr[idx] == '#')
		{
			newtetr->points[point].x = idx - newline * 5;
			newtetr->points[point].y = newline;
			point++;
		}
	}
	normalizate_coordinate(newtetr);
	return (newtetr);
}

/*нулит некст и записывает нужную букву*/
t_tetrimino		*ft_tetrnew()
{
	static	char	letter = 'A';
	t_tetrimino		*newtetr;

	if (!(newtetr = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
		return (NULL);
	newtetr->crnt_pos.x = 0;
	newtetr->crnt_pos.y = 0;	
	newtetr->letter = letter++;
	newtetr->next = NULL;
	return(newtetr);
}

void	normalizate_coordinate(t_tetrimino *tetr)
{
	int		idx;
	int		first_x;
	int		first_y;

	idx = -1;
	first_x = tetr->points[0].x;
	first_y = tetr->points[0].y;
	while(++idx < 4)
	{
		tetr->points[idx].x -= first_x;
		tetr->points[idx].y -= first_y;
	}
}

void	show_coordinate(t_tetrimino *tetr)
{
	int		idx;

	idx = -1;
	printf("\tLetter:\t%c\n", tetr->letter);
	while (++idx < 4)
	{
		printf("X ->\t%d\tY -> %d\n", tetr->points[idx].x, tetr->points[idx].y);
	}
}

void	show_tetrlist(t_tetrimino *head)
{
	while (head)
	{
		show_coordinate(head);
		head = head->next;
	}
}