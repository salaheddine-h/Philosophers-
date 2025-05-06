/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:31:34 by salhali           #+#    #+#             */
/*   Updated: 2025/05/06 12:53:37 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args_validity(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_valid_number(argv[i]) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	convert_args_to_data(int argc, char **argv, t_data *data)
{
	long	tmp;

	if (ft_atoi_safe(argv[1], &tmp) == FAILURE || tmp <= 0)
		return (FAILURE);
	data->num_philos = tmp;
	if (ft_atoi_safe(argv[2], &tmp) == FAILURE || tmp < 0)
		return (FAILURE);
	data->time_to_die = tmp;
	if (ft_atoi_safe(argv[3], &tmp) == FAILURE || tmp < 0)
		return (FAILURE);
	data->time_to_eat = tmp;
	if (ft_atoi_safe(argv[4], &tmp) == FAILURE || tmp < 0)
		return (FAILURE);
	data->time_to_sleep = tmp;
	data->meals_required = -1;
	if (argc == 6)
	{
		if (ft_atoi_safe(argv[5], &tmp) == FAILURE || tmp <= 0)
			return (FAILURE);
		data->meals_required = tmp;
	}
	return (SUCCESS);
}

int	parse_args(int argc, char **argv, t_data *data)
{
	if (check_args_validity(argc, argv) == FAILURE)
		return (FAILURE);
	if (convert_args_to_data(argc, argv, data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
