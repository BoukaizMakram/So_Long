/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:51:15 by mboukaiz          #+#    #+#             */
/*   Updated: 2023/05/18 17:29:59 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_str(char *str)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tab = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!tab)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i])
		tab[j++] = str[i++];
	tab[j] = '\0';
	free(str);
	return (tab);
}

char	*ft_line(char *str)
{
	int		i;
	char	*tab;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	tab = (char *)malloc(sizeof(char) * (i + 2));
	if (!tab)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_allocate(int fd, char *str)
{
	char	*buffer;
	int		readed;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readed = 1;
	while ((!ft_strchr(str, '\n')) && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_allocate(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_next_str(str);
	return (line);
}
