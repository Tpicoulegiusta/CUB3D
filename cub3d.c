/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:40:20 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/26 17:49:38 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 24
#define mapHeight 24
#define texWidth 64
#define texHeight 64
int	Map[mapWidth][mapHeight]=
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

void	tex_init(t_tex *tex, void *mlx) ///////texture struc init
{
	int	x;
	tex->img = mlx_xpm_file_to_image(mlx, tex->path, &x, &x);
	if (!tex->img)
		exit(1);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_length, &tex->endian);
}

int	my_pixel_get_color(t_tex *tex, int x, int y)
{
	char	*color;

	color = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
	return (*(unsigned int *)color);
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
	//printf("%d\n", key);
	double oldDirX;
	double oldPlaneX;
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
	if (key == 100)//right
	{
		//both camera direction and camera plane must be rotated
		oldDirX = data->dirX;
		data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
		data->dirY = oldDirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
		oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
		data->planeY = oldPlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
	}
	if (key == 97)//left
	{

		//both camera direction and camera plane must be rotated
		oldDirX = data->dirX;
		data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
		data->dirY = oldDirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
		oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
		data->planeY = oldPlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
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
	//calc ray position and direction
	data->cameraX = 2 * data->x / (double)WIDTH - 1; //X coordinate in camera space, 
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
	//texturing calcs
	data->texNum = Map[data->mapX][data->mapY] - 1;
	//calc value of wallX
	if (data->side == 0)
		data->wallX = data->posY + data->perpWallDist * data->rayDirY;
	else
		data->wallX = data->posX + data->perpWallDist * data->rayDirX;
	data->wallX -= floor(data->wallX);
	//x coord on the texture
	data->texX = (int)(data->wallX * (double)texWidth);
	if (data->side == 0 && data->rayDirX > 0)
		data->texX = texWidth - data->texX - 1;
	if (data->side == 1 && data->rayDirY < 0)
		data->texX = texWidth - data->texX - 1;
	//how much to increase the texture coord per screen pixel
	data->step = 1.0 * texHeight / data->lineHeight;
	//Starting texture coord
	data->texPos = (data->drawStart - HEIGHT / 2 + data->lineHeight / 2) * data->step;
	data->y2 = data->drawStart;
	while (data->y2 < data->drawEnd)
	{
		//cast the texture coord to int and mask with (texheight - 1) in case of overflow
		data->texY = (int)data->texPos & (texHeight - 1);
		data->texPos += data->step;
		if (data->side == 0 && data->rayDirX < 0) //N
			data->color = my_pixel_get_color(&data->tex_n , data->texX, data->texY);
		else if (data->side == 0 && data->rayDirX > 0) //S
			data->color = my_pixel_get_color(&data->tex_s , data->texX, data->texY);
		else if (data->side == 1 && data->rayDirY > 0) //E
			data->color = my_pixel_get_color(&data->tex_e, data->texX, data->texY);
		else if (data->side == 1 && data->rayDirY < 0) //W
			data->color = my_pixel_get_color(&data->tex_w, data->texX, data->texY);
		//darken color
		if (data->side == 1)
			data->color = (data->color >> 1) & 8355711;
		my_pixelput(data, data->x, data->y2, data->color);
		data->y2++;
	}
}

void	raycast(t_data *data)
{
	printf("x:%f, y:%f\n", data->posX, data->posY);
	//clear_win(data);
	data->x = -1;
	while (++data->x < WIDTH)
	{
		igor(data, HEIGHT);
		ft_draw(data);
		//speed modifiers
		data->moveSpeed = 0.20; // constant value is in squares/sec
		data->rotSpeed = 0.15; //constant value is in radians/sec
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int main()
{
    //t_game  game;
    
    /*if (ft_parsing(argc, argv, &game) != 0)
        return(1);*/
	t_data	data;
	data.posX = 20;
	data.posY =11.5; //x, y player start pos
	data.dirX = -1;
	data.dirY = 0; //initial direction vector
	data.planeX = 0;
	data.planeY = 0.66; //2D raycaster version of camera plane
	data.mlx = mlx_init();
	window(&data);
	data.tex_n.path = "./textures/NTEX.xpm";
	data.tex_s.path = "./textures/STEX.xpm";
	data.tex_e.path = "./textures/ETEX.xpm";
	data.tex_w.path = "./textures/WTEX.xpm";
	tex_init(&data.tex_n, data.mlx);
	tex_init(&data.tex_s, data.mlx);
	tex_init(&data.tex_e, data.mlx);
	tex_init(&data.tex_w, data.mlx);
	raycast(&data);
	hooks(&data);
	mlx_loop(data.mlx);
}
