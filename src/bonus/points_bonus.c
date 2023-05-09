/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:53:37 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/03 16:22:33 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

static void	get_points(t_fdf *var)
{
	int			i;
	t_coords	result;

	if (!var->points)
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

static void	put_hud(t_fdf *var)
{
	char	*str;
	char	*str2;
	char	*nb;

	nb = ft_itoa(var->speed);
	str = ft_strjoin("Speed = ", nb);
	str2 = ft_strjoin(str, " [Z][X]");
	var->hud[0] = mlx_put_string(var->mlx, "Buttons", 20, 20);
	var->hud[1] = mlx_put_string(var->mlx, "Projection [P]", 20, 40);
	var->hud[2] = mlx_put_string(var->mlx, "Rotation z:[A][D] x:[W][S] y:[Q][E]", 20, 60);
	var->hud[3] = mlx_put_string(var->mlx, "Translate [UP][DOWN][LEFT][RIGHT]", 20, 80);
	var->hud[4] = mlx_put_string(var->mlx, "Zoom [SCROLL]", 20, 100);
	var->hud[5] = mlx_put_string(var->mlx, str2, 20, 120);
	ft_free(str2);
	ft_free(str);
	ft_free(nb);
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
			mlx_put_pixel(var->img, x, y, var->coords[i].color);
		i++;
	}
	print_lines(var);
	mlx_image_to_window(var->mlx, var->img, 0, 0);
	put_hud(var);
}
