/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:31:34 by salhali           #+#    #+#             */
/*   Updated: 2025/04/16 11:31:49 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int parse_args(int argc, char **argv, t_data *data)
{
    if (argc < 5 || argc > 6)
        return (1);
    data->num_philos = atoi(argv[1]);
    data->time_to_die = atol(argv[2]);
    data->time_to_eat = atol(argv[3]);
    data->time_to_sleep = atol(argv[4]);
    data->meals_required = (argc == 6) ? atoi(argv[5]) : -1;
    if (data->num_philos < 1 || data->time_to_die < 0 ||
        data->time_to_eat < 0 || data->time_to_sleep < 0 ||
        (argc == 6 && data->meals_required <= 0))
        return (1);
    return (0);
}