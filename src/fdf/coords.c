/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:46:00 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/27 16:35:36 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	get_z_value(char *z)
{
	int	z_value;
	
	z_value = ft_atoi(z) * 30;
	return (z_value - z_value / 2);
}

void	init_coords(t_fdf *var)
{
	t_map	*ptr;
	int		i;
	int		y;
	int		x;

	var->total_coord = var->map_width * var->map_height;
	var->coords = (t_coords *)ft_calloc(var->total_coord, sizeof(t_coords));
	y = 0;
	i = 0;
	ptr = var->map;
	while (ptr != NULL)
	{
		x = 0;
		while (x < var->map_width)
		{
			var->coords[i].x = (x - ((var->map_width - 1) / 2)) * 30;
			var->coords[i].y = (y - ((var->map_height - 1) / 2)) * 30;
			var->coords[i].z = get_z_value(ptr->line[x]);
			x++;
			i++;
		}
		ptr = ptr->next;
		y++;
	}
}
