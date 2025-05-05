/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:16:01 by salhali           #+#    #+#             */
/*   Updated: 2025/05/05 12:41:41 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	monitor_thread;
	int			i;

	if (argc != 5 && argc != 6)
		return (printf("Salaheddine : Incorrect number of arguments !"),
			SUCCESS);
	if (parse_args(argc, argv, &data))
		return (printf("[ Your input Not valid ! ]\n"), FAILURE);
	if (init_data(&data))
		return (printf("Initialization failed ! \n"), FAILURE);
	i = 0;
	while (i < data.num_philos)
	{
		pthread_create(&data.philos[i].thread, NULL, philo_routine,
			&data.philos[i]);
		i++;
	}
	pthread_create(&monitor_thread, NULL, (void *)monitor, &data);
	i = 0;
	while (i < data.num_philos)
		pthread_join(data.philos[i++].thread, NULL);
	pthread_join(monitor_thread, NULL);
	cleanup(&data);
	return (SUCCESS);
}
