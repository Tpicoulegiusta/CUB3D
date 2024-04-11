/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:22:19 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/10 14:32:14 by tpicoule         ###   ########.fr       */
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
