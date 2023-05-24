/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 23:02:57 by mboukaiz          #+#    #+#             */
/*   Updated: 2023/05/24 04:17:45 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char *message, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nlines)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	ft_putstr(message);
	exit(1);
}

int key_pressed(int keycode, void *param)
{
	t_data *data_ptr;
	
	data_ptr = (t_data *)param;
    if (keycode == 13)
	{
		move(data_ptr, "UP");
	}
	if (keycode == 1)
	{
		move(data_ptr, "DOWN");
	}
	if (keycode == 0)
	{
		move(data_ptr, "LEFT");
	}
	if (keycode == 2)
	{
		move(data_ptr, "RIGHT");
	}
	return 0;
}

void	initialize(t_data *data)
{
	int	height = 64;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->nchars * 64, data->nlines* 64, "GAME");
	mlx_key_hook(data->win, key_pressed, (void *)data);
	data->sprite_0 = mlx_xpm_file_to_image(data->mlx, "image0.xpm", &height, &height);
	data->sprite_1 = mlx_xpm_file_to_image(data->mlx, "image1.xpm", &height, &height);
	data->sprite_C = mlx_xpm_file_to_image(data->mlx, "imageC.xpm", &height, &height);
	data->sprite_P = mlx_xpm_file_to_image(data->mlx, "imageP.xpm", &height, &height);
	data->sprite_E = mlx_xpm_file_to_image(data->mlx, "imageE.xpm", &height, &height);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;
	char	*check;
	int		width = 64;

	check = ".ber";
	if (ac != 2)
	{
		ft_putstr("Arguments are invalid!");
		return (1);
	}
	else
	{
		i = 0;
		while (av[1][ft_strlen(av[1]) - 4 + i]
			&& (av[1][ft_strlen(av[1]) - 4 + i] == check[i]))
		{
			i++;
		}
		if (i == 4)
		{
			parce(av[1], &data);
			i = 0;
			ft_putstr("Map is good\n");
			initialize(&data);
			draw(&data);
			mlx_loop(data.mlx);
		}
		else
		{
			ft_putstr("file map extension is invalid\n");
			return (1);
		}
	}
	
	return (0);
}
