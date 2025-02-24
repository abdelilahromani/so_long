/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:25:08 by aromani           #+#    #+#             */
/*   Updated: 2025/02/24 21:14:13 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>


void find_pos(char **map,t_game **game)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                (*game)->x_p = j;
                (*game)->y_p = i;
            }
            j++;
        }
        i++;
    }
    (*game)->hight = i;
    (*game)->withe = ft_strlen(map[0]);
}



void floodfill(t_game **game, char **map, int x, int y, int with, int hight)
{
    if (x < 0 || x >= (*game)->withe || y < 0 || y >= (*game)->hight || map[y][x] == '1' || map[y][x] == 'S')
        return ;
    if (map[y][x] == 'C')
        (*game)->coll--;
    if (map[y][x] == 'E')
        (*game)->exit--;
    map[y][x] = 'S';
    
    floodfill(game,map,x - 1, y, with,hight);
    floodfill(game,map,x + 1, y, with,hight);
    floodfill(game,map,x , y - 1, with,hight);
    floodfill(game,map,x , y + 1, with,hight);
}

void map_copy(t_game **game)
{
    int c;
    int e;
    (*game)->withe = 0;
    (*game)->hight = 0;

    (*game)->map_copy = ft_split((*game)->lines, '\n');
    if (!(*game)->map_copy)
        return ;
    find_pos((*game)->map_copy,game);
    c = (*game)->coll;
    e = (*game)->exit;
    floodfill(game,(*game)->map_copy,(*game)->x_p,(*game)->y_p,(*game)->withe, (*game)->hight);
    if ((*game)->coll != 0 || (*game)->exit != 0)
        return (ft_free((*game)->map_copy), ft_free((*game)->map), free((*game)->lines), free(*game));
    (*game)->coll = c;
    (*game)->exit = e;
    ft_free((*game)->map_copy);
    free((*game)->lines);
}