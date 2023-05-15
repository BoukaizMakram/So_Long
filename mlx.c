/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 23:02:57 by mboukaiz          #+#    #+#             */
/*   Updated: 2023/05/15 01:56:58 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message, t_data *data)
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

void	ft()
{
	system("leaks a.out");
}

int	main(int ac, char **av)
{
	atexit(ft);
	t_data	data;
	int		i;
	char	*check;

	check = ".ber";
	if (ac != 2)
	{
		ft_putstr("Arguments are invalid!");
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
			error("freed", &data);
		}
		else
			ft_putstr("file map extension is invalid!");
	}
	
}
