/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:48:44 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/23 16:17:16 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_maker(t_game *g)
{
	g->data.img = mlx_new_image(g->data.mlx, WIDTH, HEIGHT);
	g->data.addr = mlx_get_data_addr \
	(g->data.img, &g->data.bpp, &g->data.line_length, &g->data.endian);
}

void	window(t_game *game)
{
	game->data.mlx_win = mlx_new_window(game->data.mlx, WIDTH, HEIGHT, "cube");
	image_maker(game);
}

void	clear_win(t_game *game)
{
	mlx_clear_window(game->data.mlx, game->data.mlx_win);
	mlx_destroy_image(game->data.mlx, game->data.img);
	image_maker(game);
}

void	my_pixelput(t_game *g, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y >= HEIGHT || x < 0 || x >= WIDTH)
		return ;
	dst = g->data.addr + (y * g->data.line_length + x * (g->data.bpp / 8));
	*(unsigned int *)dst = color;
}

int	getcolor(t_tex *tex, int x, int y)
{
	char	*color;

	color = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
	return (*(unsigned int *)color);
}
