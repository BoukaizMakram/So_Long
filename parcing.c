/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 02:23:00 by mboukaiz          #+#    #+#             */
/*   Updated: 2023/05/24 03:07:31 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_entities(t_data *data, int x, int y)
{
	if ((data->map[x][y] != 'C' && data->map[x][y] != 'P'
		&& data->map[x][y] != 'E' && data->map[x][y] != '1'
		&& data->map[x][y] != '0'))
	{
		ft_free("Map entities are not valid!", data);
	}
	if (data->map[x][y] == 'C')
		data->c_count++;
	if (data->map[x][y] == 'P')
	{
		data->x_cord = x;
		data->y_cord = y;
		data->p_count++;
	}
	if (data->map[x][y] == 'E')
		data->e_count++;
	return ;
}

void	valid_table(t_data *data)
{
	int	x;
	int	y;
	int	ascii;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (x == 0 || x == (data->nlines - 1) || y == 0
				|| y == (data->nchars - 1))
			{
				if (data->map[x][y] != '1')
					ft_free("Wall error", data);
			}
			check_entities(data, x, y);
			y++;
		}
		x++;
	}
	if (data->c_count <= 0 || data->p_count != 1 || data->e_count != 1)
		ft_free("Entites are invalid!", data);
	if (!back_track(data))
		ft_free("Map is impossible to win!", data);
}

void	fill_table(char *map, t_data *data)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(map, O_RDONLY);
	while (i < (data->nlines))
	{
		data->map[i++] = get_next_line(fd);
	}
	data->map[i] = NULL;
	data->coins = 0;
	valid_table(data);
}

void	allocate(char *map, t_data *data)
{
	int	i;
	int	ncheck;
	int	fd;

	i = 0;
	fd = open(map, O_RDONLY);
	while (i < (data->nlines))
	{
		data->nchars = ft_strlen(get_next_line(fd));
		if (i == 0)
			ncheck = data->nchars;
		else if (ncheck != data->nchars)
			ft_free("Bad Map!", data);
		data->map[i++] = malloc(sizeof(char) * data->nchars);
	}
	close(fd);
	fill_table(map, data);
}

void	parce(char *map, t_data *data)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd))
	{
		data->nlines++;
	}
	data->map = malloc(sizeof(char *) * ((data->nlines) + 1));
	close(fd);
	allocate(map, data);
}
