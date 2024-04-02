/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:22:21 by rbulanad          #+#    #+#             */
/*   Updated: 2024/04/02 14:12:24 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->posX = 20;
	data->posY = 11.5; //x, y player start pos
	data->dirX = -1;
	data->dirY = 0; //initial direction vector
	data->planeX = 0;
	data->planeY = 0.66; //2D raycaster version of camera plane
	data->tex_n.path = "./textures/NTEX.xpm";
	data->tex_s.path = "./textures/STEX.xpm";
	data->tex_e.path = "./textures/ETEX.xpm";
	data->tex_w.path = "./textures/WTEX.xpm";
}

void	algo_init(t_data *data)
{
	// Camera position + direction, Player position inits
	data->cameraX = 2 * data->x / (double)WIDTH - 1;
	data->rayDirX = data->dirX + data->planeX * data->cameraX;
	data->rayDirY = data->dirY + data->planeY * data->cameraX;
	data->mapX = (int)data->posX;
	data->mapY = (int)data->posY;
	if (data->rayDirX == 0)
		data->deltaDistX = 1e30;
	else
		data->deltaDistX = fabs(1 / data->rayDirX);
	if (data->rayDirY == 0)
		data->deltaDistY = 1e30;
	else
		data->deltaDistY = fabs(1 / data->rayDirY);
	data->hit = 0;
}

void	tex_init(t_tex *tex, void *mlx) ///////texture struc init
{
	int	x;

	tex->img = mlx_xpm_file_to_image(mlx, tex->path, &x, &x);
	if (!tex->img)
		exit(1);
	tex->addr = \
		mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_length, &tex->endian);
}
