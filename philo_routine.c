/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:33:49 by salhali           #+#    #+#             */
/*   Updated: 2025/05/10 18:23:22 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	print_state(philo, "is eating");
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->death_mutex);
	philo->meals_eaten++;
	precise_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_state(philo, "is sleeping");
	precise_sleep(philo->data->time_to_sleep);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_state(philo, "has taken a fork left");
	pthread_mutex_lock(philo->right_fork);
	print_state(philo, "has taken a fork right");
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

	philo->last_meal = get_time(); // init first meal
	if (philo->id % 2 == 0)
		precise_sleep(10);
	while (1)
	{
		if (check_death_or_meal(philo))
			break ;
		thinking(philo);
		take_forks(philo);
		eat(philo);
	}
	return (NULL);
}

// void	thinking(t_philo *philo)
// {
// 	print_state(philo, "is thinking");
// }

// void	taking_forsks(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->left_fork);
// 	print_state(philo, "has taken a fork lift");
// 	pthread_mutex_lock(philo->right_fork);
// 	print_state(philo, "has taken a fork right");
// }

// void	*philo_routine(void *arg)
// {
// 	t_philo	*philo = (t_philo *)arg;

// 	// Delay bach n9lllo chances dyal deadlock
// 	if (philo->id % 2 == 0)
// 		precise_sleep(5);

// 	while (1)
// 	{
// 		// Check l death or meals finish
// 		if (check_death_or_meal(philo))
// 			break;

// 		// 🧠 Thinking
// 		print_state(philo, "is thinking");

// 		// 🍴 Taking forks (left then right)
// 		pthread_mutex_lock(philo->left_fork);
// 		print_state(philo, "has taken a fork");
// 		pthread_mutex_lock(philo->right_fork);
// 		print_state(philo, "has taken a fork");

// 		// 🍝 Eating
// 		print_state(philo, "is eating");

// 		// Lock death_mutex to update last_meal
// 		pthread_mutex_lock(&philo->data->death_mutex);
// 		philo->last_meal = get_time();
// 		pthread_mutex_unlock(&philo->data->death_mutex);

// 		philo->meals_eaten++;
// 		precise_sleep(philo->data->time_to_eat);

// 		// Release forks
// 		pthread_mutex_unlock(philo->left_fork);
// 		pthread_mutex_unlock(philo->right_fork);

// 		// 💤 Sleeping
// 		print_state(philo, "is sleeping");
// 		precise_sleep(philo->data->time_to_sleep);
// 	}
// 	return (NULL);
// }
