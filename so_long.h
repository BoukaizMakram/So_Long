/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:53:27 by mboukaiz          #+#    #+#             */
/*   Updated: 2023/05/15 02:51:05 by mboukaiz         ###   ########.fr       */
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
# include "gnl2/get_next_line.h"

typedef struct my_data
{
	int	nlines;
	int	nchars;
	int	C_count;
	int	P_count;
	int	E_count;
	char **map;
}	t_data;

void	parce(char *map, t_data *data);
void	error(char *message, t_data *data);
void ft_free(t_data *data);
#endif