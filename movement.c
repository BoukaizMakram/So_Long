#include "so_long.h"

void	print_map(t_data *data)
{
	int i = 0;
	while(i < data->nlines)
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	printf("-------\n");
}

void	Update(t_data *data, int x, int y)
{
	if (data->map[x][y] != '1' && data->map[x][y] != 'E')
	{
		if (data->map[x][y] == 'C')
			data->c_count--;
		data->map[x][y] = 'P';
		data->map[data->x_cord][data->y_cord] = '0';
		data->x_cord = x;
		data->y_cord = y;
		print_map(data);
		draw(data);
	}
	else if (data->map[x][y] == 'E' && data->c_count == 0)
	{
		data->map[x][y] = 'P';
		data->map[data->x_cord][data->y_cord] = '0';
		ft_free("YOU WON", data);
	}
}

void	move(t_data *data, char *direction)
{
	int	x;
	int	y;

	if (*direction == 'U')
	{
		x = data->x_cord - 1;
		y = data->y_cord;
	}
	else if (*direction == 'D')
	{
		x = data->x_cord + 1;
		y = data->y_cord;
	}
	else if (*direction == 'L')
	{
		x = data->x_cord;
		y = data->y_cord - 1;
	}
	else if (*direction == 'R')
	{
		x = data->x_cord;
		y = data->y_cord + 1;
	}
	Update(data, x, y);
}
