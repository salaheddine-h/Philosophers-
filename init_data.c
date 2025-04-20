/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:32:09 by salhali           #+#    #+#             */
/*   Updated: 2025/04/20 19:00:09 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_data(t_data *data)
{
    int i;
    
    data->philos = malloc(sizeof(t_philo) * data->num_philos);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
    if (!data->philos || !data->forks)
        return (FAILURE);
    pthread_mutex_init(&data->print_mutex, NULL);
    pthread_mutex_init(&data->death_mutex, NULL);
    
    data->someone_died = 0;
    i = 0;
    while (i < data->num_philos)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        data->philos[i].id = i + 1;
        data->philos[i].left_fork = &data->forks[i];
        data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philos];
        data->philos[i].last_meal = 0;
        data->philos[i].meals_eaten = 0;
        data->philos[i].data = data;
        i++;
    }
    data->start_time = get_time();
    // printf("%ld\n",data->start_time);
    return (SUCCESS);
}
