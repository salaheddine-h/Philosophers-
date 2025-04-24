/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:31:34 by salhali           #+#    #+#             */
/*   Updated: 2025/04/22 11:06:44 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args_validity(int argc, char **argv)
{
	int	i;
    // if (argc != 5 && argc != 6) // ndarbo liha chi clr hmaar aykon hssn (ERROR)
	// 	return (printf("\033[1;37;41mIncorrect number of arguments ! [ You need just 5 arguments ]\n\033[0m") , SUCCESS);
	i = 1;
	while (i < argc)
	{
	    printf("argv[%d] = %s\n", i, argv[1]);
		if (is_valid_number(argv[i]) == 0)
			return (printf("spama return 1 (check_args_validity)\n"), 0);
		i++;
	}
	return (1);
}
int	convert_args_to_data(int argc, char **argv, t_data *data)
{
	long	tmp;

	// printf("argv[1] = %s\n", argv[1]);
	if (ft_atoi_safe(argv[1], &tmp) == 0 || tmp <= 0)
		return (SUCCESS);
	// printf("%ld\n", tmp);
	// printf("spaam22\n");
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
	// printf("spaam222\n");
	return (FAILURE);
}
int	parse_args(int argc, char **argv, t_data *data) // 1 
{
	// if (check_args_validity(argc, argv) == SUCCESS)
	// 	return (FAILURE);
	if (convert_args_to_data(argc, argv, data) == SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
