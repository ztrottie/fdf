/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:53:37 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/01 12:58:49 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

void	get_points(t_fdf *var)
{
	int	i;
	t_coords	result;
	
	var->points = ft_calloc(var->total_coord, sizeof(t_coords));
	i = 0;
	while (i < var->total_coord)
	{
		result = matrice_calculus(var->coords[i], var);
		var->points[i].x = result.x + WIDTH / 2;
		var->points[i].y = result.y + HEIGHT / 2;
		var->points[i].z = result.z;
		i++;
	}
}

void	print_points(t_fdf *var)
{
	int			i;
	int			x;
	int			y;
	int			z;

	i = 0;
	set_backgroud(var);
	get_points(var);
	while (i < var->total_coord)
	{
		x = var->points[i].x;
		y = var->points[i].y;
		z = var->coords[i].z;
		if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
			mlx_put_pixel(var->img, x, y, get_color(z, var));
		i++;
	}
	print_lines(var);
	mlx_image_to_window(var->mlx, var->img, 0, 0);
}
