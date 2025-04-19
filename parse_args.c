/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:31:34 by salhali           #+#    #+#             */
/*   Updated: 2025/04/19 12:02:11 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int parse_args(int argc, char **argv, t_data *data)
// {
//     // if (argc < 5 || argc > 6)
//     //     return (1);
//     if (argc != 5 && argc != 6)
//         return (1);
//     data->num_philos = ft_atoi(argv[1]);
//     data->time_to_die = ft_atoi(argv[2]);
//     data->time_to_eat = ft_atoi(argv[3]);
//     data->time_to_sleep = ft_atoi(argv[4]);
//     return (0);
// }



int	parse_args(int argc, char **argv, t_data *data)
{
    int i;

	if (argc != 5 && argc != 6)
		return (1);
    // if (argc < 5 || argc > 6)
    //     return (1);
    i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (1);
        i++;
	}
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->meals_required = -1;
	if (argc == 6)
		data->meals_required = ft_atoi(argv[5]);

	if (data->num_philos <= 0 || data->time_to_die < 0 ||
		data->time_to_eat < 0 || data->time_to_sleep < 0 ||
		(argc == 6 && data->meals_required <= 0))
		return (1);

	return (0);
}
