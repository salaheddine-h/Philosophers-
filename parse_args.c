/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:31:34 by salhali           #+#    #+#             */
/*   Updated: 2025/04/19 18:44:27 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args_validity(int argc, char **argv)
{
	int	i;

	// if (argc != 5 && argc != 6)
	// 	return (SUCCESS);
	i = 1;
	while (i < argc)
	{
		if (is_valid_number(argv[i]) == SUCCESS)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}
int	convert_args_to_data(int argc, char **argv, t_data *data)
{
	long	tmp;

	if (ft_atoi_safe(argv[1], &tmp) == SUCCESS || tmp <= 0)
		return (SUCCESS);
	data->num_philos = tmp;
	if (ft_atoi_safe(argv[2], &tmp) == SUCCESS || tmp < 0)
		return (SUCCESS);
	data->time_to_die = tmp;
	if (ft_atoi_safe(argv[3], &tmp) == SUCCESS || tmp < 0)
		return (SUCCESS);
	data->time_to_eat = tmp;
	if (ft_atoi_safe(argv[4], &tmp) == SUCCESS || tmp < 0)
		return (SUCCESS);
	data->time_to_sleep = tmp;
	data->meals_required = -1;
	if (argc == 6)
	{
		if (ft_atoi_safe(argv[5], &tmp) == SUCCESS || tmp <= 0)
			return (SUCCESS);
		data->meals_required = tmp;
	}
	return (FAILURE);
}
int	parse_args(int argc, char **argv, t_data *data)
{
	if (check_args_validity(argc, argv) == SUCCESS)
		return (FAILURE);
	if (convert_args_to_data(argc, argv, data) == SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
