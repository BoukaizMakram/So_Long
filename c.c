#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"



int main()
{
	char *str;
	int fd;
	fd = open("maps/map2.ber", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	while (1)
	{

	}
	return (0);
}