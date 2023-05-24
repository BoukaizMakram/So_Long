/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:02:09 by mboukaiz          #+#    #+#             */
/*   Updated: 2023/05/24 04:32:07 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show(t_data *data, int x, int y)
{
	
	if (data->map[x][y] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite_1, y * 64, x * 64);
	else
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprite_0, y * 64, x * 64);
	}
	if (data->map[x][y] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite_E, y * 64, x * 64);
	if (data->map[x][y] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite_C, y * 64, x * 64);
	if (data->map[x][y] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite_P, y * 64, x * 64);
	printf ("%c\n-------\n", data->map[x][y]);
}

void	draw(t_data *data)
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
				show(data, x, y);
			if (data->map[x][y] == '0')
				show(data, x, y);
			if (data->map[x][y] == 'C')
				show(data, x, y);
			if (data->map[x][y] == 'E')
				show(data, x, y);
			if (data->map[x][y] == 'P')
				show(data, x, y);
			y++;
		}
		x++;
	}
}
