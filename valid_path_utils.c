/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thilefeb <thilefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:58:32 by thilefeb          #+#    #+#             */
/*   Updated: 2024/05/02 02:01:15 by thilefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_car(struct s_mlx_var *s_mlx_var, char car, int num)
{
	char	**test;
	size_t	i;
	size_t	y;

	if (num == 0)
		test = s_mlx_var->map_content;
	else
		test = s_mlx_var->map_content_copy;
	i = 0;
	y = 0;
	while (test[i])
	{
		while (test[i][y])
		{
			if (test[i][y] == car)
			{
				s_mlx_var->coordinates[0] = i;
				s_mlx_var->coordinates[1] = y;
				return ;
			}
			y++;
		}
		y = 0;
		i++;
	}
}

int	car_around_coordinates(struct s_mlx_var *s_mlx_var, char car)
{
	if (s_mlx_var->map_content_copy[s_mlx_var->coordinates[0] - 1] \
		[s_mlx_var->coordinates[1]] == car)
		return (1);
	if (s_mlx_var->map_content_copy[s_mlx_var->coordinates[0] + 1] \
		[s_mlx_var->coordinates[1]] == car)
		return (1);
	if (s_mlx_var->map_content_copy[s_mlx_var->coordinates[0]] \
		[s_mlx_var->coordinates[1] - 1] == car)
		return (1);
	if (s_mlx_var->map_content_copy[s_mlx_var->coordinates[0]] \
		[s_mlx_var->coordinates[1] + 1] == car)
		return (1);
	return (0);
}

void	replace_car_around_coordinates(struct s_mlx_var *s_mlx_var)
{
	if (ft_strchr("0C", s_mlx_var->map_content_copy \
		[s_mlx_var->coordinates[0] - 1][s_mlx_var->coordinates[1]]))
		s_mlx_var->map_content_copy \
		[s_mlx_var->coordinates[0] - 1][s_mlx_var->coordinates[1]] = 'X';
	if (ft_strchr("0C", s_mlx_var->map_content_copy \
		[s_mlx_var->coordinates[0] + 1][s_mlx_var->coordinates[1]]))
		s_mlx_var->map_content_copy \
		[s_mlx_var->coordinates[0] + 1][s_mlx_var->coordinates[1]] = 'X';
	if (ft_strchr("0C", s_mlx_var->map_content_copy \
		[s_mlx_var->coordinates[0]][s_mlx_var->coordinates[1] - 1]))
		s_mlx_var->map_content_copy \
		[s_mlx_var->coordinates[0]][s_mlx_var->coordinates[1] - 1] = 'X';
	if (ft_strchr("0C", s_mlx_var->map_content_copy \
		[s_mlx_var->coordinates[0]][s_mlx_var->coordinates[1] + 1]))
		s_mlx_var->map_content_copy \
		[s_mlx_var->coordinates[0]][s_mlx_var->coordinates[1] + 1] = 'X';
}

int	replace_zero_and_c_by_x_if_around_x(struct s_mlx_var *s_mlx_var)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (s_mlx_var->map_content_copy[i])
	{
		while (s_mlx_var->map_content_copy[i][y])
		{
			if (s_mlx_var->map_content_copy[i][y] == 'X')
			{
				s_mlx_var->coordinates[0] = i;
				s_mlx_var->coordinates[1] = y;
				replace_car_around_coordinates(s_mlx_var);
			}
			y++;
		}
		y = 0;
		i++;
	}
	return (0);
}

int	should_we_continue(struct s_mlx_var *s_mlx_var)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (s_mlx_var->map_content_copy[i])
	{
		while (s_mlx_var->map_content_copy[i][y])
		{
			if (s_mlx_var->map_content_copy[i][y] == 'X')
			{
				s_mlx_var->coordinates[0] = i;
				s_mlx_var->coordinates[1] = y;
				if (car_around_coordinates(s_mlx_var, '0') || \
					car_around_coordinates(s_mlx_var, 'C'))
					return (1);
			}
			y++;
		}
		y = 0;
		i++;
	}
	return (0);
}
