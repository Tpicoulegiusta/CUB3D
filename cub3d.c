/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:40:20 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/21 12:42:50 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 24
#define mapHeight 24
int	Map[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	image_maker(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length, &data->endian);
}

void	window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "kaka");
	image_maker(data);
}

void	clear_win(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
	image_maker(data);
}

void	my_pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;
	if (y < 0 || y >= HEIGHT || x < 0 || x >= WIDTH)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	verLine(t_data *data, int start, int end, int color)
{
	int	y;

	y = start;
	while (y <= end)
		my_pixelput(data, data->x, y++, color);
}

void	igor(t_data *data, int height)
{
	verLine(data, 0, height / 2, SKY);
	verLine(data, height / 2, height, GROUND);
}

int	movement(int key, t_data *data)
{
	double oldDirX;
	double oldPlaneX;
	if (key == 65362)//up
	{
		if(Map[(int)(data->posX + data->dirX * data->moveSpeed)][(int)data->posY] == false)
			data->posX += data->dirX * data->moveSpeed;
		if(Map[(int)data->posX][(int)(data->posY + data->dirY * data->moveSpeed)] == false)
			data->posY += data->dirY * data->moveSpeed;
	}
	if (key == 65364)//down
	{
		if(Map[(int)(data->posX - data->dirX * data->moveSpeed)][(int)data->posY] == false)
			data->posX -= data->dirX * data->moveSpeed;
		if(Map[(int)data->posX][(int)(data->posY - data->dirY * data->moveSpeed)] == false)
			data->posY -= data->dirY * data->moveSpeed;
	}
	if (key == 65363)//right
	{
		//both camera direction and camera plane must be rotated
		oldDirX = data->dirX;
		data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
		data->dirY = oldDirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
		oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
		data->planeY = oldPlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
	}
	if (key == 65361)//left
	{
		//both camera direction and camera plane must be rotated
		oldDirX = data->dirX;
		data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
		data->dirY = oldDirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
		oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
		data->planeY = oldPlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
	}
	raycast(data);
	return (0);
}

void	ft_draw(t_data *data)
{
	//calc ray position and direction
	data->cameraX = 2 * data->x / (double)WIDTH - 1; //X coordinate in camera space
	data->rayDirX = data->dirX + data->planeX * data->cameraX;
	data->rayDirY = data->dirY + data->planeY * data->cameraX;
	//which box of map we're in
	data->mapX = (int)data->posX;
	data->mapY = (int)data->posY;
	//length of ray from onw x or y side to next x or y side
	data->deltaDistX = (data->rayDirX == 0) ? 1e30 : fabs(1/data->rayDirX);
	data->deltaDistY = (data->rayDirY == 0) ? 1e30 : fabs(1/data->rayDirY);
	data->hit = 0; //wall hit ?
	//calc step and initial sideDist
	if (data->rayDirX < 0)
	{
		data->stepX = -1;
		data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX;
	}
	if(data->rayDirY < 0)
	{
		data->stepY = -1;
		data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
	}
	//perform DDA
	while (data->hit == 0)
	{
		//jump to next map square either in x or y direction
		if (data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			data->side = 0;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			data->side = 1;
		}
		//Check if ray hit a wall
		if (Map[data->mapX][data->mapY] > 0)
			data->hit = 1;
	}
	//calc distance projected on camera direction (not Euclidean cuz Euclidean distance = fisheye effect on walls)
	if (data->side == 0)
		data->perpWallDist = (data->sideDistX - data->deltaDistX);
	else
		data->perpWallDist = (data->sideDistY - data->deltaDistY);
	//calc height of line to draw on screen
	data->lineHeight = (int)(HEIGHT / data->perpWallDist);
	// calc lowest and highest pixel to fill in current stripe
		data->drawStart = (-(data->lineHeight) / 2) + (HEIGHT / 2);
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = (data->lineHeight / 2) + (HEIGHT / 2);
	if (data->drawEnd >= HEIGHT)
		data->drawEnd = HEIGHT - 1;
	//wall color
	int	color = 0;
	if (Map[data->mapX][data->mapY] == 1)
		color = RED; 
	if (Map[data->mapX][data->mapY] == 2)
		color = GREEN;
	if (Map[data->mapX][data->mapY] == 3)
		color = BLUE;
	if (Map[data->mapX][data->mapY] == 4)
		color = WHITE;
	if (Map[data->mapX][data->mapY] == 5)
		color = YELLOW;
	//give x and y sides diff brightness
	if (data->side == 1)
		color /= 2;
	//vertical line draw func
	verLine(data, data->drawStart, data->drawEnd, color);
}

void	raycast(t_data *data)
{
	//clear_win(data);
	data->x = -1;
	while (++data->x < WIDTH)
	{
		igor(data, HEIGHT);
		ft_draw(data);
		//speed modifiers
		data->moveSpeed = 0.20; // constant value is in squares/sec
		data->rotSpeed = 0.20; //constant value is in radians/sec
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int main()
{
    //t_game  game;
    
    /*if (ft_parsing(argc, argv, &game) != 0)
        return(1);*/
	t_data	data;
	data.posX = 22;
	data.posY = 12; //x, y player start pos
	data.dirX = -1;
	data.dirY = 0; //initial direction vector
	data.planeX = 0;
	data.planeY = 0.66; //2D raycaster version of camera plane

	data.mlx = mlx_init();
	window(&data);
	raycast(&data);
	hooks(&data);
	mlx_loop(data.mlx);
}
