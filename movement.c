#include "so_long.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	Update(t_data *data, int x, int y, char *direction)
{
	if (data->map[x][y] != '1' && data->map[x][y] != 'E')
	{
		if (data->map[x][y] == 'C')
			data->c_count--;
		data->map[x][y] = 'P';
		data->map[data->x_cord][data->y_cord] = '0';
		data->x_cord = x;
		data->y_cord = y;
		ft_putnbr(++data->nom);
		ft_putstr("\n");
	}
	else if (data->map[x][y] == 'E' && data->c_count == 0)
	{
		data->map[x][y] = 'P';
		data->map[data->x_cord][data->y_cord] = '0';
		ft_putnbr(++data->nom);
		ft_free("\nYOU WON", data);
	}
	draw(direction, data);
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
	else
	{
		x = data->x_cord;
		y = data->y_cord + 1;
	}
	Update(data, x, y, direction);
}
