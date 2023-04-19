/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:38:11 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/19 17:31:22 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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

/// @brief open_map is a function that add the directory maps/ in front on the 
/// args and then open it, Open function is secured.
/// @param var fdf main structure.
/// @return the fd number of the file opened or exit the program safely if 
///the map doesn't exist.
int	open_map(t_fdf *var)
{
	int 	fd;
	char	*tmp;
	
	if (!var->file)
		return (-1);
	tmp = ft_strjoin("maps/", var->file);
	fd = open(tmp, O_RDWR);
	ft_free(tmp);
	if (fd < 0)
		ft_exit(var->file, var, 0);
	return (fd);
}

/// @brief point_parse function verify every point from the line that he got
/// and check if its a int
/// @param points double pointer of points to parse
/// @param len the len of the line to parse
/// @return return 1 if the line is all integers and 0 if there is something unexepected
static int	point_parse(char **points, size_t len)
{
	size_t	i;

	i = 0;
	while(i < len - 1)
	{
		if (ft_isint(points[i]))
			return (0);
		i++;
	}
	return (1);
}

/// @brief the parse map funtion handle all the parsing of the *.fdf file passed as arguments
/// @param var fdf main structure
void	parse_map(t_fdf	*var)
{
	size_t	len;
	t_map	*ptr;

	ptr = var->map;
	len = ft_strlen_double(ptr->line);
	while (ptr != NULL)
	{
		if (len != ft_strlen_double(ptr->line))
			ft_exit("Lines should all have the amount of points\n", var, 0);
		if (point_parse(ptr->line, len) == 0)
			ft_exit("Error in the map! All points should be integers\n", var, 0);
		var->map_height++;
		ptr = ptr->next;
	}
	var->map_width = len;
	ft_printf("%d:%d\n", var->map_width, var->map_height);
}
