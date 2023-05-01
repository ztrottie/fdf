/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:53:39 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/01 12:53:42 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

/// @brief split_get_next_line return the split of the get_next_line return
/// with the split given in args
/// @param fd the file descriptor to read in 
/// @param split the char to split on
/// @return the splitted array
char	**split_get_next_line(int fd, char split)
{
	char	*tmp;
	char	**array;

	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	array = ft_split(tmp, split);
	ft_free(tmp);
	return (array);
}

/// @brief ft_strlen_double is like ft_strlen but for double pointers
/// @param str double pointer string
/// @return return the len of the double pointer
size_t	ft_strlen_double(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
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
