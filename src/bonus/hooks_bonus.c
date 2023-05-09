/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:45:50 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/03 16:29:48 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

static void	speed_key(mlx_key_data_t keydata, t_fdf *var)
{
	if (keydata.key == MLX_KEY_Z && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		if (var->speed < 100)
		{
			var->speed += 1;
			print_points(var);
		}
	}
	if (keydata.key == MLX_KEY_X && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		if (var->speed > 1)
		{
			var->speed -= 1;
			print_points(var);
		}
	}
}

static void	projection_key(mlx_key_data_t keydata, t_fdf *var)
{
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
	{
		if (var->proj_selec == 1)
		{
			var->proj_selec = 0;
			var->x_deg = 35;
			var->z_deg = 45;
			var->y_deg = 0;
		}
		else if (var->proj_selec == 0)
		{
			var->proj_selec = 1;
			var->x_deg = 90;
			var->y_deg = 0;
			var->z_deg = 0;
		}
		print_points(var);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*var;

	var = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit("fdf closed\n", var, 0);
	projection_key(keydata, var);
	key_translate_up_down(keydata, var);
	key_translate_left_right(keydata, var);
	key_rotate_z(keydata, var);
	key_rotate_x(keydata, var);
	key_rotate_y(keydata, var);
	speed_key(keydata, var);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fdf	*var;

	xdelta = 0;
	var = param;
	if (ydelta > 0)
	{
		if (var->scale < 10)
		{
			var->scale *= 1.1;
			print_points(var);
		}
	}
	else if (ydelta < 0)
	{
		if (var->scale > 0)
		{
			var->scale /= 1.1;
			print_points(var);
		}
	}
}
