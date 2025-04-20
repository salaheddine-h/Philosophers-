/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:16:01 by salhali           #+#    #+#             */
/*   Updated: 2025/04/20 16:45:14 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data data;
	pthread_t monitor_thread;
	int i;

    // if (argc != 5 && argc != 6) // ndarbo liya chi clr hmaar aykon hssn (ERROR)
	// 	return (printf("\033[1;37;41mIncorrect number of arguments ! [ You need just 5 arguments ]\n\033[0m") , SUCCESS);
	ft_memset(&data, 0, sizeof(t_data));
	if (parse_args(argc, argv, &data))
	{
		printf("[ Your input Not valid ! ]\n");
		return (FAILURE);
	}
	if (init_data(&data))
	{
		printf("Initialization failed\n");
		return (FAILURE);
	}
	print_data(&data);
	// i = 0;
	// while (i < data.num_philos)
	// 	pthread_create(&data.philos[i++].thread, NULL, philo_routine, &data.philos[i]);
	// pthread_create(&monitor_thread, NULL, (void *)monitor, &data);
	// i = 0;
	// while (i < data.num_philos)
	// 	pthread_join(data.philos[i++].thread, NULL);
	// pthread_join(monitor_thread, NULL);
	cleanup(&data);
	return (SUCCESS);
}

// ./philo 5 800 200 200 7

// 5 philosophers
// Philosophers die if they don't eat for 800ms
// Each philosopher takes 200ms to eat
// Each philosopher sleeps for 200ms after eating
// The simulation continues until a philosopher dies