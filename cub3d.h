/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:41:49 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/03 14:47:00 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# define HEIGHT 480
# define WIDTH 640
# define MAPWIDTH 24
# define MAPHEIGHT 24
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define YELLOW 0x00FFDD00
# define CEILING 0x054A1FF
# define FLOOR 0x087460E
/*
typedef	struct s_map
{
	
}	t_map;


typedef struct	s_game
{
    t_map	map;
    
}	t_game;
*/
typedef struct s_tex
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	char	*path;
}		t_tex;

typedef struct s_data
{
	t_tex	tex_n;
	t_tex	tex_s;
	t_tex	tex_e;
	t_tex	tex_w;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	movespeed;
	double	rotspeed;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x; //length of ray from curr posi to next x or y side
	double	sidedist_y;
	double	deltadistx;
	double	deltadisty;
	int		step_x; //what direction to step in x or y direction (+1 or -1)
	int		step_y;
	int		hit;
	int		side;
	double	perpwalldist;
	double	drawstart;
	double	drawend;
	int		lineheight;
	int		x;
	int		y2;
	void	*buffer;
	int		*texture[8];
	double	wall_x; //where exactly the wall was hit
	int		texnum;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;
	double	old_dirx;
	double	old_planex;

}		t_data;

void	data_init(t_data *data);
//int		ft_parsing(int argc, char **argv, t_game *game);
int		movement(int key, t_data *data);
void	hooks(t_data *data);
void	clear_win(t_data *data);
void	raycast(t_data *data);
void	ft_draw(t_data *data);
void	algo_init(t_data *data);
void	dda_algo(t_data *data, int Map[24][24]);
void	pre_dda(t_data *data);
void	map_render(t_data *data, int Map[24][24]);
void	texture_render(t_data *data);
void	walls_render(t_data *data);
void	my_pixelput(t_data *data, int x, int y, int color);
int		getcolor(t_tex *tex, int x, int y);
void	image_maker(t_data *data);
void	window(t_data *data);
void	tex_init(t_tex *tex, void *mlx);
void	right(t_data *data, int key);
void	left(t_data *data, int key);
void	up_down(t_data *data, int key, int Map[24][24]);
void	strafing(t_data *data, int key, int Map[24][24]);

#endif
