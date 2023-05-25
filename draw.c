/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:02:09 by mboukaiz          #+#    #+#             */
/*   Updated: 2023/05/25 23:18:31 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show(t_data *data, int x, int y, char *direction)
{
	
	if (data->map[x][y] == '1')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprite_0, y * 64, x * 64);
		mlx_put_image_to_window(data->mlx, data->win, data->sprite_1, y * 64, x * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprite_0, y * 64, x * 64);
	}
	if (data->map[x][y] == 'E')
	{
		if (data->c_count > 0)
			mlx_put_image_to_window(data->mlx, data->win, data->sprite_E, y * 64, x * 64);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->sprite_e_open, y * 64, x * 64);
	}
	if (data->map[x][y] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite_C, y * 64, x * 64);
	if (data->map[x][y] == 'P')
	{
		if (*direction == 'U')
			mlx_put_image_to_window(data->mlx, data->win, data->sprite_p_w, y * 64, x * 64);
		if (*direction == 'D')
			mlx_put_image_to_window(data->mlx, data->win, data->sprite_p_s, y * 64, x * 64);
		if (*direction == 'L')
			mlx_put_image_to_window(data->mlx, data->win, data->sprite_p_a, y * 64, x * 64);
		if (*direction == 'R')
			mlx_put_image_to_window(data->mlx, data->win, data->sprite_p_d, y * 64, x * 64);
	}
}

void	draw(char *direction, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while(data->map[x][y])
		{
			if (data->map[x][y] == '1')
				show(data, x, y, direction);
			if (data->map[x][y] == '0')
				show(data, x, y, direction);
			if (data->map[x][y] == 'C')
				show(data, x, y, direction);
			if (data->map[x][y] == 'E')
				show(data, x, y, direction);
			if (data->map[x][y] == 'P')
				show(data, x, y, direction);
			y++;
		}
		x++;
	}
}
