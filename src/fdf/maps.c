/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:38:11 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/18 18:23:57 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/// @brief open_map is a function that add the directory maps/ in front on the 
/// args and then open it, Open function is secured.
/// @param var fdf main structure.
/// @return the fd number of the file opened or exit the program safely if 
///the map doesn't exist.
int	open_map(t_fdf *var)
{
	int 	fd;
	char	*tmp;
	
	if (!var->map)
		return (-1);
	tmp = ft_strjoin("maps/", var->map);
	fd = open(tmp, O_RDWR);
	ft_free(tmp);
	if (fd < 0)
		ft_exit(var->map, var, 0);
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
	int		fd;
	size_t	len;
	char	**str;

	fd = open_map(var);
	str = split_get_next_line(fd, ' ');
	len = ft_strlen_double(str);
	while (str != NULL)
	{
		if (len != ft_strlen_double(str))
		{
			ft_exit("Lines should all have the amount of points\n", var, 0);
			ft_x2free((void **)str);
		}
		if (point_parse(str, len) == 0)
		{
			ft_exit("Error in the map! All points should be integers\n", var, 0);
			ft_x2free((void **)str);
		}
		var->map_height++;
		ft_x2free((void **)str);
		str = split_get_next_line(fd, ' ');
	}
	var->map_width = len;
	close(fd);
}
