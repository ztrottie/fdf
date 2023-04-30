/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:45:50 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/30 16:06:45 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

static void	key_translate_up_down(mlx_key_data_t keydata, t_fdf *var)
{
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		if (var->y_trans < INT_MAX)
		{
			var->y_trans -= var->trans_speed;
			print_points(var);
		}
	}
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		if (var->y_trans > INT_MIN)
		{
			var->y_trans += var->trans_speed;
			print_points(var);
		}
	}
}

static void key_translate_left_right(mlx_key_data_t keydata, t_fdf *var)
{
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		if (var->x_trans < INT_MAX)
		{
			var->x_trans -= var->trans_speed;
			print_points(var);
		}
	}
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		if (var->x_trans > INT_MIN)
		{
			var->x_trans += var->trans_speed;
			print_points(var);
		}
	}
}

static void	key_rotate_z(mlx_key_data_t keydata, t_fdf *var)
{
	if (keydata.key == MLX_KEY_E && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		var->z_deg += var->rotation_speed;
		if (var->z_deg > 360)
			var->z_deg -= 360;
		print_points(var);
	}
	if (keydata.key == MLX_KEY_Q && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		var->z_deg -= var->rotation_speed;
		if (var->z_deg < 360)
			var->z_deg += 360;
		print_points(var);
	}
}

static void	key_rotate_x(mlx_key_data_t keydata, t_fdf *var)
{
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		var->x_deg += var->rotation_speed;
		if (var->x_deg > 360)
			var->x_deg -= 360;
		print_points(var);
	}
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		var->x_deg -= var->rotation_speed;
		if (var->x_deg < 0)
			var->x_deg += 360;
		print_points(var);
	}
}

static void key_rotate_y(mlx_key_data_t keydata, t_fdf *var)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		var->y_deg += var->rotation_speed;
		if (var->y_deg > 360)
			var->y_deg -= 360;
		print_points(var);
	}
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		var->y_deg -= var->rotation_speed;
		if (var->y_deg < 0)
			var->y_deg += 360;
		print_points(var);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*var;

	var = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit("fdf closed\n", var, 0);
	key_translate_up_down(keydata, var);
	key_translate_left_right(keydata, var);
	key_rotate_z(keydata, var);
	key_rotate_x(keydata, var);
	key_rotate_y(keydata, var);
}

void	my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_fdf *var;

	xdelta = 0;
	var = param;
	if (ydelta > 0)
	{
		if (var->scale < 10000)
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