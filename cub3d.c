/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:40:20 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/15 16:23:58 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

int main(int argc, char **argv)
{
    t_game  game;
	int i;
	// int	j;

	// j = 0;
	i = 0;
    if (ft_parsing(argc, argv, &game) != 0)
        return(1);
    while(game.file.all_file[i])
	{
		printf("%s\n", game.file.all_file[i]);
		i++;
	}
	////a mettre dans une fonction free pour tous les tab////
	ft_free_tab(game.file.all_file);
}