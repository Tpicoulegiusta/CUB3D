/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:03:25 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/12 16:56:55 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_strsplitdup(char *src, int min, int max)
{
	char	*str;
	int		i;

	i = max - min;
	str = malloc(sizeof(char) * (i + 1));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (min < max)
	{
		str[i] = src[min];
		i++;
		min++;
	}
	str[i] = '\0';
	return (str);
}

static int	ischarset(char c, char charset)
{
	if (charset != '\0')
	{
		if (c == charset)
			return (1);
	}
	return (0);
}

static int	kuantanamo(char *str, char charset)
{
	int		i;
	int		mot;

	i = 0;
	mot = 0;
	while (str[i])
	{
		while (ischarset(str[i], charset) && str[i])
			i++;
		if (str[i])
			mot++;
		while (!ischarset(str[i], charset) && str[i])
			i++;
	}
	return (mot);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (kuantanamo((char *)s, c) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (ischarset(s[i], c) && s[i])
			i++;
		start = i;
		while (!ischarset(s[i], c) && s[i])
			i++;
		if (start != i)
			tab[j++] = ft_strsplitdup((char *)s, start, i);
	}
	tab[j] = NULL;
	return (tab);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*s1;
	int		j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) > len + 1)
		s1 = malloc(sizeof(char) * len + 1);
	else
		s1 = malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	if (!s1)
		return (NULL);
	j = 0;
	while (j < len && s[start])
	{
		s1[j] = s[start];
		j++;
		start++;
	}
	s1[j] = '\0';
	return (s1);
}
