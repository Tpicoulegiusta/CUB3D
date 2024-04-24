/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:52:03 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/24 13:27:04 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_file_3(t_game *game)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	game->file.tab_txt = malloc(sizeof(char *) * (4 + 1));
	while (game->file.all_file[i])
	{
		j = 0;
		ft_save_line(game, i, j, &k);
		i++;
	}
	game->file.tab_txt[k] = NULL;
	last_check(game);
	if (game->bol != 4)
	{
		ft_free_tab(game->file.all_file);
		ft_free_tab(game->file.tab_txt);
		write(2, "Error\nfile problems_txture\n", 27);
		exit(EXIT_FAILURE);
	}
}

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (1);
	i = ft_strlen(argv[1]) - 4;
	while (i < ft_strlen(argv[1]) + 1)
	{
		if (argv[1][i++] != '.')
			return (1);
		if (argv[1][i++] != 'c')
			return (1);
		if (argv[1][i++] != 'u')
			return (1);
		if (argv[1][i++] != 'b')
			return (1);
		if (argv[1][i++] != '\0')
			return (1);
	}
	return (0);
}

int	open_file(char **argv)
{
	int	can;
	int	directory;

	directory = open(argv[1], __O_DIRECTORY, 0777);
	can = open(argv[1], O_RDONLY, 0777);
	if (can == -1 || directory != -1)
		return (1);
	return (0);
}
