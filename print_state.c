/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:53:25 by salhali           #+#    #+#             */
/*   Updated: 2025/05/12 16:48:29 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	print_state(t_philo *philo, char *state)
// {
// 	pthread_mutex_lock(&philo->data->print_mutex);
// 	pthread_mutex_lock(&philo->data->death_mutex);
// 	if (!philo->data->someone_died)
// 		printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id,
// 			state);
// 	pthread_mutex_unlock(&philo->data->print_mutex);
// 	pthread_mutex_unlock(&philo->data->death_mutex);

// }
void	print_state(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->data->death_mutex);
	if (!philo->data->someone_died || strcmp(state, "died") == 0)
		printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id, state);
	pthread_mutex_unlock(&philo->data->death_mutex);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
