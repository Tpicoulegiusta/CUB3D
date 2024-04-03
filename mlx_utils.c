/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:05:19 by rbulanad          #+#    #+#             */
/*   Updated: 2024/04/03 15:11:47 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_maker(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr \
	(data->img, &data->bpp, &data->line_length, &data->endian);
}

void	window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cube");
	image_maker(data);
}

void	clear_win(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
	image_maker(data);
}

void	my_pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y >= HEIGHT || x < 0 || x >= WIDTH)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	getcolor(t_tex *tex, int x, int y)
{
	char	*color;

	color = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
	return (*(unsigned int *)color);
}
