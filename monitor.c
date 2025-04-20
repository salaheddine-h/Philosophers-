/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:53:50 by salhali           #+#    #+#             */
/*   Updated: 2025/04/20 19:06:25 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void monitor(t_data *data)
{
    int i;
    while (1)
    {
        for (i = 0; i < data->num_philos; i++)
        {
            pthread_mutex_lock(&data->death_mutex);
            if (get_time() - data->philos[i].last_meal >
                data->time_to_die)
            {
                data->someone_died = 1;
                pthread_mutex_unlock(&data->death_mutex);
                print_state(&data->philos[i], "died");
                return;
            }
            pthread_mutex_unlock(&data->death_mutex);
        }
        if (data->meals_required > 0)
        {
            int all_ate = 1;
            for (i = 0; i < data->num_philos; i++)
            {
                if (data->philos[i].meals_eaten < data->meals_required)
                {
                    all_ate = 0;
                    break;
                }
            }
            if (all_ate)
            {
                pthread_mutex_lock(&data->death_mutex);
                data->someone_died = 1;
                pthread_mutex_unlock(&data->death_mutex);
                return;
            }
        }
        usleep(1000);
    }
}
