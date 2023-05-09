/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:11:24 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/03 15:50:37 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

void	key_rotate_z(mlx_key_data_t keydata, t_fdf *var)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		var->z_deg += var->speed;
		if (var->z_deg >= 360)
			var->z_deg -= 360;
		print_points(var);
	}
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		var->z_deg -= var->speed;
		if (var->z_deg < 0)
			var->z_deg += 360;
		print_points(var);
	}
}

void	key_rotate_x(mlx_key_data_t keydata, t_fdf *var)
{
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		var->x_deg += var->speed;
		if (var->x_deg >= 360)
			var->x_deg -= 360;
		print_points(var);
	}
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		var->x_deg -= var->speed;
		if (var->x_deg < 0)
			var->x_deg += 360;
		print_points(var);
	}
}

void	key_rotate_y(mlx_key_data_t keydata, t_fdf *var)
{
	if (keydata.key == MLX_KEY_E && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		var->y_deg += var->speed;
		if (var->y_deg >= 360)
			var->y_deg -= 360;
		print_points(var);
	}
	if (keydata.key == MLX_KEY_Q && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		var->y_deg -= var->speed;
		if (var->y_deg < 0)
			var->y_deg += 360;
		print_points(var);
	}
}
