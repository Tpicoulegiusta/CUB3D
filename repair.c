/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repair.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:46:53 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/18 14:21:32 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_repair(t_game *game)
{
    int		i;
    int		count;
	int		j;
	//char	**tab_tab;
	int		start;
	int		k;

	count = 0;   
    i = 0;
	j = 0;
//	printf("'%s'\n", game->file.tab1);
    while(game->file.tab1[i])
    {
        if (game->file.tab1[i] == '\n')
            count++;
        i++;
    }
	game->nb_line = count;
	i = 0;
	game->tab_tab = malloc(sizeof(char *) * (count + 2));
	while(i <= count)
	{
		start = j;
		while(game->file.tab1[j] != '\n' && game->file.tab1[j] != '\0')
			j++;
		game->tab_tab[i] = malloc(sizeof(char) * (j - start + 2));
		j++;
		i++;
	}
	i = 0;
	j = 0;
	while(game->file.tab1[j])
	{
		k = 0;
		while(game->file.tab1[j] != '\0' && game->file.tab1[j] != '\n')
		{
			game->tab_tab[i][k] = game->file.tab1[j];
			j++;
			k++;
		}
		if (game->file.tab1[j] == '\n')
		{
			game->tab_tab[i][k] = '\n';
			k++;
			j++;
		}
		game->tab_tab[i][k] = '\0';
		i++;
	}
	game->tab_tab[i] = NULL;
}

void	ft_last_line_2(t_game *game)
{
	int	i;
	int	j;

	i = game->nb_line - 1;
	while(i > 0)
	{
		j = 0;
		while(game->tab_tab[i][j])
		{
			j = 0;
			while(game->tab_tab[i][j] == ' ' || game->tab_tab[i][j] == '\t')
				j++;
			if(game->tab_tab[i][j] == '\n')
			{
				i--;
				continue;
			}
			else
			{
				game->last_line_2 = i;
				return ;
			}
		}
	}
}

void	ft_first_line_2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i <= game->last_line_2)
	{
		j = 0;
		while(game->tab_tab[i][j] == ' ')
			j++;
		if (game->tab_tab[i][j + 1] && game->tab_tab[i][j] != '1')
		{
			i++;
			continue;
		}
		if (game->tab_tab[i][j + 1] && game->tab_tab[i][j] == '1')
		{
			game->first_line_2 = i;
			return ;
		}
		i++;
	}
}

void	ft_last_man(t_game *game)
{
	int	i;
	int	j;

	i = game->first_line_2;
	j = 0;
	while(i < game->last_line_2)
	{
		if(game->tab_tab[i][j] == '\n')
		{
			printf("Error_backslah\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

// pas de \n attention \brief ddd
// Error_backslah wtf ?? :O
// Erreur t_p_color colorz Oooohhh