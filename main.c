/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:16:01 by salhali           #+#    #+#             */
/*   Updated: 2025/04/25 20:59:34 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data data;
	pthread_t monitor_thread;
	int i;

  if (argc != 5 && argc != 6)
		return (printf("\033[1;37;41mIncorrect number of arguments ! [ You need just 5 arguments ]\n\033[0m") , SUCCESS);
	ft_memset(&data, 0, sizeof(t_data));
	if (parse_args(argc, argv, &data))
		return (printf("[ Your input Not valid ! ]\n"),FAILURE);
	if (init_data(&data))
		return (printf("Initialization failed ! \n"), FAILURE);
	// print_data(&data);
	i = 0;
	while (i < data.num_philos)
	{
		pthread_create(&data.philos[i].thread, NULL, philo_routine, &data.philos[i]);
		i++;
	}
	pthread_create(&monitor_thread, NULL, (void *)monitor, &data);
	i = 0;
	while (i < data.num_philos)
		pthread_join(data.philos[i++].thread, NULL);
	pthread_join(monitor_thread, NULL);
	// print_data(&data);
	cleanup(&data);
	return (SUCCESS);
}

// ./philo 5 800 200 200 7

// 5 philosophers
// Philosophers die if they don't eat for 800ms
// Each philosopher takes 200ms to eat
// Each philosopher sleeps for 200ms after eating
// The simulation continues until a philosopher dies
