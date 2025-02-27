/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:32:44 by aromani           #+#    #+#             */
/*   Updated: 2025/02/23 17:30:18 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_lstclear(t_game **lst)
{
	t_game	*node;
	t_game	*tmp;
	int		i;
	
	i = 0;
	if (!lst)
		return ;
	node = *lst;
	while (node != NULL)
	{
		tmp = node;
		free(tmp->lines);
		while (tmp->map[i])
			free(tmp->map[i++]);
		free(tmp->map);
		free(tmp->line_map);
		free(tmp);
	}
	*lst = NULL;
}
