/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:10:59 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/20 17:44:17 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_file(char **argv, t_game *game)
{
	int		file;
	char	*tab;
	char	*tab2;
	int		i;

	i = 0;
	file = open(argv[1], O_RDONLY, 0777);
	tab = get_next_line(file);
	while(1)
	{
		i++;
		tab2 = get_next_line(file);
		if (!tab2)
			break;
		tab = ft_strjoinfree2(tab, tab2);
		free(tab2);
	}
	if(tab == NULL)
		return(1);
	game->file.all_file = ft_split(tab, '\n');
	free(tab);
	if (i == 0)
		return (1);
	return (0);
}
int	ft_parse_file_2(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while(game->file.all_file[i])
	{
		j = 0;
		while(game->file.all_file[i][j])
		{
			if (game->file.all_file[i][j] != ' ' 
				&& game->file.all_file[i][j] != '\t' 
					&& game->file.all_file[i][j] != '\n')
				k++;
			j++;
		}
		i++;
	}
	if (k == 0)
		return (1);
	return (0);
}

void	ft_save_line(t_game *g, int i, int j, int *k)
{
	while(g->file.all_file[i][j] && (*k) < 4)
	{
		if(g->file.all_file[i][j] == 'N' && g->file.all_file[i][j + 1]
				&& g->file.all_file[i][j + 1] == 'O')
				g->file.tab_txt[(*k)++] = ft_strdup(g->file.all_file[i]);
		else if(g->file.all_file[i][j] == 'S' && g->file.all_file[i][j + 1]
				&& g->file.all_file[i][j + 1] == 'O')
				g->file.tab_txt[(*k)++] = ft_strdup(g->file.all_file[i]);
		else if(g->file.all_file[i][j] == 'W' && g->file.all_file[i][j + 1]
				&& g->file.all_file[i][j + 1] == 'E')
				g->file.tab_txt[(*k)++] = ft_strdup(g->file.all_file[i]);
		else if(g->file.all_file[i][j] == 'E' && g->file.all_file[i][j + 1]
				&& g->file.all_file[i][j + 1] == 'A')
				g->file.tab_txt[(*k)++] = ft_strdup(g->file.all_file[i]);
		j++;
	}
}

void	ft_parse_file_3(t_game *game)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	game->file.tab_txt = malloc(sizeof(char *) * (4 + 1));
	//ft_save_line(game, i, j, game->file.tab_txt);
	while (game->file.all_file[i])
	{
		j = 0;
		ft_save_line(game, i, j, &k);
		i++;
	}
	game->file.tab_txt[k] = NULL;
}
