/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:41:49 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/15 16:08:07 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define    CUBE3D_H

#ifndef BUFFER_SIZE
# define	BUFFER_SIZE 1
#endif

//#include "mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct s_map
{
    int     sizey;
}	t_map;

typedef struct s_file
{
    char    **all_file;
    char    *tab_txt;
    char	*tab_colors;
}   t_file;

typedef struct	s_game
{
    t_map	map;
    t_file  file;
    
}	t_game;
//////////////////////////////////////////////////////////////////////
int	    ft_parsing(int argc, char **argv, t_game *game);
int     check_args(int argc, char **argv);
int     open_file(char **argv);
int     ft_strlen(char *str);
//////////////////////////////////////////////////////////////////////
/////////////////get_next_line_utils//////////////////////////////////
char	*ft_strjoin(char *s1, char *s2);
//static char	*ft_strjoinfree(char *stock, char *tmp);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *str, int rd);
char	*ft_substr2(char *s, int start, int end);
//static char	*ft_get_stocked(int fd, char *stock);
char	*get_next_line(int fd);
//////////////////////////////////////////////////////////////////////
/////////////////parse_file///////////////////////////////////////////
int     parse_file(char **argv, t_game *game);
char	*ft_strjoinfree2(char *stock, char *tmp);
int	    ft_counti(char *s, char c);
char	**ft_countj(char **tabtab, char *s, char c);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *source);
void	ft_free_tab(char **tab);

#endif