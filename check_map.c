/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thilefeb <thilefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:09:55 by thilefeb          #+#    #+#             */
/*   Updated: 2024/05/02 01:48:42 by thilefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_1(struct s_mlx_var *s_mlx_var)
{
	if (!(no_foreign_car_in_map(s_mlx_var)))
	{
		ft_printf("Error\n: Map can only contain these different caracters:\
				   0, 1, C, E, P\n");
		return (0);
	}
	if (!(check_at_least_one_car(s_mlx_var, 'E') == 1))
	{
		ft_printf("Error\n: Exit position.\n");
		return (0);
	}
	if (!(check_at_least_one_car(s_mlx_var, 'C') >= 1))
	{
		ft_printf("Error\n: No item found.\n");
		return (0);
	}
	return (1);
}

int	check_map_2(struct s_mlx_var *s_mlx_var)
{
	if (!(check_at_least_one_car(s_mlx_var, 'P') == 1))
	{
		ft_printf("Error\n: Player position.\n");
		return (0);
	}
	if (!rectangular_shape(s_mlx_var))
	{
		ft_printf("Error\n: Map is not rectangular.\n");
		return (0);
	}
	if (!is_closed_by_walls(s_mlx_var))
	{
		ft_printf("Error\nMap is not closed by walls.\n");
		return (0);
	}
	if (!can_reach_exit(s_mlx_var))
	{
		ft_printf("Error\nNo valid path.\n");
		return (0);
	}
	return (1);
}
