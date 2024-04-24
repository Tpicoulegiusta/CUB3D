/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:41:49 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/24 18:32:27 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include "mlx/mlx.h"
# define HEIGHT 700
# define WIDTH 1100
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define CEILING 0x054A1FF
# define FLOOR 0x087460E

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

typedef struct s_file
{
	char	**all_file;
	char	**tab_txt;
	char	**tab_colors;
	int		rgb_f_c[6];
	char	**tab_map;
	char	**map;
	char	**cpy_map;
	char	*tab1;
}	t_file;

typedef struct s_data
{
	char	*f;
	char	*c;
	t_tex	tex_n;
	t_tex	tex_s;
	t_tex	tex_e;
	t_tex	tex_w;
	int		ceiling;
	int		floor;
	int		bpp;
	int		line_length;
	int		endian;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineheight;
	int		x;
	int		y2;
	int		texnum;
	int		tex_x;
	int		tex_y;
	int		*texture[8];
	int		color;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*buffer;
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	l_strafe;
	bool	r_strafe;
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
	double	sidedist_x;
	double	sidedist_y;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	drawstart;
	double	drawend;
	double	wall_x;
	double	step;
	double	tex_pos;
	double	old_dirx;
	double	old_planex;
}	t_data;

typedef struct s_game
{
	int		no_pos;
	int		so_pos;
	int		we_pos;
	int		ea_pos;
	int		f_pos;
	int		c_pos;
	int		n_no;
	int		n_so;
	int		n_we;
	int		n_ea;
	int		n_f;
	int		n_c;
	int		bol;
	int		flag;
	int		tab_i;
	int		size_tab;
	int		last_line;
	int		first_line;
	int		last_line_2;
	int		first_line_2;
	int		x_player;
	int		y_player;
	int		boool;
	char	player;
	int		size_max;
	int		long_line;
	int		look;
	int		s_count;
	char	**tab_tab;
	int		nb_line;
	t_file	file;
	t_data	data;
}	t_game;

int		ft_parsing(int argc, char **argv, t_game *game);
int		check_args(int argc, char **argv);
int		open_file(char **argv);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *str, int rd);
char	*ft_substr2(char *s, int start, int end);
char	*get_next_line(int fd);
int		parse_file(char **argv, t_game *game);
char	*ft_strjoinfree2(char *stock, char *tmp);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *source);
void	ft_free_tab(char **tab);
int		ft_parse_file_2(t_game *game);
void	ft_parse_file_3(t_game *game);
void	ft_save_line(t_game *g, int i, int j, int *k);
void	last_check(t_game *g);
void	ft_parse_texture(t_game *game);
void	ft_innit(t_game *game);
void	ft_parse_no(t_game	*game, int i, int j);
void	ft_parse_so(t_game	*game, int i, int j);
void	ft_parse_we(t_game	*game, int i, int j);
void	ft_parse_ea(t_game	*game, int i, int j);
char	*ft_parse_path(t_game *game, int i, int j);
void	ft_parse_pos(t_game *game);
void	ft_check_path(char *path);
void	ft_parse_colors(t_game *game);
void	ft_search_colors(t_game *game);
void	ft_parsing_colors(t_game *game);
void	ft_parse_f(t_game *game, int i, int j);
void	ft_parse_c(t_game *game, int i, int j);
void	ft_parse_f_c_pos(t_game *g);
char	*ft_parse_path_f_c(t_game *game, int i, int j);
int		ft_isdigit(int c);
int		ft_isalpha(int i);
int		ft_atoi(const char *str);
int		ft_isprint(int c);
void	ft_last_line(t_game *game, int j);
void	ft_first_line(t_game *game, int j);
void	ft_check_line(char *str);
void	ft_check_left_right(t_game *game);
void	ft_pre_check(t_game *game);
void	ft_check_inside(t_game *game);
void	ft_check_inside_2(t_game *game);
void	ft_stock_map(t_game *game);
void	ft_player(t_game *game);
void	ft_create_cpy(t_game *game, int i, int j, int k);
void	ft_alex(t_game *game);
void	ft_z_check(t_game *game);
void	ft_look_at_me(t_game *game);
void	ft_void_reunit(t_game *game);
void	ft_freez(t_game *game);
void	ft_parse_f(t_game *game, int i, int j);
void	ft_parse_c(t_game *game, int i, int j);
void	ft_check_2_bis(char *path);
void	ft_check_two(char *path);
void	ft_check_path_f_c(char *path, t_game *game);
char	*ft_parse_path_f_c(t_game *g, int i, int j);
void	ft_parse_f_c_pos(t_game *g);
void	ft_check_tree(char *path, t_game *game);
int		ft_cara(int i);
void	ft_repair(t_game *game);
void	ft_last_line_2(t_game *game);
void	ft_first_line_2(t_game *game);
void	ft_last_man(t_game *game);
void	ft_innit_obj(t_game *game);
void	ft_reduce_2(t_game *game);
void	ft_another_check(t_game *game);

void	ft_exit(t_game *game, char *str);
void	ft_exit_2(t_game *game, char *str);
void	ft_free_obj(t_game *game);

//REDDYE//
void	data_init(t_game *game);
void	map_alloc(t_game *game);
void	map_maker(t_game *game);
void	hooks(t_game *game);
void	clear_win(t_game *game);
void	raycast(t_game *game);
void	ft_draw(t_game *game);
void	algo_init(t_game *game);
void	dda_algo(t_game *game, char **map);
void	pre_dda(t_game *game);
void	map_render(t_game *game, char **map);
void	texture_render(t_game *game);
void	walls_render(t_game *game);
void	my_pixelput(t_game *game, int x, int y, int color);
void	image_maker(t_game *game);
void	window(t_game *game);
void	tex_init(t_tex *tex, void *mlx);
void	upp(t_game *game, char **map);
void	down(t_game *game, char **map);
void	right(t_game *game);
void	left(t_game *game);
void	r_strafing(t_game *game, char **map);
void	l_strafing(t_game *game, char **map);
int		getcolor(t_tex *tex, int x, int y);
int		create_trgb(int t, int r, int g, int b);
int		movement(int key, t_game *game);
int		ft_keypress(int key, t_game *game);
int		ft_keyrelease(int key, t_game *game);
int		hook_loop(t_game *game);
int		kb_hooks(int key, t_game *game);

#endif