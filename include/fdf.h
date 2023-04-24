/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:18:01 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/24 17:13:00 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT 720
# define WIDTH 1280

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_map
{
	char			**line;
	struct	s_map	*next;
}	t_map;


typedef struct s_coords
{
	int	x;
	int	y;
	int	z;
}	t_coords;

typedef struct s_fdf
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	char				*file;
	struct	s_map		*map;
	struct	s_coords	*coords;
	int					x_mod;
	int					y_mod;
	int					total_coord;
	int					map_height;
	int					map_width;
}	t_fdf;

int		args_error(int argc, char **argv);
int		open_map(t_fdf *var);
void	ft_exit(char *error, t_fdf *var, int type);
void	set_backgroud(t_fdf *var);
char	**split_get_next_line(int fd, char split);
size_t	ft_strlen_double(char **str);
void	parse_map(t_fdf	*var);
void	init_coords(t_fdf *var);
void	add_line_end(t_fdf *var, char **line);
void	convert_map(t_fdf *var);
void	print_points(t_fdf *var);

#endif