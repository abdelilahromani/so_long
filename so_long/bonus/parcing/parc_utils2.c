/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:31:10 by aromani           #+#    #+#             */
/*   Updated: 2025/02/27 04:24:34 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int wall_check(char **str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (str[i] && str[i][len] == '1')
        len++;
    if (ft_strlen(str[i]) != len)
        return (0);
    i++;
    len--;
    while (str[i + 1] != NULL)
    {
        if (str[i][0] != '1' || str[i][len] != '1')
            return (0);
        i++;
    }
    len = 0;
    while (str[i] && str[i][len] == '1')
        len++;
    if (ft_strlen(str[i]) != len)
        return (0);
    return (1);
}

int check_rec(char **str)
{
    int i;
    int len;

    i = 0;
    if (!str)
        return (0);
    len = ft_strlen(str[i]);
    while (str[i])
    {
        if (ft_strlen(str[i]) != len)
            return (0);
        i++;
    }
    return (1);
}

int map_alpha(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != 'C'
        && str[i] != 'E' && str[i] != 'P' && str[i] != 'N')
            return (0);
        i++;
    }
    return (1);
}

int map(t_game **map)
{
    int i;

    i = 0;
    (*map)->map = ft_split((*map)->lines,'\n');
    if (!(*map)->map)
        return (0);
    while ((*map)->map[i])
    {
        if (map_alpha((*map)->map[i++]) == 0)
            return (0);
    }
    return (1);
}