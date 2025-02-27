/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:10:45 by aromani           #+#    #+#             */
/*   Updated: 2025/02/27 15:53:25 by aromani          ###   ########.fr       */
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


static void filler(char **str, t_game **game)
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

static int checker(char **str,t_game **game)
{
    filler(str,game);
    if ((*game)->exit != 1)
        return (ft_printf("the map must have 1 exit !!\n"),ft_free((*game)->map), free((*game)->lines), free(*game), exit(0), 0);
    if ((*game)->coll == 0)
        return (ft_printf("the map must at least 1 collect !!\n"),ft_free((*game)->map), free((*game)->lines), free(*game), exit(0), 0);
    if ((*game)->pos != 1)
        return (ft_printf("the map must have 1 player !!\n"),ft_free((*game)->map), free((*game)->lines), free(*game), exit(0), 0);
    return (1);
}



static  int get_map(t_game **game,int fd)
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
            return (ft_printf("the map have empty line !!\n"), exit(1), 0);
        (*game)->lines = ft_strjoin(tmp,(*game)->line_map);
        free(tmp);
        free((*game)->line_map);
    }
    return (close(fd), 1);
}


#include <stdio.h>
int map_validation(t_game **game, int ac, char **av)
{
    int fd;

    if (ac < 2)
        return (0);
    if (fex_check(av[1]) != 0)
        return (ft_printf("unvalid extention file !!\n"), exit(1), 0);
    fd = open (av[1],O_RDONLY);
    if (fd < 0)
        return (ft_printf("unvalid file  !!\n"), exit(1),0);
    *game = malloc(sizeof(t_game));
    if (!game)
        return (0);
    (*game)->frames = 0;
    get_map(game,fd);
    if (map(game) == 0)
        return (ft_printf("unvalid characters !!\n"),ft_free((*game)->map), free((*game)->lines), free(*game), exit(0),0);
    if (check_rec((*game)->map) == 0)
        return (ft_printf("the map must be rectangular !!\n"),ft_free((*game)->map), free((*game)->lines), free(*game), exit(0), 0);
    if (wall_check((*game)->map) == 0)
        return (ft_printf("the map must be by surroended by wall !!\n"),ft_free((*game)->map), free((*game)->lines), free(*game), exit(0) ,0);
    checker((*game)->map, game);
    map_copy(game);
    return (0);
}

