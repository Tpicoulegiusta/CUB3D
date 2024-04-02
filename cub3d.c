/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:40:20 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/02 14:58:07 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	Map[mapWidth][mapHeight] =
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

void	verLine(t_data *data, int start, int end, int color)
{
	int	y;

	y = start;
	while (y <= end)
		my_pixelput(data, data->x, y++, color);
}

void	ceiling_floor(t_data *data, int height)
{
	verLine(data, 0, height / 2, CEILING);
	verLine(data, height / 2, height, FLOOR);
}

int	movement(int key, t_data *data)
{
	//printf("%d\n", key);

	left_right(data, key);
	if (key == 119)//up
	{
		if(Map[(int)(data->posX + data->dirX * data->moveSpeed)][(int)data->posY] == false)
			data->posX += data->dirX * data->moveSpeed;
		if(Map[(int)data->posX][(int)(data->posY + data->dirY * data->moveSpeed)] == false)
			data->posY += data->dirY * data->moveSpeed;
	}
	if (key == 115)//down
	{
		if(Map[(int)(data->posX - data->dirX * data->moveSpeed)][(int)data->posY] == false)
			data->posX -= data->dirX * data->moveSpeed;
		if(Map[(int)data->posX][(int)(data->posY - data->dirY * data->moveSpeed)] == false)
			data->posY -= data->dirY * data->moveSpeed;
	}

	if (key == 101)//strafe right
	{
		if(Map[(int)(data->posX + data->planeX * data->moveSpeed)][(int)data->posY] == false)
			data->posX += data->planeX * data->moveSpeed;
		if(Map[(int)data->posX][(int)(data->posY + data->planeY * data->moveSpeed)] == false)
			data->posY += data->planeY * data->moveSpeed;
	}
	if (key == 113)//strafe left
	{
		if(Map[(int)(data->posX - data->planeX * data->moveSpeed)][(int)data->posY] == false)
			data->posX -= data->planeX * data->moveSpeed;
		if(Map[(int)data->posX][(int)(data->posY - data->planeY * data->moveSpeed)] == false)
			data->posY -= data->planeY * data->moveSpeed;
	}
	raycast(data);
	return (0);
}

void	ft_draw(t_data *data)
{
	algo_init(data);
	pre_dda(data);
	dda_algo(data, Map);
	map_render(data, Map);
	texture_render(data);
}

void	raycast(t_data *data)
{
	//printf("x:%f, y:%f\n", data->posX, data->posY);
	data->x = -1;
	while (++data->x < WIDTH)
	{
		ceiling_floor(data, HEIGHT);
		ft_draw(data);
		//speed modifiers
		data->moveSpeed = 0.20;
		data->rotSpeed = 0.15;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	main(void)
{
	t_data	data;

	data_init(&data);
	window(&data);
	tex_init(&data.tex_n, data.mlx);
	tex_init(&data.tex_s, data.mlx);
	tex_init(&data.tex_e, data.mlx);
	tex_init(&data.tex_w, data.mlx);
	raycast(&data);
	hooks(&data);
	mlx_loop(data.mlx);
}
