/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:41:34 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/11 14:12:21 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

/// @brief init_variables function just set everything in the var struct to 0
/// and then it set some value with the argv
/// @param argv the main argv
/// @param var fdf main struct
static void	init_variables(char **argv, t_fdf *var)
{
	ft_bzero(var, sizeof(t_fdf));
	var->file = argv[1];
	var->scale = 1;
	var->x_deg = 35;
	var->z_deg = 45;
	var->speed = 1;
	convert_map(var);
}

int	main(int argc, char **argv)
{
	t_fdf	var;
	int		scale;

	if (args_error(argc, argv))
		return (0);
	init_variables(argv, &var);
	parse_map(&var);
	scale = (WIDTH / var.map_width) / 2;
	init_coords(&var, scale);
	var.mlx = mlx_init(WIDTH, HEIGHT, "fdf", 0);
	if (var.mlx == NULL)
		ft_exit("MLX_INIT\n", &var, 0);
	print_points(&var);
	mlx_key_hook(var.mlx, my_keyhook, &var);
	mlx_scroll_hook(var.mlx, my_scrollhook, &var);
	mlx_loop(var.mlx);
	free_all(&var);
	mlx_terminate(var.mlx);
}
