/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:17:54 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/14 10:54:15 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf/fdf.h"
#define HEIGHT 480
#define WIDTH 740

int	main(int argc, char **argv)
{
	mlx_t *mlx;
	
	if (argc != 2)
		return (0);
	argv = 0;
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", 1);
	if (!mlx)
		exit(0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}