/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:27:42 by aromani           #+#    #+#             */
/*   Updated: 2025/02/26 00:49:10 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void get_images(void *mlx,t_game **game)
{
    int img_with;
    int img_hight;

    img_with = 50;
    img_hight = 50;
    (*game)->c_pic = mlx_xpm_file_to_image(mlx,"./textures/coins.xpm",&img_with, &img_hight);
    (*game)->p_pic = mlx_xpm_file_to_image(mlx,"./textures/player.xpm",&img_with,&img_hight);
    (*game)->w_pic = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm",&img_with,&img_hight);
    (*game)->f_pic = mlx_xpm_file_to_image(mlx, "./textures/floor2.xpm",&img_with,&img_hight);
    (*game)->e_pic = mlx_xpm_file_to_image(mlx, "./textures/exit.xpm",&img_with,&img_hight);

    if (!(*game)->c_pic || !(*game)->p_pic || !(*game)->w_pic || !((*game)->f_pic))
        return ;
}

#include <stdio.h>
void mlx_draw(t_game **game, char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    (*game)->mlx_pointer = mlx_init();
    get_images((*game)->mlx_pointer, game);
    (*game)->win_pointer = mlx_new_window((*game)->mlx_pointer, (*game)->withe * 50, (*game)->hight * 50, "so_long");
    while (i < (*game)->hight)
    {
        
        j = 0;
        while (j < (*game)->withe)
        {
            //mlx_put_image_to_window(mlx, win, (*game)->f_pic, i * 50 , j * 50);
            if (map[i][j] == '1')
            {
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->w_pic, j * 50 , i* 50);
            }
            else if (map[i][j] == 'P')
            {
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->f_pic, j * 50 , i * 50);
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->p_pic, j * 50 , i * 50);
            }   
            else if (map[i][j] == 'C')
            {
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->f_pic, j * 50 , i * 50);
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->c_pic, j * 50 , i * 50);
            }
            else if (map[i][j] == 'E')
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->e_pic, j * 50 , i * 50);
            else
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->f_pic, j * 50 , i * 50);
            j++;
        }
        i++;
    }
    mlx_key_hook((*game)->win_pointer, moves_keys, *game);
    mlx_loop((*game)->mlx_pointer);
}
