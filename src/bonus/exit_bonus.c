/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:53:18 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/03 13:10:13 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

void	free_all(t_fdf *var)
{
	t_map	*ptr;
	t_map	*tmp;

	ft_free(var->coords);
	ft_free(var->points);
	ptr = var->map;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		ft_x2free((void **)ptr->line);
		ft_free(ptr);
		ptr = tmp;
	}
}

/// @brief ft_exit is the function that exit safely and without leaks 
/// the program anywhere in case of an error
/// @param error the reason of the error
/// @param var fdf main struct to be properly freed
void	ft_exit(char *error, t_fdf *var, int type)
{
	if (var->mlx)
		mlx_terminate(var->mlx);
	if (type == 1)
	{
		free_all(var);
		perror(error);
		exit(errno);
	}
	free_all(var);
	ft_putstr_fd(error, 2);
	exit(0);
}
