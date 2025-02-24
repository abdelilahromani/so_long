/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:10:45 by aromani           #+#    #+#             */
/*   Updated: 2025/02/24 21:09:20 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>
#include <libc.h>

static int fex_check(char *f)
{
    int i;

    i = 0;
    while (f[i])
        i++;
    i--;
    while (f[i] && f[i] != '.')
        i--;
    if (ft_strcmp(&f[i], ".ber") == 0)
        return (0);
    return (1);
}

int map_alpha(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != 'C'
        && str[i] != 'E' && str[i] != 'P')
            return (0);
        i++;
    }
    return (1);
}



void filler(char **str, t_game **game)
{
    int i;
    int j;

    (*game)->pos = 0;
    (*game)->coll = 0;
    (*game)->exit = 0;
    i = 0;
    while (str[i])
    {
        j = 0;
        while (str[i][j] != '\0')
        {
            if (str[i][j] == 'P') 
                (*game)->pos++;
            else if (str[i][j] == 'C')
                (*game)->coll++;
            else if (str[i][j] == 'E')
                (*game)->exit++;
            j++;
        }
        i++;
    }
}

int checker(char **str,t_game **game)
{
    filler(str,game);
    if ((*game)->exit != 1)
        return (0);
    if ((*game)->coll == 0)
        return (0);
    if ((*game)->pos != 1)
        return (0);
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

int get_map(t_game **game,int fd)
{ 
    char *tmp;

    (*game)->lines = NULL;
    while (1)
    {
        if ((*game)->lines == NULL)
            (*game)->lines = ft_strdup("");
        tmp = (*game)->lines;
        (*game)->line_map = get_next_line(fd);
        if (!(*game)->line_map)
            break ;
        if (ft_strcmp((*game)->line_map,"\n") == 0)
            return (write (2, "unvalid map\n" ,12), exit(1), 0);
        (*game)->lines = ft_strjoin(tmp,(*game)->line_map);
        free(tmp);
        free((*game)->line_map);
    }
    return (close(fd), 1);
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

#include <stdio.h>
int map_validation(t_game **game, int ac, char **av)
{
    int fd;

    if (ac < 2)
        return (0);
    if (fex_check(av[1]) != 0)
        return (write (2, "unvalid file\n" ,13), exit(1), 0);
    fd = open (av[1],O_RDONLY);
    if (fd < 0)
        return (write (2, "unvalid file\n" ,13), exit(1),0);
    *game = malloc(sizeof(t_game));
    if (!game)
        return (0);
    get_map(game,fd);
    if (map(game) == 0)
        return (write (2, "unvalid map\n" ,12),ft_free((*game)->map), free((*game)->lines), free(*game), 0);
    if (check_rec((*game)->map) == 0)
        return (write (2, "unvalid map\n" ,12),ft_free((*game)->map), free((*game)->lines), free(*game), 0);
    if (wall_check((*game)->map) == 0)
        return (write (2, "unvalid map\n" ,12),ft_free((*game)->map), free((*game)->lines), free(*game), 0);
    if (checker((*game)->map, game) == 0)
        return (write (2, "unvalid map\n" ,12),ft_free((*game)->map), free((*game)->lines), free(*game), 0);
    map_copy(game);
    return (0);
}

