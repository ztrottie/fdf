/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:05:59 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/25 16:52:15 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	get_points(t_fdf *var)
{
	int	i;
	int	x;
	int	y;
	int	deg;
	
	var->points = ft_calloc(var->total_coord, sizeof(t_coords));
	ft_printf("ymod:%d xmod:%d\n", var->y_mod, var->x_mod);
	i = 0;
	deg = atan(hypot(var->map_width, var->map_height));
	while (i < var->total_coord)
	{
		x = var->coords[i].x * cos(45) + var->coords[i].y * -sin(45);
		y = var->coords[i].x * sin(45) + var->coords[i].y * cos(45);
		y = y * cos(deg) + var->coords[i].z * -sin(deg);
		var->points[i].x = x;
		var->points[i].y = y;
		i++;
	}
}

void	print_points(t_fdf *var)
{
	int			i;
	int			x;
	int			y;
	i = 0;
	set_backgroud(var);
	get_points(var);
	while (i < var->total_coord)
	{
		x = var->points[i].x + var->x_mod;
		y = var->points[i].y + var->y_mod;
		if (x <= WIDTH && y <= HEIGHT && x >= 0 && y >= 0)
			mlx_put_pixel(var->img, x, y, 0xFFFFFFFF);
		i++;
	}
	mlx_image_to_window(var->mlx, var->img, 0, 0);
}
