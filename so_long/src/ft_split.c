/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:17:33 by aromani           #+#    #+#             */
/*   Updated: 2025/02/20 17:55:17 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(char **p, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free (p[i]);
		i++;
	}
	free (p);
}

static char	**filler(char **str, char const *s, char c, size_t wo)
{
	size_t	start;
	size_t	end;
	size_t	wn;

	start = 0;
	wn = 0;
	while (wn < wo)
	{
		while (s[start] && s[start] == c)
			start++;
		end = 0;
		while (s[start + end] && s[start + end] != c)
			end++;
		str[wn] = malloc(end + 1);
		if (!str[wn])
		{
			ft_free(str, wn);
			return (NULL);
		}
		start = ft_strcpy(str[wn], s, start, c);
		wn++;
	}
	str[wn] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	len;

	if (!s)
		return (NULL);
	len = count_words(s, c);
	str = (char **)malloc((len + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = filler(str, s, c, len);
	return (str);
}
