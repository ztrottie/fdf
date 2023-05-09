/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:35:05 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/03 15:39:42 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

void	key_translate_up_down(mlx_key_data_t keydata, t_fdf *var)
{
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		if (var->y_trans < INT_MAX)
		{
			var->y_trans -= var->speed;
			print_points(var);
		}
	}
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		if (var->y_trans > INT_MIN)
		{
			var->y_trans += var->speed;
			print_points(var);
		}
	}
}

void	key_translate_left_right(mlx_key_data_t keydata, t_fdf *var)
{
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		if (var->x_trans < INT_MAX)
		{
			var->x_trans -= var->speed;
			print_points(var);
		}
	}
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS \
	|| keydata.action == MLX_REPEAT))
	{
		if (var->x_trans > INT_MIN)
		{
			var->x_trans += var->speed;
			print_points(var);
		}
	}
}
