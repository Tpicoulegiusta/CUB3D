/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:40:20 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/21 16:01:33 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

void	ft_innit(t_game *game)
{
	game->bol = 0;
	game->n_NO = 0;
	game->n_SO = 0;	
	game->n_EA = 0;	
	game->n_WE = 0;	
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
    // while(game.file.all_file[i])
	// {
	// 	printf("%s\n", game.file.all_file[i]);
	// 	i++;
	// }
	
		for(int x = 0; game.file.tab_txt[x] != NULL; x++)
			printf("%s\n", game.file.tab_txt[x]);
	////a mettre dans une fonction free pour tous les tab////
	ft_free_tab(game.file.all_file);
	ft_free_tab(game.file.tab_txt);
}
//////fonction pour verifier le file une derniere fois, si il y a un truc random dedans en plus 
//////des au'on a la 1ere ligne de la map on regarde si au dessus on a uniauement 6 lignes sinon
//////on a un probleme//////////////////////////////////////////////////////////////////////////