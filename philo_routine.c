/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:33:49 by salhali           #+#    #+#             */
/*   Updated: 2025/05/16 18:42:54 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_sleeping(t_philo *philo)
{
	print_state(philo, "is eating");
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->death_mutex);
	precise_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_state(philo, "is sleeping");
	precise_sleep(philo->data->time_to_sleep);
}

void	take_forks(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
    	pthread_mutex_lock(philo->right_fork);
    	print_state(philo, "has taken a fork");
    	pthread_mutex_lock(philo->left_fork);
    	print_state(philo, "has taken a fork");
    }
    else
	{
    	pthread_mutex_lock(philo->left_fork);
    	print_state(philo, "has taken a fork");
    	pthread_mutex_lock(philo->right_fork);
    	print_state(philo, "has taken a fork");
    }
}

void	thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
}

int	check_death_or_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->someone_died || (philo->data->meals_required > 0
			&& philo->meals_eaten >= philo->data->meals_required))
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (FAILURE);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (SUCCESS);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->death_mutex);
	if (philo->id % 2 == 0)
		precise_sleep(10);
	if (philo->data->num_philos == 1)
	{
    	print_state(philo, "has taken a fork");
		precise_sleep(philo->data->time_to_die); // 120 just test
		return NULL;
	}
	while (1)
	{
		if (check_death_or_meal(philo))
			break ;
		take_forks(philo);
		eat_sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
