/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:40:20 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/27 18:35:11 by tpicoule         ###   ########.fr       */
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
	
}

int main(int argc, char **argv)
{
    t_game  game;
	// int i;
	// // int	j;

	// // j = 0;
	// i = 0;
	ft_innit(&game);
    if (ft_parsing(argc, argv, &game) != 0)
		return(1);
	ft_parse_colors(&game);
	// ft_parsing_colors(&game);
	// ft_parse_colors(&game);
	//check filelignes < 9 == quit//
    // while(game.file.all_file[i])
	// {
	// 	printf("%s\n", game.file.all_file[i]);	ft_free_tab(game.file.all_file);
	// 	i++;
	// }
	
	// for(int x = 0; game.file.tab_txt[x] != NULL; x++)
	// 	printf("%s\n", game.file.tab_txt[x]);
	for(int y = 0; game.file.tab_colors[y] != NULL; y++)
		printf("%s\n", game.file.tab_colors[y]);
	////a mettre dans une fonction free pour tous les tab////
	ft_free_tab(game.file.all_file);
	ft_free_tab(game.file.tab_txt);
	ft_free_tab(game.file.tab_colors);
	ft_free_obj(&game);
}
//////fonction pour verifier le file une derniere fois, si il y a un truc random dedans en plus 
//////des au'on a la 1ere ligne de la map on regarde si au dessus on a uniauement 6 lignes sinon
//////on a un probleme//////////////////////////////////////////////////////////////////////////