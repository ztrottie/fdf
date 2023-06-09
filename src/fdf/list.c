/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:58:31 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/30 09:35:41 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf/fdf.h"

void	add_line_end(t_fdf *var, char **line)
{
	t_map	*ptr;

	if (!var->map)
	{
		var->map = ft_calloc(1, sizeof(t_map));
		var->map->line = line;
	}
	else
	{
		ptr = var->map;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = ft_calloc(1, sizeof(t_map));
		ptr->next->line = line;
	}
}
