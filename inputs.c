/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:54:22 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/23 16:13:33 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	right(t_game *game)
{
	game->data.old_dirx = game->data.dir_x;
	game->data.dir_x = game->data.dir_x * cos(-game->data.rotspeed) \
		- game->data.dir_y * sin(-game->data.rotspeed);
	game->data.dir_y = game->data.old_dirx * sin(-game->data.rotspeed) \
		+ game->data.dir_y * cos(-game->data.rotspeed);
	game->data.old_planex = game->data.plane_x;
	game->data.plane_x = game->data.plane_x * cos(-game->data.rotspeed) \
		- game->data.plane_y * sin(-game->data.rotspeed);
	game->data.plane_y = game->data.old_planex * sin(-game->data.rotspeed) \
		+ game->data.plane_y * cos(-game->data.rotspeed);
}

void	upp(t_game *game, char **map)
{
	if (map[(int)(game->data.pos_x + game->data.dir_x * game->data.movespeed)] \
			[(int)game->data.pos_y] != '1')
		game->data.pos_x += game->data.dir_x * game->data.movespeed;
	if (map[(int)game->data.pos_x] \
	[(int)(game->data.pos_y + game->data.dir_y * game->data.movespeed)] != '1')
		game->data.pos_y += game->data.dir_y * game->data.movespeed;
}

void	down(t_game *game, char **map)
{
	if (map[(int)(game->data.pos_x - game->data.dir_x * game->data.movespeed)] \
			[(int)game->data.pos_y] != '1')
		game->data.pos_x -= game->data.dir_x * game->data.movespeed;
	if (map[(int)game->data.pos_x] \
	[(int)(game->data.pos_y - game->data.dir_y * game->data.movespeed)] != '1')
		game->data.pos_y -= game->data.dir_y * game->data.movespeed;
}

void	left(t_game *game)
{
	game->data.old_dirx = game->data.dir_x;
	game->data.dir_x = game->data.dir_x * cos(game->data.rotspeed) \
		- game->data.dir_y * sin(game->data.rotspeed);
	game->data.dir_y = game->data.old_dirx * sin(game->data.rotspeed) \
		+ game->data.dir_y * cos(game->data.rotspeed);
	game->data.old_planex = game->data.plane_x;
	game->data.plane_x = game->data.plane_x * cos(game->data.rotspeed) \
		- game->data.plane_y * sin(game->data.rotspeed);
	game->data.plane_y = game->data.old_planex * sin(game->data.rotspeed) \
		+ game->data.plane_y * cos(game->data.rotspeed);
}
