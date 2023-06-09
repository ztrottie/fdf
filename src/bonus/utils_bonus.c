/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:53:39 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/02 14:05:12 by ztrottie         ###   ########.fr       */
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
