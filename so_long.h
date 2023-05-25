/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:53:27 by mboukaiz          #+#    #+#             */
/*   Updated: 2023/05/26 00:26:34 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "gnl/get_next_line.h"

typedef struct table_data
{
	int		nlines;
	int		nchars;
	int		coins;
	int		c_count;
	int		p_count;
	int		e_count;
	int		x_cord;
	int		y_cord;
	int		nom;

	char	**map;
	char	**map_dup;
	void	*win;
	void	*mlx;
	void	*sprite_0;
	void	*sprite_1;
	void	*sprite_C;
	void	*sprite_E;
	void	*sprite_e_open;
	void	*sprite_p_s;
	void	*sprite_p_d;
	void	*sprite_p_a;
	void	*sprite_p_w;
}	t_data;

void	parce(char *map, t_data *data);
void	ft_free(char *message, t_data *data);
int		back_track(t_data *data);
void	move(t_data *data, char *direction);
void	draw(char *direction, t_data *data);
char	*get_next_line(int fd);
void	ft_putnbr(int nb);
#endif