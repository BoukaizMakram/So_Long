#include "mlx.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include<unistd.h>


typedef struct t_data
{
	void *win;
	void *mlx;
	void *img_1;
	void *img_0;
	void *img_C;
	int length;
	int width;
	int height;
}	s_data;

void	draw(s_data *data, char *str)
{
	printf("called\n");
	int i = 0;
	while (str[i])
	{
		if (str[i] == '1')
		{
			printf("1");
			mlx_put_image_to_window(data->mlx, data->win, data->img_1, i * 64, 0);
		}
		else if (str[i] == '0')
		{
			printf("0");
			mlx_put_image_to_window(data->mlx, data->win, data->img_0, i * 64, 0);
		}else if (str[i] == 'C')
		{
			printf("C");
			mlx_put_image_to_window(data->mlx, data->win, data->img_C, i * 64, 0);
		}
		i++;
	}
	printf("\n");
}

void init(s_data *data, char *str)
{
	data->length = strlen(str) * 64;
	data->width = 64;
	data->height = 64;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->length, 64, "XPM Image");
	data->img_1 = mlx_xpm_file_to_image(data->mlx, "image1.xpm", &data->width, &data->height);
	data->img_0 = mlx_xpm_file_to_image(data->mlx, "image0.xpm", &data->width, &data->height);
	data->img_C = mlx_xpm_file_to_image(data->mlx, "imageC.xpm", &data->width, &data->height);
}

int main()
{
	char str[13] = "111000111CCC";

	s_data data;
	init(&data, str);
	draw(&data, str);
	usleep(200);
	str[0] = '0';
	draw(&data, str);
	mlx_loop(data.mlx);
}