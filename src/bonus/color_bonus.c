/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:46:50 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/02 16:16:05 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

int	convert_hexa(char *str, t_fdf *var)
{
	
}

int	convert_color(char *str, t_fdf *var)
{
	
}

int	get_color(int z, t_fdf *var)
{
	if (z == var->z_max)
		return (get_rgba(255, 0, 0, 255));
	if (z == 0)
		return (get_rgba(0, 255, 0, 255));
	return (get_rgba(255, 255, 255, 255));
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}