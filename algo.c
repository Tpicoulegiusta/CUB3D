/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:45:28 by rbulanad          #+#    #+#             */
/*   Updated: 2024/04/03 14:36:10 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pre_dda(t_data *data)
{
	//calc step and initial sideDist
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

void	dda_algo(t_data *data, int Map[24][24])
{
	while (data->hit == 0)
	{
		//jump to next map square either in x or y direction
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
		//Check if ray hit a wall
		if (Map[data->map_x][data->map_y] > 0)
			data->hit = 1;
	}
}

void	map_render(t_data *data, int Map[24][24])
{
	//calc distance projected on camera direction (not Euclidean cuz Euclidean distance = fisheye effect on walls)
	if (data->side == 0)
		data->perpwalldist = (data->sidedist_x - data->deltadistx);
	else
		data->perpwalldist = (data->sidedist_y - data->deltadisty);
	//calc height of line to draw on screen
	data->lineheight = (int)(HEIGHT / data->perpwalldist);
	// calc lowest and highest pixel to fill in current stripe
	data->drawstart = (-(data->lineheight) / 2) + (HEIGHT / 2);
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = (data->lineheight / 2) + (HEIGHT / 2);
	if (data->drawend >= HEIGHT)
		data->drawend = HEIGHT - 1;
	//texturing calcs
	data->texnum = Map[data->map_x][data->map_y] - 1;
	//calc value of wall_x
	if (data->side == 0)
		data->wall_x = data->pos_y + data->perpwalldist * data->raydir_y;
	else
		data->wall_x = data->pos_x + data->perpwalldist * data->raydir_x;
	data->wall_x -= floor(data->wall_x);
}

void	texture_render(t_data *data)
{
	//x coord on the texture
	data->tex_x = (int)(data->wall_x * (double)TEXWIDTH);
	if (data->side == 0 && data->raydir_x > 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
	if (data->side == 1 && data->raydir_y < 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
	//how much to increase the texture coord per screen pixel
	data->step = 1.0 * TEXHEIGHT / data->lineheight;
	//Starting texture coord
	data->tex_pos = (data->drawstart - HEIGHT / 2 + data->lineheight / 2) \
		* data->step;
	data->y2 = data->drawstart;
	while (data->y2 < data->drawend)
	{
		//cast the texture coord to int and mask with (texheight - 1) in case of overflow
		data->tex_y = (int)data->tex_pos & (TEXHEIGHT - 1);
		data->tex_pos += data->step;
		walls_render(data);
		//darken color
		if (data->side == 1)
			data->color = (data->color >> 1) & 8355711;
		my_pixelput(data, data->x, data->y2, data->color);
		data->y2++;
	}
}

void	walls_render(t_data *data)
{
	if (data->side == 0 && data->raydir_x < 0) //N
		data->color = getcolor(&data->tex_n, data->tex_x, data->tex_y);
	else if (data->side == 0 && data->raydir_x > 0) //S
		data->color = getcolor(&data->tex_s, data->tex_x, data->tex_y);
	else if (data->side == 1 && data->raydir_y > 0) //E
		data->color = getcolor(&data->tex_e, data->tex_x, data->tex_y);
	else if (data->side == 1 && data->raydir_y < 0) //W
		data->color = getcolor(&data->tex_w, data->tex_x, data->tex_y);
}
