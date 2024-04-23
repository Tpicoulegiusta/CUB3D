/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:56:24 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/23 16:14:31 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	l_strafing(t_game *g, char **map)
{
	if (map[(int)(g->data.pos_x + g->data.plane_x * g->data.movespeed)] \
	[(int)g->data.pos_y] != '1')
		g->data.pos_x += g->data.plane_x * g->data.movespeed;
	if (map[(int)g->data.pos_x] \
			[(int)(g->data.pos_y + g->data.plane_y * g->data.movespeed)] != '1')
		g->data.pos_y += g->data.plane_y * g->data.movespeed;
}

void	r_strafing(t_game *g, char **map)
{
	if (map[(int)(g->data.pos_x - g->data.plane_x * g->data.movespeed)] \
			[(int)g->data.pos_y] != '1')
		g->data.pos_x -= g->data.plane_x * g->data.movespeed;
	if (map[(int)g->data.pos_x] \
			[(int)(g->data.pos_y - g->data.plane_y * g->data.movespeed)] != '1')
		g->data.pos_y -= g->data.plane_y * g->data.movespeed;
}
