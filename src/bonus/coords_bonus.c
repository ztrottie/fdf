/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:51:39 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/01 16:33:29 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

int	get_z_value(char *z, t_fdf *var)
{
	int	z_value;
	
	z_value = ft_atoi(z) * 30;
	if (z_value < var->z_min)
		var->z_min = z_value;
	if (z_value > var->z_max)
		var->z_max = z_value;
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
			var->coords[i].x = ((x - ((var->map_width - 1) / 2)) * 30);
			var->coords[i].y = ((y - ((var->map_height - 1) / 2)) * 30);
			var->coords[i].z = get_z_value(ptr->line[x], var);
			x++;
			i++;
		}
		ptr = ptr->next;
		y++;
	}
}
