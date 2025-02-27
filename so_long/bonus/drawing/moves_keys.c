/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:16:38 by aromani           #+#    #+#             */
/*   Updated: 2025/02/27 15:55:02 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

#include <stdio.h>

void f()
{
    system("leaks so_long");
}

void moves(t_game *game, int n_x, int n_y)
{
    if (game->map[n_y][n_x] != '1' && game->map[n_y][n_x] != 'E')
    {
        if (game->map[n_y][n_x] == 'C')
        {
            game->map[n_y][n_x] = '0';
            game->coll--;
        }
        if ((game->y_p != n_y) || (game->x_p != n_x))
        {
            game->m_size++;
            ft_printf("%d\n",game->m_size);
        }
        game->x_p = n_x;
        game->y_p = n_y;
    }
    else if (game->coll == 0 && game->map[n_y][n_x] == 'E')
    {
        ft_printf("you win\n");
        destroy_free(game,game->mlx_pointer);
    }
}

void animate(t_game *g)
{
    g->frames++;
    if (g->frames > 60)
    {
        g->frames = 0;
        g->c_pic_anime *= -1;
    }
}

int drow(t_game **game)
{
    int i = 0;
    int j = 0;

    mlx_clear_window((*game)->mlx_pointer, (*game)->win_pointer);
   while (i < (*game)->hight)
    {
        j = 0;
        while (j < (*game)->withe)
        {
            if ((*game)->map[i][j] == '1')
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->w_pic, j * size_pic , i* size_pic);
            else if ((*game)->map[i][j] == 'P')
            {
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->f_pic, j * size_pic , i * size_pic);
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->p_pic, j * size_pic , i * size_pic);
            }   
            else if ((*game)->map[i][j] == 'C')
            {
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->f_pic, j * size_pic , i * size_pic);
                if ((*game)->c_pic_anime == 1)
                    mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->c_pic[0], j * size_pic , i * size_pic);
                else
                    mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->c_pic[1], j * size_pic , i * size_pic);
            }
            else if ((*game)->map[i][j] == 'E')
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->e_pic, j * size_pic , i * size_pic);
            else if ((*game)->map[i][j] == 'N')
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->n_pic[(i + j) % 4] , j * size_pic , i * size_pic);
            else
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->f_pic, j * size_pic , i * size_pic);
            j++;
        }
        i++;
    }
    animate(*game);
    return (0);
}

int moves_keys(int key_code, t_game *game)
{
    //(void)(game)->map;
    // findexit(game->map,&game);
    int n_x;
    int n_y;

    n_x = game->x_p;
    n_y = game->y_p;
    game->map[game->y_p][game->x_p] = '0';
    //game->map[game->y_door][game->x_door] = '1';
    if (key_code == 0)
       n_x--;
    else if (key_code == 13)
        n_y--;
    else if (key_code == 2)
        n_x++;
    else if (key_code == 1)
        n_y++;
    else if (key_code == 53)
        destroy_free(game, game->mlx_pointer);
    moves(game,n_x,n_y);
    // while (game->map[i])
    //     printf("%s\n",game->map[i++]);
    mlx_put_image_to_window(game->mlx_pointer, game->win_pointer,game->p_pic,(game->x_p * size_pic), (game->y_p * size_pic));
    //mlx_put_image_to_window(game->mlx_pointer, game->win_pointer,game->e_pic,(game->x_door * size_pic), (game->y_door * size_pic));
    return (0);
}