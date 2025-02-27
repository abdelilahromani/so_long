/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:22:04 by aromani           #+#    #+#             */
/*   Updated: 2025/02/27 15:47:23 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <stdio.h>

// void f()
// {
//     system("leaks so_long");
// }

int freea(t_game *game)
{
    if ((game)->c_pic[0])
        mlx_destroy_image((game)->mlx_pointer,(game)->c_pic[0]);
    if ((game)->c_pic[1])
        mlx_destroy_image((game)->mlx_pointer,(game)->c_pic[1]);
    if ((game)->p_pic)
        mlx_destroy_image((game)->mlx_pointer,(game)->p_pic);
    if ((game)->w_pic)
        mlx_destroy_image((game)->mlx_pointer,(game)->w_pic);
    if ((game)->f_pic)
        mlx_destroy_image((game)->mlx_pointer,(game)->f_pic);
    if ((game)->e_pic)
        mlx_destroy_image((game)->mlx_pointer,(game)->e_pic);
    mlx_destroy_window((game)->mlx_pointer,(game)->win_pointer);
    return (ft_free((game)->map), free(game), exit(0),0);
}

int main(int ac,char **av)
{
    t_game *game;
    int i;

    i = 0;
    //atexit(f);
    
    game = NULL;
    map_validation(&game,ac,av);
    // while (game->map[i])
    //     printf("%s \n", game->map[i++]);
    mlx_draw(&game);
    printf("ijgfigf\n");
    mlx_hook((game)->win_pointer, 2, 0, moves_keys, game);
    mlx_hook((game)->win_pointer, 17, 0, freea, game);
    mlx_loop_hook((game)->mlx_pointer, drow, &game);
    mlx_loop((game)->mlx_pointer);
    return (0);
    // if(map_validation(&game,ac,av) == 0)
    // {
    //     printf("unvalid map");
    //     return(0);
    // }
   //printf("%s",game->lines);
    //ft_lstclear(&game);
}