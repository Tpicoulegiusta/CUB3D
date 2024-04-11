/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:38:07 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/11 16:06:29 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_last_line(t_game *game, int j)
{
	int i;

	i = game->size_tab - 1;
	while (i > 0)
	{
		j = 0;
		while (game->file.all_file[i][j])
		{
			while (game->file.all_file[i][j] == ' ' || game->file.all_file[i][j] == '\t')
				j++;
			if (game->file.all_file[i][j] == '\n' || game->file.all_file[i][j] == '\0')
				break;
			else if (game->file.all_file[i][j] == '1')
			{
				game->last_line = i;
				return ;
			}
			else
			{
				printf("Erreur map_1_smthing down here or missing map\n");
				exit(EXIT_FAILURE);
			}
		}
		i--;
	}
}

void	ft_first_line(t_game *game, int j)
{
	int i;

	i = 0;
	while (i < game->last_line)
	{
		j = 0;
		while (game->file.all_file[i][j])
		{
			while (game->file.all_file[i][j] == ' ' || game->file.all_file[i][j] == '\t')
				j++;
			if (game->file.all_file[i][j] == '\n' ||
					game->file.all_file[i][j] == '\0' ||
						(ft_isprint(game->file.all_file[i][j]) == 1 &&
							game->file.all_file[i][j] != '1'))
					break;
			else if (game->file.all_file[i][j] == '1')
			{
				game->first_line = i;
				return ;
			}
		}
		i++;
	}
}

void	ft_check_line(char *str)
{
	int j;
	
	j = 0;
	while(str[j] == ' ' || str[j] == '1')
		j++;
	if (str[j] != '\0' && str[j] != '\n')
	{
		printf("Erreur on line map\n");
		exit(EXIT_FAILURE);
	}
}
int	ft_cara(int i)
{
	if (i == 'N')
		return (0);
	if (i == 'S')
		return (0);
	if (i == 'W')
		return (0);
	if (i == 'E')
		return (0);
	return (1);
}

int		ft_check_l_r(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	while(str[i] != '1' && str[i] != '0' && ft_cara(str[i]) != 0)
		i--;
	if (str[i] == '1' || str[i + 1] == ' ')
		return (0);
	return (1);
}

void	ft_check_left_right(t_game *game)
{
	int i;
	int j;

	i = game->first_line + 1;
	while(i < game->last_line)
	{
		j = 0;
		while(game->file.all_file[i][j])
		{
			while(game->file.all_file[i][j] == ' ')
				j++;
			if (game->file.all_file[i][j] != '1')
			{
				printf("Erreur on line map\n");
				exit(EXIT_FAILURE);
			}
			if (ft_check_l_r(game->file.all_file[i]) == 1)
			{
				printf("Erreur on line map");
				exit(EXIT_FAILURE);
			}
			break ;
		}
		i++;
	}
}
