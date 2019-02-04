/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:10:09 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/04 03:57:35 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <unistd.h>
# define MALDEF(x) if (!x) return (NULL);

typedef	struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef	struct			s_tetrimino
{
	t_point				points[4];
	t_point				crnt_pos;
	char				letter;
	struct s_tetrimino	*next;
}						t_tetrimino;

int						read_figure(int fd, char **str);
t_tetrimino				*read_file(char *filename);
int						tetrimino_norme(char *tetr);
int						newline_norme(char *tetr);
int						dots_norme(char *tetr);
int						grids_count(char *tetr);
int						grids_norme(char *tetr);
int						shift_x(char *tetr);
int						shift_y(char *tetr);
void					shift_figure(char *tetr);
t_tetrimino				*ft_tetrnew();
t_tetrimino				*to_coordinate(char *tetr);
void					show_coordinate(t_tetrimino *tetr);
void					normalizate_coordinate(t_tetrimino *tetr);
t_tetrimino				*new_tetrnode(char *line);
void					add_tetrnode(t_tetrimino **head, char *line);
void					create_tetrlist(t_tetrimino **head, char *line);
void					show_tetrlist(t_tetrimino *head);
char					**map_creator(int side);
void					show_map(char **map);
void					free_map(char **map);
int						ft_sqrt(int nb);
int						tryto_put(char **map, int map_side, t_tetrimino *tetr);
void					put_tetr(char **map, t_tetrimino *tetr);
void					clean_tetr(char **map, t_tetrimino *tetr);
void					shift_coordinate(int map_side, t_tetrimino *tetr);
void					map_resize(char ***map, int	map_side);
int						fill_map(char **map, int map_side, t_tetrimino *tetr);
void					list_reset(t_tetrimino *tetr);
int						figures_count(t_tetrimino *head);

#endif
