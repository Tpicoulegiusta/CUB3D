/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:26:54 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/21 14:52:29 by tpicoule         ###   ########.fr       */
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
			if (tab[i])
				free(tab[i]);
			i++;
		}
	}
	free(tab);
	}

int	ft_parsing(int argc, char **argv, t_game *game)
{
	if (check_args(argc, argv) != 0)
		return(write(2, "Error\nwrong args\n", 17));
	if (open_file(argv) != 0)
		return(write(2, "Error\nmap can't be opened or directory\n", 39));
	if (parse_file(argv, game) != 0)
		return (write(2, "Error\nfile problems_file\n", 25));
	if (ft_parse_file_2(game) != 0)
	{
		ft_free_tab(game->file.all_file);
		return (write(2, "Error\nfile problems_file\n", 25));
	}
	ft_parse_file_3(game);
	ft_parse_texture(game);
	return (0);
}
