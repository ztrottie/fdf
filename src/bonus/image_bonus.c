/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:53:21 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/03 15:47:57 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

static void	delete_images(t_fdf *var)
{
	int	i;

	i = -1;
	if (var->img)
		mlx_delete_image(var->mlx, var->img);
	while (++i < 6)
		mlx_delete_image(var->mlx, var->hud[i]);
}

/// @brief set_image function initialize a new image and put it to the window
/// using MLX42 functions and set the var->img variable;
/// @param var 
static void	set_image(t_fdf *var)
{
	delete_images(var);
	var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	if (!var->img)
		ft_exit("NEW IMAGE", var, 0);
}

/// @brief set_backgroud fucntion just set the backgroud in black 
/// for when i will need to print the wireframe
/// @param var fdf main structure
void	set_backgroud(t_fdf *var)
{
	int	x;
	int	y;

	set_image(var);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(var->img, x, y, BLACK_COLOR);
			x++;
		}
		y++;
	}
}
