/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:27:42 by aromani           #+#    #+#             */
/*   Updated: 2025/02/27 04:32:49 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int destroy_free(t_game *game, void *mlx)
{
    if ((game)->c_pic[0])
        mlx_destroy_image(mlx,(game)->c_pic[0]);
    if ((game)->c_pic[1])
        mlx_destroy_image(mlx,(game)->c_pic[1]);
    if ((game)->p_pic)
        mlx_destroy_image(mlx,(game)->p_pic);
    if ((game)->w_pic)
        mlx_destroy_image(mlx,(game)->w_pic);
    if ((game)->f_pic)
        mlx_destroy_image(mlx,(game)->f_pic);
    if ((game)->e_pic)
        mlx_destroy_image(mlx,(game)->e_pic);
    mlx_destroy_window((game)->mlx_pointer,(game)->win_pointer);
    return (ft_free((game)->map), free(game), exit(0),0);
}

static void get_images(void *mlx,t_game **game)
{
    int img_with;
    int img_hight;

    img_with = size_pic;
    img_hight = size_pic;
    (*game)->c_pic[0] = mlx_xpm_file_to_image(mlx,"./texturess/co1.xpm",&img_with, &img_hight);
    (*game)->c_pic[1] = mlx_xpm_file_to_image(mlx,"./texturess/co0.xpm",&img_with, &img_hight);
    (*game)->p_pic = mlx_xpm_file_to_image(mlx,"./texturess/pl.xpm",&img_with,&img_hight);
    (*game)->w_pic = mlx_xpm_file_to_image(mlx, "./texturess/wa.xpm",&img_with,&img_hight);
    (*game)->f_pic = mlx_xpm_file_to_image(mlx, "./texturess/f.xpm",&img_with,&img_hight);
    (*game)->e_pic = mlx_xpm_file_to_image(mlx, "./texturess/ex.xpm",&img_with,&img_hight);
    (*game)->n_pic[0] = mlx_xpm_file_to_image(mlx, "./bonus/texturess/n1.xpm",&img_with,&img_hight);
    (*game)->n_pic[1] = mlx_xpm_file_to_image(mlx, "./bonus/texturess/n2.xpm",&img_with,&img_hight);
    (*game)->n_pic[2] = mlx_xpm_file_to_image(mlx, "./bonus/texturess/n3.xpm",&img_with,&img_hight);
    (*game)->n_pic[3] = mlx_xpm_file_to_image(mlx, "./bonus/texturess/n4.xpm",&img_with,&img_hight);

    if (!(*game)->c_pic[0] || !(*game)->c_pic[1] || !(*game)->p_pic || !(*game)->w_pic || !(*game)->f_pic)
        destroy_free(*game,mlx);
}

void looping(t_game **game, int i, int j)
{
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
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->c_pic[(i + j) % 2], j * size_pic , i * size_pic);
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
}

void mlx_draw(t_game **game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    (*game)->m_size= 0;
    (*game)->mlx_pointer = mlx_init();
    get_images((*game)->mlx_pointer, game);
    (*game)->win_pointer = mlx_new_window((*game)->mlx_pointer, (*game)->withe * size_pic, (*game)->hight * size_pic, "so_long");
    looping(game,i,j);
}
