/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:57:13 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/23 16:21:17 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verline(t_game *game, int start, int end, int color)
{
	int	y;

	y = start;
	while (y <= end)
		my_pixelput(game, game->data.x, y++, color);
}

void	ceiling_floor(t_game *game, int height)
{
	game->data.floor = create_trgb(0, game->file.rgb_f_c[0], \
		game->file.rgb_f_c[1], \
		game->file.rgb_f_c[2]);
	game->data.ceiling = create_trgb(0, game->file.rgb_f_c[3], \
		game->file.rgb_f_c[4], \
		game->file.rgb_f_c[5]);
	verline(game, 0, height / 2, game->data.ceiling);
	verline(game, height / 2, height, game->data.floor);
}

void	ft_draw(t_game *game)
{
	algo_init(game);
	pre_dda(game);
	dda_algo(game, game->file.map);
	map_render(game, game->file.map);
	texture_render(game);
}

void	raycast(t_game *g)
{
	g->data.x = -1;
	while (++g->data.x < WIDTH)
	{
		ceiling_floor(g, HEIGHT);
		ft_draw(g);
		g->data.movespeed = 0.06;
		g->data.rotspeed = 0.04;
	}
	mlx_put_image_to_window(g->data.mlx, g->data.mlx_win, g->data.img, 0, 0);
}
