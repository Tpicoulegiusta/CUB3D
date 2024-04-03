/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:22:21 by rbulanad          #+#    #+#             */
/*   Updated: 2024/04/03 15:13:37 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->pos_x = 20;
	data->pos_y = 11.5; //x, y player start pos
	data->dir_x = -1;
	data->dir_y = 0; //initial direction vector
	data->plane_x = 0;
	data->plane_y = 0.66; //2D raycaster version of camera plane
	data->tex_n.path = "./textures/NTEX.xpm";
	data->tex_s.path = "./textures/STEX.xpm";
	data->tex_e.path = "./textures/ETEX.xpm";
	data->tex_w.path = "./textures/WTEX.xpm";
}

void	algo_init(t_data *data)
{
	// Camera position + direction, Player position inits
	data->camera_x = 2 * data->x / (double)WIDTH - 1;
	data->raydir_x = data->dir_x + data->plane_x * data->camera_x;
	data->raydir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	if (data->raydir_x == 0)
		data->deltadistx = 1e30;
	else
		data->deltadistx = fabs(1 / data->raydir_x);
	if (data->raydir_y == 0)
		data->deltadisty = 1e30;
	else
		data->deltadisty = fabs(1 / data->raydir_y);
	data->hit = 0;
}

void	tex_init(t_tex *tex, void *mlx) ///////texture struc init
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
