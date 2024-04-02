/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:47:05 by rbulanad          #+#    #+#             */
/*   Updated: 2024/04/02 14:57:53 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	left_right(t_data *data, int key)
{
	if (key == 100)//right
	{
		//both camera direction and camera plane must be rotated
		data->old_dirx = data->dirX;
		data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
		data->dirY = data->old_dirx * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
		data->old_planex = data->planeX;
		data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
		data->planeY = data->old_planex * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
	}
	if (key == 97)//left
	{
		//both camera direction and camera plane must be rotated
		data->old_dirx = data->dirX;
		data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
		data->dirY = data->old_dirx * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
		data->old_planex = data->planeX;
		data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
		data->planeY = data->old_planex * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);

	}
}
