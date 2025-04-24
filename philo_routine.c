/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:33:49 by salhali           #+#    #+#             */
/*   Updated: 2025/04/24 14:17:07 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    // if (philo->id % 2 == 0) // Even IDs wait to avoid deadlock
    //     precise_sleep(10);
    while (1)
    {
        pthread_mutex_lock(&philo->data->death_mutex);
        if (philo->data->someone_died ||
            (philo->data->meals_required > 0 &&
             philo->meals_eaten >= philo->data->meals_required))
        {
            pthread_mutex_unlock(&philo->data->death_mutex);
            break;
        }
        pthread_mutex_unlock(&philo->data->death_mutex);
        print_state(philo, "is thinking");
        pthread_mutex_lock(philo->left_fork);
        print_state(philo, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
        print_state(philo, "has taken a fork");
        print_state(philo, "is eating");
        philo->last_meal = get_time();
        philo->meals_eaten++;
        // precise_sleep(philo->data->time_to_eat);
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        print_state(philo, "is sleeping");
        // precise_sleep(philo->data->time_to_sleep);
    }
    return (NULL);
}
