/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:53:24 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/03 13:38:26 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

void	x_lines(t_lines lines, t_fdf *var, int i)
{
	lines.x2 = var->points[i + 1].x;
	lines.y2 = var->points[i + 1].y;
	if (lines.color == WHITE_COLOR && var->coords[i + 1].color > lines.color)
		lines.color = var->coords[i + 1].color;
	draw_line(var, lines);
}

void	y_lines(t_lines lines, t_fdf *var, int i)
{
	lines.x2 = var->points[i + var->map_width].x;
	lines.y2 = var->points[i + var->map_width].y;
	if (lines.color == WHITE_COLOR && \
	var->coords[i + var->map_width].color > lines.color)
		lines.color = var->coords[i + var->map_width].color;
	draw_line(var, lines);
}

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
