/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:46:00 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/19 17:43:15 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	init_coords(t_fdf *var)
{
	t_map	*ptr;
	int		i;
	int		z;
	int		x;
	
	var->total_coord = var->map_width * var->map_height;
	var->coords = (t_coords *)ft_calloc(var->total_coord, sizeof(t_coords));
	z = 0;
	i = 0;
	ptr = var->map;
	while (ptr != NULL)
	{
		x = 0;
		while (x < var->map_width)
		{
			var->coords[i].x = x * 30;
			var->coords[i].y = ft_atoi(ptr->line[x]) * 30;
			var->coords[i].z = z * 30;
			x++;
			i++;
		}
		ptr = ptr->next;
		z++;
	}
	for(i = 0; i < var->total_coord; i++)
		ft_printf("x:%d y:%d z:%d\n", var->coords[i].x, var->coords[i].y, var->coords[i].z);
}
