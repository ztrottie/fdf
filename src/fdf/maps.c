/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:38:11 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/15 15:24:39 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	open_map(char *map)
{
	int 	fd;
	char	*tmp;
	
	if (!map)
		return (-1);
	tmp = ft_strjoin("maps/", map);
	fd = open(tmp, O_RDWR);
	ft_free(tmp);
	if (fd < 0)
	{
		perror(map);
		exit(errno);
	}
	return (fd);
}

int	get_coords_amount(t_fdf *var)
{
	int		fd;
	int		len;
	char	*str;

	fd = open_map(var->map);
	str = get_next_line(fd);
	len = 0;
	while (str != NULL)
	{
		len += (ft_word_count(str, ' ') - 1);
		ft_printf("%d\n", ft_word_count(str, ' ') - 1);
		str = get_next_line(fd);
	}
	close(fd);
	ft_printf("%d\n", len);
	return (len);
}

void	get_coords(t_fdf *var)
{
	var->coords = ft_calloc(get_coords_amount(var), sizeof(int *));
	
}