/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:26:10 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/18 14:34:19 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/// @brief set_image function initialize a new image and put it to the window
/// using MLX42 functions and set the var->img variable;
/// @param var 
void	set_image(t_fdf *var)
{
	var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	if (!var->img)
		ft_exit("NEW IMAGE", var, 0);
	mlx_image_to_window(var->mlx, var->img, 0, 0);
}

/// @brief set_backgroud fucntion just set the backgroud in black 
/// for when i will need to print the wireframe
/// @param var fdf main structure
void	set_backgroud(t_fdf *var)
{
	int	x;
	int	y;

	if (!var->img)
		set_image(var);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			mlx_put_pixel(var->img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}