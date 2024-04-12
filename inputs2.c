/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:13:19 by rbulanad          #+#    #+#             */
/*   Updated: 2024/04/12 14:13:53 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	l_strafing(t_data *data, int **Map)
{
	if (Map[(int)(data->pos_x + data->plane_x * data->movespeed)] \
			[(int)data->pos_y] == false)
		data->pos_x += data->plane_x * data->movespeed;
	if (Map[(int)data->pos_x] \
			[(int)(data->pos_y + data->plane_y * data->movespeed)] == false)
		data->pos_y += data->plane_y * data->movespeed;
}

void	r_strafing(t_data *data, int **Map)
{
	if (Map[(int)(data->pos_x - data->plane_x * data->movespeed)] \
			[(int)data->pos_y] == false)
		data->pos_x -= data->plane_x * data->movespeed;
	if (Map[(int)data->pos_x] \
			[(int)(data->pos_y - data->plane_y * data->movespeed)] == false)
		data->pos_y -= data->plane_y * data->movespeed;
}
