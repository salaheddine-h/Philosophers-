/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:54:17 by salhali           #+#    #+#             */
/*   Updated: 2025/04/16 13:54:32 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void cleanup(t_data *data)
{
    int i;
    for (i = 0; i < data->num_philos; i++)
        pthread_mutex_destroy(&data->forks[i]);
    pthread_mutex_destroy(&data->print_mutex);
    pthread_mutex_destroy(&data->death_mutex);
    free(data->philos);
    free(data->forks);
}
