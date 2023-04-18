/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:46:00 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/18 18:26:10 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	get_coords(t_fdf *var)
{
	int		x;
	int		z;
	int		i;
	int		fd;
	char	**str;

	fd = open_map(var);
	z = 0;
	i = 0;
	while(z < var->map_height - 1)
	{
		str = split_get_next_line(fd, ' ');
		x = 0;
		while (x < var->map_width - 1)
		{
			var->coords[i][0] = x * 15;
			var->coords[i][1] = (ft_atoi(str[x]) * 15);
			var->coords[i][2] = z * 15;
			i++;
			x++;
		}
		z++;
		ft_x2free((void **)str);
	}
	var->total_coord = i;
	close(fd);
}

void	init_coords(t_fdf *var)
{
	int	i;
	
	var->coords = ft_calloc((var->map_height * var->map_width), sizeof(int *));
	if (!var->coords)
		ft_exit("CALLOC", var, 1);
	i = 0;
	while (i < var->map_height * var->map_width)
	{
		var->coords[i] = ft_calloc(3, sizeof(int));
		i++;
	}
	get_coords(var);
}
