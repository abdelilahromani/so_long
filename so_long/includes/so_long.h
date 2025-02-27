/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:22:54 by aromani           #+#    #+#             */
/*   Updated: 2025/02/27 14:54:00 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "get_next_line.h"
# include "ft_printf.h"
#include <mlx.h>
# include <fcntl.h>

# ifndef size_pic
# define size_pic 32
# endif

typedef struct game
{
    char *line_map;
    char **map;
    char **map_copy;
    char  *lines;
    int coll;
    int exit;
    int pos;
    int x_p;
    int x_door;
    int y_p;
    int y_door;
    int withe;
    int hight;
    int m_size;
    void *p_pic;
    void *w_pic;
    void *f_pic;
    void *c_pic;
    void *e_pic;
    void *mlx_pointer;
    void *win_pointer;
    struct game *next;
}   t_game;

int     ft_strcmp(char *s1, char *s2);
size_t	count_words(char const *str, int sep);
size_t	ft_strcpy(char *dst, char const *src, size_t index, char c);
int     map_validation(t_game **game, int ac, char **av);
void	ft_free(char **p);
char	*ft_itoa(int nbr);
int	ft_atoi(const char *str);
int     ft_strlen(char *str);
void	ft_lstclear(t_game **lst);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char*s2);
void    map_copy(t_game **map);
void mlx_draw(t_game **game);
int moves_keys(int key_code, t_game *game);
int wall_check(char **str);
int check_rec(char **str);
int map_alpha(char *str);
int map(t_game **map);
int destroy_free(t_game **game, void *mlx);

#endif