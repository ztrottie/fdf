/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:42:49 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/01 16:35:12 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# define HEIGHT 720
# define WIDTH 1280

# include "../../lib/libft/libft.h"
# include "../../lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>

typedef struct s_map
{
	char			**line;
	struct s_map	*next;
}	t_map;

typedef struct s_lines
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	z1;
	int	z2;
}	t_lines;

typedef struct s_draw
{
	int	dx;
	int	dy;
	int	yi;
	int	xi;
	int	p;
	int	x;
	int	y;
}	t_draw;

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
	struct s_map		*map;
	struct s_coords		*coords;
	struct s_coords		*points;
	int					total_coord;
	int					map_height;
	int					map_width;
	int					trans_speed;
	int					rotation_speed;
	int					proj_selec;
	int					z_min;
	int					z_max;
	int					x_trans;
	int					y_trans;
	int					z_deg;
	int					x_deg;
	int					y_deg;
	float				scale;
}	t_fdf;

int			args_error(int argc, char **argv);
void		ft_exit(char *error, t_fdf *var, int type);
void		set_backgroud(t_fdf *var);
char		**split_get_next_line(int fd, char split);
size_t		ft_strlen_double(char **str);
void		parse_map(t_fdf	*var);
void		init_coords(t_fdf *var);
void		convert_map(t_fdf *var);
void		print_points(t_fdf *var);
void		print_lines(t_fdf *var);
t_draw		p_calculus_low(t_draw draw);
t_draw		p_calculus_high(t_draw draw);
void		free_all(t_fdf *var);
t_coords	matrice_calculus(t_coords coords, t_fdf *var);
void 		my_scrollhook(double xdelta, double ydelta, void* param);
void		my_keyhook(mlx_key_data_t keydata, void *param);
int 		get_rgba(int r, int g, int b, int a);
int			get_color(int z, t_fdf *var);

#endif