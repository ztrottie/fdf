/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:31:50 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/27 16:39:40 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_lines	swap_lines(t_lines lines)
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

void	draw_line_low(t_fdf *var, t_lines lines)
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
	while (lines.x1 < lines.x2)
	{
		if (lines.x1 < WIDTH && draw.y < HEIGHT \
		&& lines.x1 >= 0 && draw.y >= 0)
			mlx_put_pixel(var->img, lines.x1, draw.y, 0xFFFFFFFF);
		lines.x1++;
		draw = p_calculus_low(draw);
	}
}

void	draw_line_high(t_fdf *var, t_lines lines)
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
	while (lines.y1 < lines.y2)
	{
		if (draw.x < WIDTH && lines.y1 < HEIGHT \
		&& draw.x >= 0 && lines.y1 >= 0)
			mlx_put_pixel(var->img, draw.x, lines.y1, 0xFFFFFFFF);
		lines.y1++;
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
		if (x < var->map_width - 1)
		{
			lines.x2 = var->points[i + 1].x;
			lines.y2 = var->points[i + 1].y;
			draw_line(var, lines);
		}
		if (y < var->map_height - 1)
		{
			lines.x2 = var->points[i + var->map_width].x;
			lines.y2 = var->points[i + var->map_width].y;
			draw_line(var, lines);
		}
	}
}
