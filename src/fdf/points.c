/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:05:59 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/27 16:44:31 by ztrottie         ###   ########.fr       */
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
	i = 0;
	deg = atan(hypot(var->map_width, var->map_height));
	while (i < var->total_coord)
	{
		x = var->coords[i].x * cos(45) + var->coords[i].y * -sin(45);
		y = var->coords[i].x * sin(45) + var->coords[i].y * cos(45);
		y = y * cos(deg) + var->coords[i].z * -sin(deg);
		var->points[i].x = x + WIDTH / 2 + var->x_mod;
		var->points[i].y = y + HEIGHT / 2 + var->y_mod;
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
		x = var->points[i].x;
		y = var->points[i].y;
		if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
			mlx_put_pixel(var->img, x, y, 0xFFFFFFFF);
		i++;
	}
	print_lines(var);
	mlx_image_to_window(var->mlx, var->img, 0, 0);
}
