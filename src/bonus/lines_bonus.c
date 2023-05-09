/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:53:27 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/03 14:05:02 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

static t_lines	swap_lines(t_lines lines)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = lines.x1;
	tmp_y = lines.y1;
	lines.x1 = lines.x2;
	lines.y1 = lines.y2;
	lines.x2 = tmp_x;
	lines.y2 = tmp_y;
	return (lines);
}

static void	draw_line_low(t_fdf *var, t_lines lines)
{
	t_draw	draw;

	draw.dy = lines.y2 - lines.y1;
	draw.dx = lines.x2 - lines.x1;
	draw.yi = 1;
	if (draw.dy < 0)
	{
		draw.yi = -1;
		draw.dy = -draw.dy;
	}
	draw.p = (2 * draw.dy) - draw.dx;
	draw.y = lines.y1;
	while (lines.x1++ < lines.x2)
	{
		if (lines.x1 < WIDTH && draw.y < HEIGHT \
		&& lines.x1 >= 0 && draw.y >= 0)
			mlx_put_pixel(var->img, lines.x1, draw.y, lines.color);
		draw = p_calculus_low(draw);
	}
}

static void	draw_line_high(t_fdf *var, t_lines lines)
{
	t_draw	draw;

	draw.dy = lines.y2 - lines.y1;
	draw.dx = lines.x2 - lines.x1;
	draw.xi = 1;
	if (draw.dx < 0)
	{
		draw.xi = -1;
		draw.dx = -draw.dx;
	}
	draw.p = (2 * draw.dx) - draw.dy;
	draw.x = lines.x1;
	while (lines.y1++ < lines.y2)
	{
		if (draw.x < WIDTH && lines.y1 < HEIGHT \
		&& draw.x >= 0 && lines.y1 >= 0)
			mlx_put_pixel(var->img, draw.x, lines.y1, lines.color);
		draw = p_calculus_high(draw);
	}
}

void	draw_line(t_fdf *var, t_lines lines)
{
	if (abs(lines.y2 - lines.y1) < abs(lines.x2 - lines.x1))
	{
		if (lines.x1 > lines.x2)
			draw_line_low(var, swap_lines(lines));
		else
			draw_line_low(var, lines);
	}
	else
	{
		if (lines.y1 > lines.y2)
			draw_line_high(var, swap_lines(lines));
		else
			draw_line_high(var, lines);
	}
}

void	print_lines(t_fdf *var)
{
	t_lines	lines;
	int		x;
	int		i;
	int		y;

	i = -1;
	while (i++ < var->total_coord - 1)
	{
		y = i / var->map_width;
		x = i - (y * var->map_width);
		lines.x1 = var->points[i].x;
		lines.y1 = var->points[i].y;
		lines.color = var->coords[i].color;
		if (x < var->map_width - 1)
		{
			x_lines(lines, var, i);
		}
		if (y < var->map_height - 1)
		{
			y_lines(lines, var, i);
		}
	}
}
