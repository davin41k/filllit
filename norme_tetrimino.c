/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 22:07:38 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/06 22:09:58 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetrimino_norme(char *tetr)
{
	if (newline_norme(tetr) && dots_norme(tetr) && grids_norme(tetr))
		return (1);
	return (0);
}

int		newline_norme(char *tetr)
{
	int		newlines;
	int		idx;

	if (*tetr == '\n')
		return (0);
	newlines = 0;
	idx = -1;
	while (tetr[++idx])
	{
		if (tetr[idx] == '\n')
			newlines++;
	}
	if (tetr[idx - 2] == '\n')
		newlines--;
	return (newlines == 4 ? 1 : 0);
}

int		dots_norme(char *tetr)
{
	int		dots;
	int		idx;

	dots = 0;
	idx = -1;
	while (tetr[++idx])
	{
		if (tetr[idx] == '.')
			dots++;
	}
	return (dots == 12 ? 1 : 0);
}

int		grids_count(char *tetr)
{
	int		grids;
	int		idx;

	grids = 0;
	idx = -1;
	while (tetr[++idx])
	{
		if (tetr[idx] == '#')
			grids++;
	}
	return (grids == 4 ? 1 : 0);
}

int		grids_norme(char *tetr)
{
	int		idx;
	int		line;
	int		frends;

	if (!grids_count(tetr))
		return (0);
	idx = -1;
	line = 1;
	frends = 0;
	while (tetr[++idx])
	{
		if (tetr[idx] == '#')
		{
			if (idx != 0 && tetr[idx - 1] == '#')
				frends++;
			if (tetr[idx + 1] == '#')
				frends++;
			if (line != 1 && tetr[idx - 5] == '#')
				frends++;
			if (line != 4 && tetr[idx + 5] == '#')
				frends++;
		}
		if (tetr[idx] == '\n')
			line++;
	}
	return ((frends == 6 || frends == 8) ? 1 : 0);
}
