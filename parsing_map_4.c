/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:31:22 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/22 13:36:48 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_look_at_me(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->first_line)
	{
		j = 0;
		while (game->file.all_file[i][j] == ' '
			|| game->file.all_file[i][j] == '\t')
			j++;
		if (game->file.all_file[i][j] != '\0' && game->file.all_file[i][j + 1]
			&& (ft_isprint(game->file.all_file[i][j + 1]) == 1))
			game->look++;
		i++;
	}
	if (game->look != 6)
	{
		printf("Error too much line\n");
		exit(EXIT_FAILURE);
	}
}

int	ft_check_l_r(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != '1' && str[i] != '0' && ft_cara(str[i]) != 0)
		i--;
	if (str[i] == '1' || str[i + 1] == ' ')
		return (0);
	return (1);
}


// void	ft_check_left_right(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = game->first_line + 1;
// 	while (i < game->last_line)
// 	{
// 		j = 0;
// 		while (game->file.all_file[i][j])
// 		{
// 			while (game->file.all_file[i][j] == ' ')
// 			{
// 				game->file.all_file[i][j] = '1';
// 				j++;
// 			}
// 			printf("j == %c\n", game->file.all_file[i][j]);
// 			if (game->file.all_file[i][j] != '1')
// 			{
// 				printf("Erreur on line map\n");
// 				exit(EXIT_FAILURE);
// 			}
// 			if (ft_check_l_r(game->file.all_file[i]) == 1)
// 			{
// 				printf("Erreur on line map");
// 				exit(EXIT_FAILURE);
// 			}
// 			break ;
// 		}
// 		i++;
// 	}
// }
