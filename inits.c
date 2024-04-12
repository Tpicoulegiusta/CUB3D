/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:22:21 by rbulanad          #+#    #+#             */
/*   Updated: 2024/04/12 14:23:42 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	Map[MAPWIDTH][MAPHEIGHT] =
{
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
	{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
	{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
	{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
	{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
	{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
	{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
	{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
	{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
	{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
	{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
	{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
	{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
	{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
	{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
	{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
	{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
	{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
	{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
	{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
	{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

void	map_alloc(t_data *data)
{
	int	i;

	data->map = malloc(sizeof(int *) * MAPHEIGHT);
	i = -1;
	while (++i < MAPWIDTH)
		data->map[i] = malloc(sizeof(int) * MAPWIDTH);
}

void	map_maker(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MAPHEIGHT)
	{
		j = -1;
		while (++j < MAPWIDTH)
			data->map[i][j] = Map[i][j];
	}
}

void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->pos_x = 20;
	data->pos_y = 11.5;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->tex_n.path = "./textures/NTEX.xpm";
	data->tex_s.path = "./textures/STEX.xpm";
	data->tex_s2.path = "./textures/texturetest.xpm";
	data->tex_e.path = "./textures/ETEX.xpm";
	data->tex_e2.path = "./textures/tommitexture.xpm";
	data->tex_w.path = "./textures/WTEX.xpm";
	data->up = 0;
	data->down = 0;
	data->left = 0;
	data->right = 0;
	data->l_strafe = 0;
	data->r_strafe = 0;
	map_alloc(data);
	map_maker(data);
}

void	algo_init(t_data *data)
{
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
