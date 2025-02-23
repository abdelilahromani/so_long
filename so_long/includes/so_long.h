/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:22:54 by aromani           #+#    #+#             */
/*   Updated: 2025/02/23 18:09:10 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "get_next_line.h"
# include <fcntl.h>

typedef struct game
{
    char *line_map;
    char **map;
    char  *lines;
    int len;
    int coll;
    int exit;
    int pos;
    struct game *next;
}   t_game;

int     ft_strcmp(char *s1, char *s2);
size_t	count_words(char const *str, int sep);
size_t	ft_strcpy(char *dst, char const *src, size_t index, char c);
int     map_validation(t_game **game, int ac, char **av);
void	ft_free(char **p, size_t index);
char	*ft_itoa(int nbr);
int	ft_atoi(const char *str);
int     ft_strlen(char *str);
void	ft_lstclear(t_game **lst);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char*s2);

#endif