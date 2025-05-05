/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:53:25 by salhali           #+#    #+#             */
/*   Updated: 2025/05/05 12:31:31 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->someone_died)
		printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id,
			state);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
