/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:27:42 by aromani           #+#    #+#             */
/*   Updated: 2025/02/27 15:09:31 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int destroy_free(t_game **game, void *mlx)
{
    if ((*game)->c_pic)
        mlx_destroy_image(mlx,(*game)->c_pic);
    if ((*game)->p_pic)
        mlx_destroy_image(mlx,(*game)->p_pic);
    if ((*game)->w_pic)
        mlx_destroy_image(mlx,(*game)->w_pic);
    if ((*game)->f_pic)
        mlx_destroy_image(mlx,(*game)->f_pic);
    if ((*game)->e_pic)
        mlx_destroy_image(mlx,(*game)->e_pic);
    printf("mlx pointer is : %p\n", (*game)->mlx_pointer);
    printf("mlx windows is : %p\n", (*game)->win_pointer);
    mlx_destroy_window((*game)->mlx_pointer, (*game)->win_pointer);
    printf("iug fiug\n");
    return (ft_free((*game)->map), free(*game), exit(0), 0);
}   

void *mlx_load (char *file_path, t_game *game)
{
    int img_with;
    int img_hight;

    char *file = mlx_xpm_file_to_image(game, file_path, &img_with, &img_hight);
    if (!file)
        return NULL;
    return file;
}
static void get_images(void *mlx,t_game **game) 
{

    (*game)->c_pic = mlx_load("./texturess/co1.xpm", *game);
    (*game)->p_pic = mlx_load("./texturess/plesd.xpm",*game);
    (*game)->w_pic = mlx_load( "./texturess/wa.xpm",*game);
    (*game)->f_pic = mlx_load( "./texturess/f.xpm", *game);
    (*game)->e_pic = mlx_load( "./texturess/ex.xpm", *game);

    ft_printf("c_pic %p\n", (*game)->c_pic);
    ft_printf("p_pic %p\n", (*game)->p_pic);
    ft_printf("w_pic %p\n", (*game)->w_pic);
    ft_printf("f_pic %p\n", (*game)->f_pic);
    ft_printf("e_pic %p\n", (*game)->e_pic);
    if (!(*game)->c_pic || !(*game)->p_pic || !(*game)->w_pic || !(*game)->f_pic)
        destroy_free(game,mlx);
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
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->c_pic, j * size_pic , i * size_pic);
            }
            else if ((*game)->map[i][j] == 'E')
                mlx_put_image_to_window((*game)->mlx_pointer, (*game)->win_pointer, (*game)->e_pic, j * size_pic , i * size_pic);
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
    (*game)->win_pointer = mlx_new_window((*game)->mlx_pointer, (*game)->withe * size_pic, (*game)->hight * size_pic, "so_long");
    get_images((*game)->mlx_pointer, game);
    looping(game,i,j);
}
