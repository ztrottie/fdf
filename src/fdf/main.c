/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:17:54 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/18 14:32:23 by ztrottie         ###   ########.fr       */
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
	var->map = argv[1];
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fdf *var;

	var = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(var->mlx);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_fdf var;
	
	if (args_error(argc, argv))
		return (0);
	init_variables(argv, &var);
	parse_map(&var);
	var.mlx = mlx_init(WIDTH, HEIGHT, "fdf", 0);
	if (!var.mlx)
		ft_exit("MLX_INIT\n", &var, 0);
	set_backgroud(&var);
	mlx_key_hook(var.mlx, my_keyhook, &var);
	mlx_loop(var.mlx);
	mlx_terminate(var.mlx);
}