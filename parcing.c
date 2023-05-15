/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 02:23:00 by mboukaiz          #+#    #+#             */
/*   Updated: 2023/05/15 02:49:47 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_entities(t_data *data, int x, int y)
{
	if (data->map[x][y] != 'C' && data->map[x][y] != 'P'
		&& data->map[x][y] != 'E' && data->map[x][y] != '1'
		&& data->map[x][y] != '0')
	{
		error("Map entities are not valid!", data);
	}
	if (data->map[x][y] == 'C')
		data->C_count++;
	if (data->map[x][y] == 'P')
		data->P_count++;
	if (data->map[x][y] == 'E')
		data->E_count++;
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
					error("Wall error", data);
			}
			check_entities(data, x, y);
			y++;
		}
		x++;
	}
	if (data->C_count <= 0 || data->P_count != 1 || data->E_count != 1)
		error ("Entites are invalid!", data);
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
			error("Bad Map!", data);
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
