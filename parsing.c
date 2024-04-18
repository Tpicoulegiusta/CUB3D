/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:26:54 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/18 13:35:42 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i] != NULL)
				free(tab[i]);
			i++;
		}
	}
	free(tab);
}

int	ft_parsing(int argc, char **argv, t_game *game)
{
	if (check_args(argc, argv) != 0)
		return (write(2, "Error\nwrong args\n", 17));
	if (open_file(argv) != 0)
		return (write(2, "Error\nmap can't be opened or directory\n", 39));
	if (parse_file(argv, game) != 0)
		return (write(2, "Error\nfile problems_file\n", 25));
	if (ft_parse_file_2(game) != 0)
	{
		ft_free_tab(game->file.all_file);
		return (free(game->file.tab1), write(2, "Error\nfile problems_file\n", 25));
	}
	ft_parse_file_3(game);
	ft_parse_texture(game);
	ft_parse_pos(game);
	game->data.no = ft_parse_path(game, game->no_pos, 0);
	game->data.so = ft_parse_path(game, game->so_pos, 0);
	game->data.we = ft_parse_path(game, game->we_pos, 0);
	game->data.ea = ft_parse_path(game, game->ea_pos, 0);
	return (0);
}
