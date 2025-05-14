/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_single.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:38:02 by salhali           #+#    #+#             */
/*   Updated: 2025/05/14 18:58:24 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philo_routine_single(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;

    pthread_mutex_lock(philo->left_fork);
    print_state(philo, "has taken a fork left");
    pthread_mutex_lock(&philo->data->death_mutex);
    print_state(philo, "died");
    pthread_mutex_unlock(&philo->data->death_mutex);
    return (NULL);
}