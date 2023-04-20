/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:17:54 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/20 11:18:20 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/// @brief init_variables function just set everything in the var struct to 0
/// and then it set some value with the argv
/// @param argv the main argv
/// @param var fdf main struct
void	init_variables(char **argv, t_fdf *var)
{
	ft_bzero(var, sizeof(t_fdf));
	var->file = argv[1];
	convert_map(var);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fdf *var;

	var = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
}

void	print_points(t_fdf *var)
{
	int	i;
	int	x;
	int	y;
	
	i = 0;
	while (i < var->total_coord)
	{
		x =
		y =
		mlx_put_pixel(var->img, var->coords[i].x + 100, var->coords[i].z + 100, 0xFFFFFFFF);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_fdf var;
	
	if (args_error(argc, argv))
		return (0);
	init_variables(argv, &var);
	parse_map(&var);
	init_coords(&var);
	var.mlx = mlx_init(WIDTH, HEIGHT, "fdf", 0);
	if (var.mlx == NULL)
		ft_exit("MLX_INIT\n", &var, 0);
	set_backgroud(&var);
	print_points(&var);
	mlx_key_hook(var.mlx, my_keyhook, &var);
	mlx_loop(var.mlx);
	mlx_terminate(var.mlx);
}