/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:01:04 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/23 16:11:06 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pre_dda(t_game *game)
{
	if (game->data.raydir_x < 0)
	{
		game->data.step_x = -1;
		game->data.sidedist_x = (game->data.pos_x - game->data.map_x) \
		* game->data.deltadistx;
	}
	else
	{
		game->data.step_x = 1;
		game->data.sidedist_x = (game->data.map_x + 1.0 - game->data.pos_x) \
		* game->data.deltadistx;
	}
	if (game->data.raydir_y < 0)
	{
		game->data.step_y = -1;
		game->data.sidedist_y = (game->data.pos_y - game->data.map_y) \
		* game->data.deltadisty;
	}
	else
	{
		game->data.step_y = 1;
		game->data.sidedist_y = (game->data.map_y + 1.0 - game->data.pos_y) \
		* game->data.deltadisty;
	}
}

void	dda_algo(t_game *game, char **map)
{
	while (game->data.hit == 0)
	{
		if (game->data.sidedist_x < game->data.sidedist_y)
		{
			game->data.sidedist_x += game->data.deltadistx;
			game->data.map_x += game->data.step_x;
			game->data.side = 0;
		}
		else
		{
			game->data.sidedist_y += game->data.deltadisty;
			game->data.map_y += game->data.step_y;
			game->data.side = 1;
		}
		if (map[game->data.map_x][game->data.map_y] == '1')
			game->data.hit = 1;
	}
}

void	map_render(t_game *game, char **map)
{
	if (game->data.side == 0)
		game->data.perpwalldist = \
		(game->data.sidedist_x - game->data.deltadistx);
	else
		game->data.perpwalldist = \
		(game->data.sidedist_y - game->data.deltadisty);
	game->data.lineheight = (int)(HEIGHT / game->data.perpwalldist);
	game->data.drawstart = (-(game->data.lineheight) / 2) + (HEIGHT / 2);
	if (game->data.drawstart < 0)
		game->data.drawstart = 0;
	game->data.drawend = (game->data.lineheight / 2) + (HEIGHT / 2);
	if (game->data.drawend >= HEIGHT)
		game->data.drawend = HEIGHT - 1;
	game->data.texnum = map[game->data.map_x][game->data.map_y] - 1;
	if (game->data.side == 0)
		game->data.wall_x = \
		game->data.pos_y + game->data.perpwalldist * game->data.raydir_y;
	else
		game->data.wall_x = \
		game->data.pos_x + game->data.perpwalldist * game->data.raydir_x;
	game->data.wall_x -= floor(game->data.wall_x);
}

void	texture_render(t_game *game)
{
	game->data.tex_x = (int)(game->data.wall_x * (double)TEXWIDTH);
	if (game->data.side == 0 && game->data.raydir_x > 0)
		game->data.tex_x = TEXWIDTH - game->data.tex_x - 1;
	if (game->data.side == 1 && game->data.raydir_y < 0)
		game->data.tex_x = TEXWIDTH - game->data.tex_x - 1;
	game->data.step = 1.0 * TEXHEIGHT / game->data.lineheight;
	game->data.tex_pos = (game->data.drawstart - \
	HEIGHT / 2 + game->data.lineheight / 2) * game->data.step;
	game->data.y2 = game->data.drawstart;
	while (game->data.y2 < game->data.drawend)
	{
		game->data.tex_y = (int)game->data.tex_pos & (TEXHEIGHT - 1);
		game->data.tex_pos += game->data.step;
		walls_render(game);
		if (game->data.side == 1)
			game->data.color = (game->data.color >> 1) & 8355711;
		my_pixelput(game, game->data.x, game->data.y2, game->data.color);
		game->data.y2++;
	}
}

void	walls_render(t_game *game)
{
	if (game->data.side == 0 && game->data.raydir_x < 0)
		game->data.color = \
		getcolor(&game->data.tex_n, game->data.tex_x, game->data.tex_y);
	else if (game->data.side == 0 && game->data.raydir_x > 0)
	{
		game->data.color = \
		getcolor(&game->data.tex_s, game->data.tex_x, game->data.tex_y);
	}
	else if (game->data.side == 1 && game->data.raydir_y > 0)
	{
		game->data.color = \
		getcolor(&game->data.tex_e, game->data.tex_x, game->data.tex_y);
	}
	else if (game->data.side == 1 && game->data.raydir_y < 0)
		game->data.color = \
		getcolor(&game->data.tex_w, game->data.tex_x, game->data.tex_y);
}
