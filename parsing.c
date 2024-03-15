/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:26:54 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/15 16:27:39 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if(tab)
	{
		while(tab[i])
		{
			free(tab[i++]);
		}
		free(tab);
	}
}

int	ft_parsing(int argc, char **argv, t_game *game)
{

	if (check_args(argc, argv) != 0)
		return(write(2, "Error\nwrong args\n", 17));
	if (open_file(argv) != 0)
		return(write(2, "Error\nmap can't be opened or directory\n", 39));
	if (parse_file(argv, game) != 0)
	{
		ft_free_tab(game->file.all_file);
		return (write(2, "Error\nfile problem\n", 19));
	}
	return (0);
}