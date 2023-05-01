/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:07:26 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/01 12:58:10 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

static t_coords	rotation_z(t_coords coords, t_fdf *var)
{
	t_coords	result;
	double		deg;

	deg = var->z_deg * (M_PI / 180);
	result.x = coords.x * cos(deg) + coords.y * -sin(deg);
	result.y = coords.x * sin(deg) + coords.y * cos(deg);
	result.z = coords.z;
	return (result);
}

static t_coords	rotation_x(t_coords coords, t_fdf *var)
{
	t_coords	result;
	double		deg;

	deg = var->x_deg * (M_PI / 180);
	result.x = coords.x;
	result.y = coords.y * cos(deg) + coords.z * -sin(deg);
	result.z = coords.y * sin(deg) + coords.z * cos(deg);
	return (result);
}

static t_coords	rotation_y(t_coords coords, t_fdf *var)
{
	t_coords	result;
	double		deg;

	deg = var->y_deg * (M_PI / 180);
	result.x = coords.x * cos(deg) + coords.z * sin(deg);
	result.y = coords.y;
	result.z = coords.x * -sin(deg) + coords.z * cos(deg);
	return (result);
}

static t_coords scale(t_coords coords, t_fdf *var)
{
	t_coords	result;

	result.x = coords.x * var->scale;
	result.y = coords.y * var->scale;
	result.z = coords.z * var->scale;
	return (result);
}

t_coords	matrice_calculus(t_coords coords, t_fdf *var)
{
	t_coords	result;

	result = coords;
	result = rotation_z(result, var);
	result = rotation_y(result, var);
	result = rotation_x(result, var);
	result = scale(result, var);
	result.x += var->x_trans;
	result.y += var->y_trans;
	return (result);
}