/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:45:28 by rbulanad          #+#    #+#             */
/*   Updated: 2024/04/02 14:04:20 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pre_dda(t_data *data)
{
	//calc step and initial sideDist
	if (data->rayDirX < 0)
	{
		data->stepX = -1;
		data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX;
	}
	if (data->rayDirY < 0)
	{
		data->stepY = -1;
		data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
	}
}

void	dda_algo(t_data *data, int Map[24][24])
{
	while (data->hit == 0)
	{
		//jump to next map square either in x or y direction
		if (data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			data->side = 0;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			data->side = 1;
		}
		//Check if ray hit a wall
		if (Map[data->mapX][data->mapY] > 0)
			data->hit = 1;
	}
}

void	map_render(t_data *data, int Map[24][24])
{
	//calc distance projected on camera direction (not Euclidean cuz Euclidean distance = fisheye effect on walls)
	if (data->side == 0)
		data->perpWallDist = (data->sideDistX - data->deltaDistX);
	else
		data->perpWallDist = (data->sideDistY - data->deltaDistY);
	//calc height of line to draw on screen
	data->lineHeight = (int)(HEIGHT / data->perpWallDist);
	// calc lowest and highest pixel to fill in current stripe
	data->drawStart = (-(data->lineHeight) / 2) + (HEIGHT / 2);
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = (data->lineHeight / 2) + (HEIGHT / 2);
	if (data->drawEnd >= HEIGHT)
		data->drawEnd = HEIGHT - 1;
	//texturing calcs
	data->texNum = Map[data->mapX][data->mapY] - 1;
	//calc value of wallX
	if (data->side == 0)
		data->wallX = data->posY + data->perpWallDist * data->rayDirY;
	else
		data->wallX = data->posX + data->perpWallDist * data->rayDirX;
	data->wallX -= floor(data->wallX);
}

void	texture_render(t_data *data)
{
	//x coord on the texture
	data->texX = (int)(data->wallX * (double)texWidth);
	if (data->side == 0 && data->rayDirX > 0)
		data->texX = texWidth - data->texX - 1;
	if (data->side == 1 && data->rayDirY < 0)
		data->texX = texWidth - data->texX - 1;
	//how much to increase the texture coord per screen pixel
	data->step = 1.0 * texHeight / data->lineHeight;
	//Starting texture coord
	data->texPos = (data->drawStart - HEIGHT / 2 + data->lineHeight / 2) \
		* data->step;
	data->y2 = data->drawStart;
	while (data->y2 < data->drawEnd)
	{
		//cast the texture coord to int and mask with (texheight - 1) in case of overflow
		data->texY = (int)data->texPos & (texHeight - 1);
		data->texPos += data->step;
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
	if (data->side == 0 && data->rayDirX < 0) //N
		data->color = getcolor(&data->tex_n, data->texX, data->texY);
	else if (data->side == 0 && data->rayDirX > 0) //S
		data->color = getcolor(&data->tex_s, data->texX, data->texY);
	else if (data->side == 1 && data->rayDirY > 0) //E
		data->color = getcolor(&data->tex_e, data->texX, data->texY);
	else if (data->side == 1 && data->rayDirY < 0) //W
		data->color = getcolor(&data->tex_w, data->texX, data->texY);
}
