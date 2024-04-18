/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:41:49 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/18 16:26:11 by tpicoule         ###   ########.fr       */
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
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
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
	int		bool;
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

void	ft_exit(t_game *game, char *str);
void	ft_exit_2(t_game *game, char *str);
void	ft_free_obj(t_game *game);
#endif