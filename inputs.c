/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:47:05 by rbulanad          #+#    #+#             */
/*   Updated: 2024/04/12 14:13:31 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	right(t_data *data)
{
	data->old_dirx = data->dir_x;
	data->dir_x = data->dir_x * cos(-data->rotspeed) \
		- data->dir_y * sin(-data->rotspeed);
	data->dir_y = data->old_dirx * sin(-data->rotspeed) \
		+ data->dir_y * cos(-data->rotspeed);
	data->old_planex = data->plane_x;
	data->plane_x = data->plane_x * cos(-data->rotspeed) \
		- data->plane_y * sin(-data->rotspeed);
	data->plane_y = data->old_planex * sin(-data->rotspeed) \
		+ data->plane_y * cos(-data->rotspeed);
}

void	left(t_data *data)
{
	data->old_dirx = data->dir_x;
	data->dir_x = data->dir_x * cos(data->rotspeed) \
		- data->dir_y * sin(data->rotspeed);
	data->dir_y = data->old_dirx * sin(data->rotspeed) \
		+ data->dir_y * cos(data->rotspeed);
	data->old_planex = data->plane_x;
	data->plane_x = data->plane_x * cos(data->rotspeed) \
		- data->plane_y * sin(data->rotspeed);
	data->plane_y = data->old_planex * sin(data->rotspeed) \
		+ data->plane_y * cos(data->rotspeed);
}

void	upp(t_data *data, int **Map)
{
	if (Map[(int)(data->pos_x + data->dir_x * data->movespeed)] \
			[(int)data->pos_y] == false)
		data->pos_x += data->dir_x * data->movespeed;
	if (Map[(int)data->pos_x] \
			[(int)(data->pos_y + data->dir_y * data->movespeed)] == false)
		data->pos_y += data->dir_y * data->movespeed;
}

void	down(t_data *data, int **Map)
{
	if (Map[(int)(data->pos_x - data->dir_x * data->movespeed)] \
			[(int)data->pos_y] == false)
		data->pos_x -= data->dir_x * data->movespeed;
	if (Map[(int)data->pos_x] \
			[(int)(data->pos_y - data->dir_y * data->movespeed)] == false)
		data->pos_y -= data->dir_y * data->movespeed;
}
