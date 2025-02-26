/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:16:38 by aromani           #+#    #+#             */
/*   Updated: 2025/02/26 01:46:00 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

#include <stdio.h>

void findexit(char **map, t_game**game)
{
    int i;
    int j;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E')
            {
                (*game)->x_door = j;
                (*game)->y_door = i;
            }
            j++;
        }
        i++;
    }
}

void move_up(t_game *game)
{
     if (game->map[game->y_p - 1][game->x_p] == '1')
        return ;
    else if (game->map[game->y_p - 1][game->x_p] == 'C')
    {
        //mlx_destroy_image(game->mlx_pointer, game->c_pic);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->f_pic, (game->x_p) * 50, ((game)->y_p - 1) * 50);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->f_pic, (game->x_p) * 50, (game)->y_p * 50);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->p_pic, (game->x_p) * 50, ((game)->y_p - 1) * 50);
        game->y_p--;
        game->coll--;
    }else if (game->map[game->y_p - 1][game->x_p] == '0')
    {
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->f_pic, (game->x_p) * 50, (game)->y_p * 50);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->p_pic, (game->x_p) * 50, ((game)->y_p - 1) * 50);
        game->y_p--;
    }
}



void move_left(t_game *game)
{
    findexit(game->map,&game);
    printf("y = %d  || x = %d\n",game->x_door,game->y_door);
    if (game->map[game->y_p][game->x_p - 1] == '1')
        return ;
    else if (game->map[game->y_p][game->x_p - 1] == 'C')
    {
        //mlx_destroy_image(game->mlx_pointer, game->c_pic);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->f_pic, (game->x_p - 1) * 50, (game)->y_p * 50);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->f_pic, (game->x_p) * 50, (game)->y_p * 50);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->p_pic, (game->x_p - 1) * 50, (game)->y_p * 50);
        game->x_p--;
        game->coll--;
    }else if (game->map[game->y_p][game->x_p - 1] == '0')
    {
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->f_pic, (game->x_p) * 50, (game)->y_p * 50);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->p_pic, (game->x_p - 1) * 50, (game)->y_p * 50);
        game->x_p--;
    }else if (game->map[game->y_p][game->x_p - 1] == 'E')
    {
        if (game->coll != 0)
        {
            mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->f_pic, (game->x_p) * 50, (game)->y_p * 50);
            mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->p_pic, (game->x_p - 1) * 50, (game)->y_p * 50);
            game->x_p--;
        }else 
        {
            exit(0);
        }
    }
}
void move_right(t_game *game)
{
    //printf("y = %d  || x = %d\n",game->y_p,game->x_p);
    if (game->map[game->y_p][game->x_p + 1] == '1')
        return ;
    else if (game->map[game->y_p][game->x_p + 1] == 'C')
    {
        //mlx_destroy_image(game->mlx_pointer, game->c_pic);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->f_pic, (game->x_p + 1) * 50, (game)->y_p * 50);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->f_pic, (game->x_p) * 50, (game)->y_p * 50);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->p_pic, (game->x_p + 1) * 50, (game)->y_p * 50);
        game->x_p++;
        game->coll--;
    }else if (game->map[game->y_p][game->x_p + 1] == '0')
    {
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->f_pic, (game->x_p) * 50, (game)->y_p * 50);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->p_pic, (game->x_p + 1) * 50, (game)->y_p * 50);
        game->x_p++;
    }
}

void move_down(t_game *game)
{
     if (game->map[game->y_p + 1][game->x_p] == '1')
        return ;
    else if (game->map[game->y_p + 1][game->x_p] == 'C')
    {
        //mlx_destroy_image(game->mlx_pointer, game->c_pic);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->f_pic, (game->x_p) * 50, ((game)->y_p + 1) * 50);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->f_pic, (game->x_p) * 50, (game)->y_p * 50);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->p_pic, (game->x_p) * 50, ((game)->y_p + 1) * 50);
        game->y_p++;
        game->coll--;
    }else if (game->map[game->y_p + 1][game->x_p] == '0')
    {
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->f_pic, (game->x_p) * 50, (game)->y_p * 50);
        mlx_put_image_to_window(game->mlx_pointer, game->win_pointer, game->p_pic, (game->x_p) * 50, ((game)->y_p +1) * 50);
        game->y_p++;
    }
}
int moves_keys(int key_code, t_game *game)
{
    //(void)(game)->map;
    game->map[game->y_p][game->x_p] = '0';
    if (key_code == 0)
       move_left(game);
    else if (key_code == 13)
        move_up(game);
    else if (key_code == 2)
        move_right(game);
    else if (key_code == 1)
        move_down(game);
    return (0);
}