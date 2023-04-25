/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:05:23 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/25 12:55:41 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/// @brief ft_exit is the function that exit safely and without leaks 
/// the program anywhere in case of an error
/// @param error the reason of the error
/// @param var fdf main struct to be properly freed
void	ft_exit(char *error, t_fdf *var, int type)
{
	if (var->mlx)
		mlx_close_window(var->mlx);
	if (type == 1)
	{
		perror(error);
		exit(errno);
	}
	ft_putstr_fd(error, 2);
	exit(0);
}
