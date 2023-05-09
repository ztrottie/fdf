/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:53:34 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/09 15:24:35 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

static void	add_line_end(t_fdf *var, char **line)
{
	t_map	*ptr;

	if (!var->map)
	{
		var->map = ft_calloc(1, sizeof(t_map));
		var->map->line = line;
	}
	else
	{
		ptr = var->map;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = ft_calloc(1, sizeof(t_map));
		ptr->next->line = line;
	}
}

/// @brief open_map is a function that add the directory maps/ in front on the 
/// args and then open it, Open function is secured.
/// @param var fdf main structure.
/// @return the fd number of the file opened or exit the program safely if 
///the map doesn't exist.
static int	open_map(t_fdf *var)
{
	int		fd;
	char	*tmp;

	if (!var->file)
		return (-1);
	tmp = ft_strjoin("maps/", var->file);
	fd = open(tmp, O_RDWR);
	ft_free(tmp);
	if (fd < 0)
		ft_exit(var->file, var, 1);
	return (fd);
}

void	convert_map(t_fdf *var)
{
	int		fd;
	char	**line;

	fd = open_map(var);
	line = split_get_next_line(fd, ' ');
	while (line != NULL)
	{
		add_line_end(var, line);
		line = split_get_next_line(fd, ' ');
	}
	close(fd);
}

/// @brief point_parse function verify every point from the line that he got
/// and check if its a int
/// @param points double pointer of points to parse
/// @param len the len of the line to parse
/// @return return 1 if the line is all integers and 0 if there
/// is something unexepected
static int	point_parse(char **points, size_t len)
{
	size_t	i;
	char	**str;

	i = 0;
	while (i < len - 1)
	{
		str = ft_split(points[i], ',');
		if (ft_isint(str[0]))
			return (ft_x2free((void **)str), 0);
		ft_x2free((void **)str);
		i++;
	}
	return (1);
}

/// @brief the parse map funtion handle all the parsing 
/// of the *.fdf file passed as arguments
/// @param var fdf main structure
void	parse_map(t_fdf	*var)
{
	size_t	len;
	t_map	*ptr;

	ptr = var->map;
	len = ft_strlen_double(ptr->line);
	while (ptr != NULL)
	{
		if (len != ft_strlen_double(ptr->line) && PARSE == 0)
			ft_exit("Lines should all have the amount of points\n", \
			var, 0);
		if (point_parse(ptr->line, len) == 0 && PARSE == 0)
			ft_exit("Error in the map! All points should \
			be integers\n", var, 0);
		var->map_height++;
		ptr = ptr->next;
	}
	var->map_width = len;
}
