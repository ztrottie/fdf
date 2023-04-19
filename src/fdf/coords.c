/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:46:00 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/19 15:20:44 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	init_coords(t_fdf *var)
{
	int 	fd;
	char	**str;
	int		i;
	int		z;
	int		x;
	
	var->total_coord = var->map_width * var->map_height;
	var->coords = (t_coords *)ft_calloc(var->total_coord, sizeof(t_coords));
	fd = open_map(var);
	z = 0;
	i = 0;
	while (z < var->map_height)
	{
		str = split_get_next_line(fd, ' ');
		x = 0;
		while (x < var->map_width)
		{
			var->coords[i].x = x;
			var->coords[i].y = ft_atoi(str[x]);
			var->coords[i].z = z;
			x++;
			i++;
		}
		ft_x2free((void **)str);
		z++;
	}
	for (i = 0; i < var->total_coord; i++)
		ft_printf("x:%d y:%d z:%d\n", var->coords[i].x, var->coords[i].y, var->coords[i].z);
	ft_printf("here the seg?\n");
}
