/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:41:49 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/20 13:23:14 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define    CUBE3D_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# define HEIGHT 700
# define WIDTH 1400
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define YELLOW 0x00FFDD00


typedef	struct s_map
{
	
}	t_map;


typedef struct	s_game
{
    t_map	map;
    
}	t_game;

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int	bpp;
	int	line_length;
	int	endian;
}		t_mlx;

int ft_parsing(int argc, char **argv, t_game *game);
void	hooks(t_mlx *libx);

#endif
