/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:40:20 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/12 13:28:21 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

void	ft_exit(t_game *game, char *str)
{
	printf("%s\n", str);
	ft_free_tab(game->file.tab_txt);
	exit(EXIT_FAILURE);	
}

void	ft_exit_2(t_game *game, char *str)
{
	printf("%s\n", str);
	ft_free_tab(game->file.tab_txt);
	ft_free_tab(game->file.all_file);
	ft_free_obj(game);
	exit(EXIT_FAILURE);
}

void	ft_free_obj(t_game *game)
{
	if (game->data.no)
		free(game->data.no);
	if (game->data.so)
		free(game->data.so);
	if (game->data.we)
		free(game->data.we);
	if (game->data.ea)
		free(game->data.ea);
	if (game->data.f)
		free(game->data.f);
	if (game->data.c)
		free(game->data.c);
}

void	ft_innit(t_game *game)
{
	game->bol = 0;
	game->n_no = 0;
	game->n_so = 0;
	game->n_ea = 0;
	game->n_we = 0;
	game->no_pos = 0;
	game->so_pos = 0;
	game->we_pos = 0;
	game->ea_pos = 0;
	game->n_f = 0;
	game->n_c = 0;
	game->f_pos = 0;
	game->c_pos = 0;
	game->tab_i = 0;
	game->last_line = 0;
	game->first_line = 0;
	game->x_player = 0;
	game->y_player = 0;
	game->bool = 0;
	game->boool = 0;
	game->size_max = 0;
	game->long_line = 0;
	game->look = 0;
}

int main(int argc, char **argv)
{
    t_game  game;
	int i;
	// int	j;

	// j = 0;
	i = 0;
	ft_innit(&game);
    if (ft_parsing(argc, argv, &game) != 0)
		return(1);
	ft_parse_colors(&game);
	//puts("caca");
	ft_last_line(&game, 0);
	ft_first_line(&game, 0);
	ft_look_at_me(&game);
	ft_check_line(game.file.all_file[game.first_line]);
	ft_check_line(game.file.all_file[game.last_line]);
	ft_check_left_right(&game);
	ft_pre_check(&game);
	ft_check_inside(&game);
	ft_check_inside_2(&game);
	ft_stock_map(&game);
	ft_player(&game);
	ft_alex(&game);
	ft_create_cpy(&game);
	ft_z_check(&game);
	//fonction pour compter les elements jusqua first line en passant les espaces des auon trouve auelaue chose///
	
	// ft_inside_walls(&game);
	
	//printf("last === %d\n", game.last_line);
	// ft_parsing_colors(&game);
	// ft_parse_colors(&game);
	//check filelignes < 9 == quit//
    while(game.file.map[i])
	{
		printf("'%s'\n", game.file.map[i]);	
		//ft_free_tab(game.file.all_file);
		i++;
	}
		
	// for(int x = 0; game.file.tab_txt[x] != NULL; x++)
	// 	printf("%s\n", game.file.tab_txt[x]);
	// for(int y = 0; game.file.tab_colors[y] != NULL; y++)
	// 	printf("%s\n", game.file.tab_colors[y]);
	////a mettre dans une fonction free pour tous les tab////
	ft_free_tab(game.file.all_file);
	ft_free_tab(game.file.tab_txt);
	ft_free_tab(game.file.tab_colors);
	ft_free_tab(game.file.map);
	ft_free_tab(game.file.cpy_map);
	//ft_free_tab(game.file.cpy_cpy);
	ft_free_obj(&game);
}
//////fonction pour verifier le file une derniere fois, si il y a un truc random dedans en plus 
//////des au'on a la 1ere ligne de la map on regarde si au dessus on a uniauement 6 lignes sinon
//////on a un probleme//////////////////////////////////////////////////////////////////////////