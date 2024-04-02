/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:47:05 by rbulanad          #+#    #+#             */
/*   Updated: 2024/04/02 16:26:27 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	right(t_data *data, int key)
{
	if (key == 100)
	{
		//both camera direction and camera plane must be rotated
		data->old_dirx = data->dirX;
		data->dirX = data->dirX * cos(-data->rotSpeed) \
			- data->dirY * sin(-data->rotSpeed);
		data->dirY = data->old_dirx * sin(-data->rotSpeed) \
			+ data->dirY * cos(-data->rotSpeed);
		data->old_planex = data->planeX;
		data->planeX = data->planeX * cos(-data->rotSpeed) \
			- data->planeY * sin(-data->rotSpeed);
		data->planeY = data->old_planex * sin(-data->rotSpeed) \
			+ data->planeY * cos(-data->rotSpeed);
	}
}

void	left(t_data *data, int key)
{
	if (key == 97)
	{
		//both camera direction and camera plane must be rotated
		data->old_dirx = data->dirX;
		data->dirX = data->dirX * cos(data->rotSpeed) \
			- data->dirY * sin(data->rotSpeed);
		data->dirY = data->old_dirx * sin(data->rotSpeed) \
			+ data->dirY * cos(data->rotSpeed);
		data->old_planex = data->planeX;
		data->planeX = data->planeX * cos(data->rotSpeed) \
			- data->planeY * sin(data->rotSpeed);
		data->planeY = data->old_planex * sin(data->rotSpeed) \
			+ data->planeY * cos(data->rotSpeed);
	}
}

void	up_down(t_data *data, int key, int Map[24][24])
{
	if (key == 119)
	{
		if (Map[(int)(data->posX + data->dirX * data->moveSpeed)] \
				[(int)data->posY] == false)
			data->posX += data->dirX * data->moveSpeed;
		if (Map[(int)data->posX] \
				[(int)(data->posY + data->dirY * data->moveSpeed)] == false)
			data->posY += data->dirY * data->moveSpeed;
	}
	if (key == 115)
	{
		if (Map[(int)(data->posX - data->dirX * data->moveSpeed)] \
				[(int)data->posY] == false)
			data->posX -= data->dirX * data->moveSpeed;
		if (Map[(int)data->posX] \
				[(int)(data->posY - data->dirY * data->moveSpeed)] == false)
			data->posY -= data->dirY * data->moveSpeed;
	}
}

void	strafing(t_data *data, int key, int Map[24][24])
{
	if (key == 101)
	{
		if (Map[(int)(data->posX + data->planeX * data->moveSpeed)] \
				[(int)data->posY] == false)
			data->posX += data->planeX * data->moveSpeed;
		if (Map[(int)data->posX] \
				[(int)(data->posY + data->planeY * data->moveSpeed)] == false)
			data->posY += data->planeY * data->moveSpeed;
	}
	if (key == 113)
	{
		if (Map[(int)(data->posX - data->planeX * data->moveSpeed)] \
				[(int)data->posY] == false)
			data->posX -= data->planeX * data->moveSpeed;
		if (Map[(int)data->posX] \
				[(int)(data->posY - data->planeY * data->moveSpeed)] == false)
			data->posY -= data->planeY * data->moveSpeed;
	}
}
