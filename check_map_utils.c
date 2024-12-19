/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thilefeb <thilefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:48:06 by thilefeb          #+#    #+#             */
/*   Updated: 2024/05/02 02:06:09 by thilefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_at_least_one_car(struct s_mlx_var *s_mlx_var, char car)
{
	size_t	i;
	size_t	y;
	size_t	count;

	i = 0;
	y = 0;
	count = 0;
	while (s_mlx_var->map_content_copy[i])
	{
		while (s_mlx_var->map_content_copy[i][y])
		{
			if (s_mlx_var->map_content_copy[i][y] == car)
			{
				count++;
			}
			y++;
		}
		y = 0;
		i++;
	}
	return (count);
}

int	rectangular_shape(struct s_mlx_var *s_mlx_var)
{
	int	i;

	s_mlx_var->num_rows = 0;
	s_mlx_var->num_cols = 0;
	i = 0;
	if (s_mlx_var->map_content != NULL)
	{
		while (s_mlx_var->map_content[s_mlx_var->num_rows] != NULL)
			s_mlx_var->num_rows++;
		s_mlx_var->num_cols = ft_strlen(s_mlx_var->map_content[0]);
		while (i < s_mlx_var->num_rows)
		{
			if ((int)ft_strlen(s_mlx_var->map_content[i]) \
			!= s_mlx_var->num_cols)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	is_closed_by_walls(struct s_mlx_var *s_mlx_var)
{
	int		j;

	j = 0;
	while (j < s_mlx_var->num_cols)
	{
		if ((s_mlx_var->map_content[0][j] != '1') \
		|| (s_mlx_var->map_content[s_mlx_var->num_rows - 1][j] != '1'))
			return (0);
		j++;
	}
	j = 0;
	while (j < s_mlx_var->num_rows)
	{
		if ((s_mlx_var->map_content[j][0] != '1') \
		|| ((s_mlx_var->map_content[j][s_mlx_var->num_cols - 1] != '1')))
			return (0);
		j++;
	}
	return (1);
}

int	no_foreign_car_in_map(struct s_mlx_var *s_mlx_var)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (s_mlx_var->map_content[i])
	{
		while (s_mlx_var->map_content[i][y])
		{
			if (!(ft_strchr("0C1EP", s_mlx_var->map_content[i][y])))
				return (0);
			y++;
		}
		y = 0;
		i++;
	}
	return (1);
}
