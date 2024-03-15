/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:54:04 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/14 15:54:47 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_strjoinfree(char *stock, char *tmp)
{
	char	*str;

	if (!stock)
	{
		stock = malloc(sizeof(char) * 1);
		stock[0] = '\0';
	}
	str = ft_strjoin(stock, tmp);
	if (stock)
		free(stock);
	return (str);
}

static char	*ft_get_stocked(int fd, char *stock)
{
	char			*buf;
	int				ret_read;

	buf = ft_calloc(BUFFER_SIZE, ret_read = 1);
	if (buf == NULL)
		return (NULL);
	while (ret_read != 0 && !ft_strchr(stock, '\n'))
	{
		ret_read = read(fd, buf, BUFFER_SIZE);
		if (ret_read < 0)
			return (NULL);
		buf[ret_read] = '\0';
		stock = ft_strjoinfree(stock, buf);
	}
	return (free(buf), stock);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*stock;
	int				i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (stock)
			return (free(stock), stock = NULL, NULL);
		return (NULL);
	}
	stock = ft_get_stocked(fd, stock);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	line = ft_substr2(stock, 0, i);
	if (ft_strlen(line) == 0)
		return (free(stock), stock = NULL, free(line), NULL);
	stock = ft_substr2(stock, i, ft_strlen(stock));
	return (line);
}