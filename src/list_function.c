/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 23:25:36 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/06 22:14:54 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	list_reset(t_tetrimino *tetr)
{
	while (tetr)
	{
		tetr->crnt_pos.x = 0;
		tetr->crnt_pos.y = 0;
		tetr = tetr->next;
	}
}

int		figures_count(t_tetrimino *head)
{
	int		count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
