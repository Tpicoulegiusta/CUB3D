/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:46:37 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/23 16:42:13 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	data_init(t_game *game)
{
	game->data.mlx = mlx_init();
	game->data.pos_x = game->y_player + 0.5;
	game->data.pos_y = game->x_player + 0.5;
	game->data.dir_x = -1;
	game->data.dir_y = 0;
	game->data.plane_x = 0;
	game->data.plane_y = 0.66;
	game->data.up = 0;
	game->data.down = 0;
	game->data.left = 0;
	game->data.right = 0;
	game->data.l_strafe = 0;
	game->data.r_strafe = 0;
}

void	algo_init(t_game *game)
{
	game->data.camera_x = 2 * game->data.x / (double)WIDTH - 1;
	game->data.raydir_x = \
	game->data.dir_x + game->data.plane_x * game->data.camera_x;
	game->data.raydir_y = \
	game->data.dir_y + game->data.plane_y * game->data.camera_x;
	game->data.map_x = (int)game->data.pos_x;
	game->data.map_y = (int)game->data.pos_y;
	if (game->data.raydir_x == 0)
		game->data.deltadistx = 1e30;
	else
		game->data.deltadistx = fabs(1 / game->data.raydir_x);
	if (game->data.raydir_y == 0)
		game->data.deltadisty = 1e30;
	else
		game->data.deltadisty = fabs(1 / game->data.raydir_y);
	game->data.hit = 0;
}

void	tex_init(t_tex *tex, void *mlx)
{
	int	x;

	tex->img = mlx_xpm_file_to_image(mlx, tex->path, &x, &x);
	if (!tex->img)
	{
		printf("ERR: Not an xpm file\n");
		exit(1);
	}
	tex->addr = \
		mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_length, &tex->endian);
}
