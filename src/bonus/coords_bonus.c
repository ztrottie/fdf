/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:51:39 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/02 14:04:37 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

int	get_z_value(char *z, int index, t_fdf *var)
{
	int		z_value;
	char	**str;
	
	str = ft_split(z, ',');
	z_value = ft_atoi(str[0]) * 30;
	if (!str[1])
		var->coords[index].color = WHITE_COLOR;
	else
	{
		var->coords[index].color = convert_color(str[1], var);
	}
	ft_free(str);
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
			var->coords[i].z = get_z_value(ptr->line[x], i, var);
			x++;
			i++;
		}
		ptr = ptr->next;
		y++;
	}
}
