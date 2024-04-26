/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:22:19 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/26 16:29:45 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoinfree2(char *stock, char *tmp)
{
	char	*str;

	str = ft_strjoin(stock, tmp);
	if (stock)
		free (stock);
	return (str);
}

void	ft_reduce_2(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < game->nb_line && game->file.tab1[j])
	{
		k = 0;
		while (game->file.tab1[j] != '\0' && game->file.tab1[j] != '\n')
			game->tab_tab[i][k++] = game->file.tab1[j++];
		game->tab_tab[i][k] = '\n';
		k++;
		j++;
		game->tab_tab[i][k] = '\0';
		i++;
	}
	game->tab_tab[i] = NULL;
}
