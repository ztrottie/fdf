/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:53:24 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/30 09:55:12 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

t_draw	p_calculus_low(t_draw draw)
{
	if (draw.p > 0)
	{
		draw.y = draw.y + draw.yi;
		draw.p = draw.p + (2 * (draw.dy - draw.dx));
	}
	else
		draw.p = draw.p + 2 * draw.dy;
	return (draw);
}

t_draw	p_calculus_high(t_draw draw)
{
	if (draw.p > 0)
	{
		draw.x = draw.x + draw.xi;
		draw.p = draw.p + (2 * (draw.dx - draw.dy));
	}
	else
			draw.p = draw.p + 2 * draw.dx;
	return (draw);
}
