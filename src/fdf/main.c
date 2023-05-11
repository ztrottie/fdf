/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:17:54 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/11 13:19:40 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf/fdf.h"

/// @brief init_variables function just set everything in the var struct to 0
/// and then it set some value with the argv
/// @param argv the main argv
/// @param var fdf main struct
static void	init_variables(char **argv, t_fdf *var)
{
	ft_bzero(var, sizeof(t_fdf));
	var->file = argv[1];
	convert_map(var);
}

static void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*var;
	int		speed;

	var = param;
	speed = 5;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit("fdf closed\n", var, 0);
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
	mlx_loop(var.mlx);
	free_all(&var);
	mlx_terminate(var.mlx);
}
