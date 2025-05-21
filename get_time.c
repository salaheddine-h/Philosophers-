/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:52:45 by salhali           #+#    #+#             */
/*   Updated: 2025/05/21 12:51:12 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/*void	precise_sleep(long ms)
{
	long	start;

	start = get_time();
	while (get_time() - start <= ms)
		usleep(100);
}*/

void precise_sleep(long ms)
{
	long start;
	long now;

	start = get_time();
	while (1)
	{
		now = get_time();
		if (now - start >= ms)
			break;
		usleep(1000); // sleep 1ms instead of 0.1ms
	}
}

