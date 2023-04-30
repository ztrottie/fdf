/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:53:39 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/30 17:01:55 by ztrottie         ###   ########.fr       */
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
	int	r;
	int	b;
	int	g;
	int	diff_bot;
	int	diff_top;

	diff_top = 0;
	diff_bot = 0;
	if (var->z_min != 0)
		diff_bot = 255 / -var->z_min;
	if (var->z_max != 0)
		diff_top = 255 / var->z_max;
	b = z * diff_top;
	r = -z * diff_bot;
	g = 255 - (b + r);
	return (get_rgba(r, g, b, 255));
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
