/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_tetrimino.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 22:37:35 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/07 19:33:14 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*возвращает указатель на голову списка из координат*/
t_tetrimino		*read_file(char *filename)
{
	char		*line;
	int			fd;
	int			ret;
	t_tetrimino	*head;

	fd = open(filename, O_RDONLY);
	line = ft_strnew(21);
	head = NULL;
	while ((ret = read(fd, line, 21)))
	{
		line[ret] = '\0';
		if (tetrimino_norme(line))
			create_tetrlist(&head, line);
		else
		{
			printf("Wrong tetrimino\n");
			exit(0);
		}
	}
	close(fd);
	free(line);
	return (head);
}

void			shift_figure(char *tetr)
{
	int		idx;
	int		shiftx;
	int		shifty;

	idx = -1;
	shiftx = shift_x(tetr);
	shifty = shift_y(tetr);
	while (tetr[++idx])
	{
		if (tetr[idx] == '#')
		{
			tetr[idx] = '.';
			tetr[idx - shiftx - shifty * 5] = '#';
		}
	}
}

int				shift_x(char *tetr)
{
	int		shift;
	int		idx;
	int		lines;

	idx = -1;
	shift = 10;
	lines = 0;
	while (tetr[++idx])
	{
		if (tetr[idx] == '#')
			if (shift > (idx - lines))
				shift = (idx - lines);
		if (tetr[idx] == '\n')
			lines += 5;
	}
	idx = -1;
	return (shift);
}

int				shift_y(char *tetr)
{
	int		lineas;

	lineas = 0;
	while (*tetr)
	{
		if (*tetr == '#')
			break ;
		lineas++;
		tetr++;
	}
	return (lineas / 5);
}
