/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:05:59 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/30 11:45:58 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf/fdf.h"

void	get_points(t_fdf *var)
{
	int		i;
	int		x;
	int		y;
	double	x_deg;
	double	z_deg;

	var->points = ft_calloc(var->total_coord, sizeof(t_coords));
	i = 0;
	x_deg = 35 * (M_PI / 180);
	z_deg = 45 * (M_PI / 180);
	while (i < var->total_coord)
	{
		x = var->coords[i].x * cos(z_deg) + var->coords[i].y * -sin(z_deg);
		y = var->coords[i].x * sin(z_deg) + var->coords[i].y * cos(z_deg);
		y = y * cos(x_deg) + var->coords[i].z * -sin(x_deg);
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
