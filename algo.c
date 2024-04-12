/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:45:28 by rbulanad          #+#    #+#             */
/*   Updated: 2024/04/12 14:24:37 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pre_dda(t_data *data)
{
	if (data->raydir_x < 0)
	{
		data->step_x = -1;
		data->sidedist_x = (data->pos_x - data->map_x) * data->deltadistx;
	}
	else
	{
		data->step_x = 1;
		data->sidedist_x = (data->map_x + 1.0 - data->pos_x) * data->deltadistx;
	}
	if (data->raydir_y < 0)
	{
		data->step_y = -1;
		data->sidedist_y = (data->pos_y - data->map_y) * data->deltadisty;
	}
	else
	{
		data->step_y = 1;
		data->sidedist_y = (data->map_y + 1.0 - data->pos_y) * data->deltadisty;
	}
}

void	dda_algo(t_data *data, int **Map)
{
	while (data->hit == 0)
	{
		if (data->sidedist_x < data->sidedist_y)
		{
			data->sidedist_x += data->deltadistx;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->sidedist_y += data->deltadisty;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (Map[data->map_x][data->map_y] > 0)
			data->hit = 1;
	}
}

void	map_render(t_data *data, int **Map)
{
	if (data->side == 0)
		data->perpwalldist = (data->sidedist_x - data->deltadistx);
	else
		data->perpwalldist = (data->sidedist_y - data->deltadisty);
	data->lineheight = (int)(HEIGHT / data->perpwalldist);
	data->drawstart = (-(data->lineheight) / 2) + (HEIGHT / 2);
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = (data->lineheight / 2) + (HEIGHT / 2);
	if (data->drawend >= HEIGHT)
		data->drawend = HEIGHT - 1;
	data->texnum = Map[data->map_x][data->map_y] - 1;
	if (data->side == 0)
		data->wall_x = data->pos_y + data->perpwalldist * data->raydir_y;
	else
		data->wall_x = data->pos_x + data->perpwalldist * data->raydir_x;
	data->wall_x -= floor(data->wall_x);
}

void	texture_render(t_data *data)
{
	data->tex_x = (int)(data->wall_x * (double)TEXWIDTH);
	if (data->side == 0 && data->raydir_x > 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
	if (data->side == 1 && data->raydir_y < 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
	data->step = 1.0 * TEXHEIGHT / data->lineheight;
	data->tex_pos = (data->drawstart - HEIGHT / 2 + data->lineheight / 2) \
		* data->step;
	data->y2 = data->drawstart;
	while (data->y2 < data->drawend)
	{
		data->tex_y = (int)data->tex_pos & (TEXHEIGHT - 1);
		data->tex_pos += data->step;
		walls_render(data);
		if (data->side == 1)
			data->color = (data->color >> 1) & 8355711;
		my_pixelput(data, data->x, data->y2, data->color);
		data->y2++;
	}
}

void	walls_render(t_data *data)
{
	if (data->side == 0 && data->raydir_x < 0)
		data->color = getcolor(&data->tex_n, data->tex_x, data->tex_y);
	else if (data->side == 0 && data->raydir_x > 0)
	{
		if (data->map_x == 23 && data->map_y == 11)
			data->color = getcolor(&data->tex_s2, data->tex_x, data->tex_y);
		else
			data->color = getcolor(&data->tex_s, data->tex_x, data->tex_y);
	}
	else if (data->side == 1 && data->raydir_y > 0)
	{
		if (data->map_x == 8 && data->map_y == 20)
			data->color = getcolor(&data->tex_e2, data->tex_x, data->tex_y);
		else
			data->color = getcolor(&data->tex_e, data->tex_x, data->tex_y);
	}
	else if (data->side == 1 && data->raydir_y < 0)
		data->color = getcolor(&data->tex_w, data->tex_x, data->tex_y);
}
