/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:40:20 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/12 14:21:40 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verline(t_data *data, int start, int end, int color)
{
	int	y;

	y = start;
	while (y <= end)
		my_pixelput(data, data->x, y++, color);
}

void	ceiling_floor(t_data *data, int height)
{
	data->ceiling = create_trgb(0, 84, 161, 255);
	data->floor = create_trgb(0, 135, 70, 14);
	verline(data, 0, height / 2, data->ceiling);
	verline(data, height / 2, height, data->floor);
}

void	ft_draw(t_data *data)
{
	algo_init(data);
	pre_dda(data);
	dda_algo(data, data->map);
	map_render(data, data->map);
	texture_render(data);
}

void	raycast(t_data *data)
{
	data->x = -1;
	while (++data->x < WIDTH)
	{
		ceiling_floor(data, HEIGHT);
		ft_draw(data);
		data->movespeed = 0.08;
		data->rotspeed = 0.05;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	main(void)
{
	t_data	data;

	data_init(&data);
	window(&data);
	tex_init(&data.tex_n, data.mlx);
	tex_init(&data.tex_s, data.mlx);
	tex_init(&data.tex_s2, data.mlx);
	tex_init(&data.tex_e, data.mlx);
	tex_init(&data.tex_e2, data.mlx);
	tex_init(&data.tex_w, data.mlx);
	raycast(&data);
	hooks(&data);
	mlx_loop(data.mlx);
}
