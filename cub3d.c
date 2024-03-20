/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:40:20 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/20 14:01:23 by rbulanad         ###   ########.fr       */
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

void	window(t_mlx *libx)
{
	libx->mlx_win = mlx_new_window(libx->mlx, WIDTH, HEIGHT, "kaka");
	libx->img = mlx_new_image(libx->mlx, WIDTH, HEIGHT);
	libx->addr = mlx_get_data_addr(libx->img, &libx->bpp, &libx->line_length, &libx->endian);
}

void	my_pixelput(t_mlx *libx, int x, int y, int color)
{
	char	*dst;
	if (y < 0 || y >= HEIGHT || x < 0 || x >= WIDTH)
		return ;
	dst = libx->addr + (y * libx->line_length + x * (libx->bpp / 8));
	*(unsigned int *)dst = color;
}

void	verLine(t_mlx *libx, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y < end)
		my_pixelput(libx, x, y++, color);
}

/*void	movement(int key)
{
	double oldDirX;
	double oldDiry;
	if (key == 65362)//up
	{
		if(Map[(int)(posX + dirX * moveSpeed)][(int)posY] == false)
			posX += dirX * moveSpeed;
		if(Map[(int)posX][(int)(posY + dirY * moveSpeed)] == false)
			posY += dirY * moveSpeed;
	}
	if (key == 65364)//down
	{
		if(Map[(int)(posX - dirX * moveSpeed)][(int)posY] == false)
			posX -= dirX * moveSpeed;
		if(Map[(int)posX][(int)(posY - dirY * moveSpeed)] == false)
			posY -= dirY * moveSpeed;
	}
	if (key == 65363)//right
	{
		//both camera direction and camera plane must be rotated
		oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	if (key == 65361)//left
	{
		//both camera direction and camera plane must be rotated
		oldDirX = dirX;
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		oldPlaneX = planeX;
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}
}*/

int main()
{
    //t_game  game;
    
    /*if (ft_parsing(argc, argv, &game) != 0)
        return(1);*/
	t_mlx	libx;
	double	posX = 22;
	double	posY = 12; //x, y player start pos
	double	dirX = -1;
	double	dirY = 0; //initial direction vector
	double	planeX = 0;
	double	planeY = 0.66; //2D raycaster version of camera plane
	//double	time = 0; //time of current frame
	//double	oldTime = 0; //time of previous frame

	libx.mlx = mlx_init();
	window(&libx);
	int done = 0;
	while(!done)
	{
		int	x = -1;
		while (++x < WIDTH)
		{
			//calc ray position and direction
			double cameraX = 2 * x / (double)WIDTH - 1; //X coordinate in camera space
			double rayDirX = dirX + planeX * cameraX;
			double	rayDirY = dirY + planeY * cameraX;
			//which box of map we're in
			int	mapX = (int)posX;
			int	mapY = (int)posY;
			//length of rya from curr posi to next x or y side
			double	sideDistX;
			double	sideDistY;
			//length of ray from onw x or y side to next x or y side
			double	deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1/rayDirX);
			double	deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1/rayDirY);
			//what direction to step in x or y direction (+1 or -1)
			int	stepX;
			int	stepY;

			int	hit = 0; //wall hit ?
			int	side; //was it a NS or a EW wall hit ?
			//calc step and initial sideDist
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = -1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
			}
			if(rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
			}
			//perform DDA
			while (hit == 0)
			{
				//jump to next map square either in x or y direction
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				//Check if ray hit a wall
				if (Map[mapX][mapY] > 0)
					hit = 1;
			}
			//calc distance projected on camera direction (not Euclidean cuz Euclidean distance = fisheye effect on walls)
			double perpWallDist;
			if (side == 0)
				perpWallDist = (sideDistX -deltaDistX);
			else
				perpWallDist = (sideDistY -deltaDistY);
			//calc height of line to draw on screen
			int	lineHeight = (int)(HEIGHT / perpWallDist);
			// calc lowest and highest pixel to fill in current stripe
			int	drawStart = -lineHeight / 2 + HEIGHT / 2;
			if (drawStart < 0)
				drawStart = 0;
			int	drawEnd = lineHeight / 2 + HEIGHT / 2;
			if (drawEnd >= HEIGHT)
				drawEnd = HEIGHT - 1;
			//wall color
			int	color = 0;
			if (Map[mapX][mapY] == 1)
				color = RED; 
			if (Map[mapX][mapY] == 2)
				color = GREEN;
			if (Map[mapX][mapY] == 3)
				color = BLUE;
			if (Map[mapX][mapY] == 4)
				color = WHITE;
			if (Map[mapX][mapY] == 5)
				color = YELLOW;
			//give x and y sides diff brightness
			if (side == 1)
				color /= 2;
			//vertical line draw func
			verLine(&libx, x, drawStart, drawEnd, color);
			//speed modifiers
			/*double moveSpeed = 1; // constant value is in squares/sec
			double rotSpeed = 1; //constant value is in radians/sec
			mlx_key_hook(libx.mlx_win, movement, libx);*/
		}
		done = 1;
	}
	mlx_put_image_to_window(libx.mlx, libx.mlx_win, libx.img, 0, 0);
	hooks(&libx);
	mlx_loop(libx.mlx);
}
