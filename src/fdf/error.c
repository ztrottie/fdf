/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 09:04:51 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/15 09:29:34 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	argv_error(char **argv)
{
	int		error;
	char	**tmp;
	char	*msg;

	tmp = ft_split(argv[1], '.');
	error = 0;
	if (ft_strncmp(tmp[1], "fdf\0", 4) != 0)
		error = 1;
	ft_x2free((void **)tmp);
	if (error == 1)
	{
		msg = ft_strjoin(argv[1], " : Invalid map should be *.fdf\n");
		ft_putstr_fd(msg, 2);
		ft_free(msg);
	}
	return (error);
}

int	args_error(int argc, char **argv)
{
	if (argc > 2)
		return (ft_putstr_fd("Too much arguments\n", 2), 1);
	if (argc < 2)
		return (ft_putstr_fd("Not enough arguments\n", 2), 1);
	if (argv_error(argv))
		return (1);
	return (0);
}
