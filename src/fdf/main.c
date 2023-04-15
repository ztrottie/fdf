/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:17:54 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/15 14:09:35 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf var;
	mlx_t *mlx;
	
	if (args_error(argc, argv))
		return (0);
	var.map = argv[1];
	get_coords_amount(&var);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", 0);
	if (!mlx)
		exit(0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}