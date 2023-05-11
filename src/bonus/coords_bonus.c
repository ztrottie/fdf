/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:51:39 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/11 14:10:10 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

static int	get_z_value(char *z, int index, t_fdf *var, int scale)
{
	int		z_value;
	char	**str;

	str = ft_split(z, ',');
	z_value = ft_atoi(str[0]) * scale;
	if (!str[1])
		var->coords[index].color = WHITE_COLOR;
	else
		var->coords[index].color = convert_color(str[1] + 2);
	ft_x2free((void **)str);
	return (z_value - z_value / 2);
}

void	init_coords(t_fdf *var, int scale)
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
			var->coords[i].x = ((x - ((var->map_width - 1) / 2)) * scale);
			var->coords[i].y = ((y - ((var->map_height - 1) / 2)) * scale);
			var->coords[i].z = get_z_value(ptr->line[x], i, var, scale);
			x++;
			i++;
		}
		ptr = ptr->next;
		y++;
	}
}
