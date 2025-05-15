/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:53:50 by salhali           #+#    #+#             */
/*   Updated: 2025/05/15 19:02:05 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->death_mutex);
	if (get_time() - data->philos[i].last_meal > data->time_to_die)
	{
		data->someone_died = 1;
		pthread_mutex_unlock(&data->death_mutex);
		print_state(&data->philos[i], "died");
		return (FAILURE);
	}
	pthread_mutex_unlock(&data->death_mutex);
	return (SUCCESS);
}

int	check_all_ate(t_data *data)
{
	int	i;
	int	all_ate;

	all_ate = 1;
	i = 0;
	while (i < data->num_philos)
	{
		if (data->philos[i].meals_eaten < data->meals_required)
		{
			all_ate = 0;
			break ;
		}
		i++;
	}
	return (all_ate);
}

void	monitor(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->num_philos)
		{
			if (check_death(data, i))
				return ;
			i++;
		}
		if (data->meals_required > 0 && check_all_ate(data))
		{
			pthread_mutex_lock(&data->death_mutex);
			data->someone_died = 1;
			pthread_mutex_unlock(&data->death_mutex);
			return ;
		}
		usleep(1000);
	}
}
