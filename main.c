/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:16:01 by salhali           #+#    #+#             */
/*   Updated: 2025/04/17 12:53:48 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_data data;
    pthread_t monitor_thread;
    int i;

    // if(is_valid_number(argv) == 0)
    // {
    //     printf("Invalid arguments\n");
    //     return (1);
    // }
    // ft_memset(&data, 0, sizeof(t_data));
    printf("%d\n", data.num_philos);
    if (parse_args(argc, argv, &data))
    {
        printf("Invalid arguments77\n");
        return (1);
    }
    if (init_data(&data))
    {
        printf("Initialization failed\n");
        return (1);
    }
    i = 0;
    while(i < data.num_philos)
    {
        pthread_create(&data.philos[i].thread, NULL, philo_routine, &data.philos[i]);
    }
    pthread_create(&monitor_thread, NULL, (void *)monitor, &data);
    i = 0;
    while (i < data.num_philos)
    {
        pthread_join(data.philos[i].thread, NULL);
    }
    pthread_join(monitor_thread, NULL);
    cleanup(&data);
    return (0);
}

// ./philo 5 800 200 200

// 5 philosophers
// Philosophers die if they don't eat for 800ms
// Each philosopher takes 200ms to eat
// Each philosopher sleeps for 200ms after eating
// The simulation continues until a philosopher dies