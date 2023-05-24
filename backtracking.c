#include "so_long.h"
int	check_path(t_data *data, int x, int y, char entity)
{
	if (data->map_dup[x][y] == '1' || (data->map_dup[x][y] == 'E'
		&& entity != 'E'))
		return (0);
	if (data->map_dup[x][y] == 'P')
		return (1);
	data->map_dup[x][y] = '1';
	if (check_path(data, x + 1, y, entity))
		return (1);
	if (check_path(data, x - 1, y, entity))
		return (1);
	if (check_path(data, x, y + 1, entity))
		return (1);
	if (check_path(data, x, y - 1, entity))
		return (1);
	return (0);
}

void	copy_map(t_data *data)
{
	int	x;

	x = 0;
	data->map_dup = malloc(sizeof(char *) * (data->nlines + 1));
	while (x < data->nlines)
		data->map_dup[x++] = malloc(sizeof(char) * (data->nchars + 1));
	x = 0;
	while (x < data->nlines)
	{
		data->map_dup[x] = ft_strdup(data->map[x]);
		x++;
	}
}

int	back_track(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'C' || data->map[x][y] == 'E')
			{
				copy_map (data);
				if (!check_path(data, x, y, data->map[x][y]))
				{
					return (0);
				}
			}
			y++;
		}
		x++;
	}
	return (1);
}