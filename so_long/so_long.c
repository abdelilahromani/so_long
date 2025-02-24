/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:22:04 by aromani           #+#    #+#             */
/*   Updated: 2025/02/24 20:24:52 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <stdio.h>

void f()
{
    system("leaks so_long");
}

int main(int ac,char **av)
{
    t_game *game;
    int i;

    i = 0;
    atexit(f);
    
    game = NULL;
    map_validation(&game,ac,av);
    // while (game->map[i])
    //     printf("%s \n", game->map[i++]);
    // if(map_validation(&game,ac,av) == 0)
    // {
    //     printf("unvalid map");
    //     return(0);
    // }
   //printf("%s",game->lines);
    //ft_lstclear(&game);
}