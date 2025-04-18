/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:16:01 by salhali           #+#    #+#             */
/*   Updated: 2025/04/17 18:28:18 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_data data;
    // t_philo philo;
    pthread_t monitor_thread;
    int i;
    int j;

    j = 1;
    while(j < argc)
    {
        if(!is_valid_number(argv[j]))
        {
            printf("Invalid arguments (function : is_valid_number) N/23 \n");
            return (1);
        }
        j++;
    }
    ft_memset(&data, 0, sizeof(t_data));
    if (parse_args(argc, argv, &data))
    {
        printf("Invalid arguments\n");
        return (1);
    }

    ///////////////////////////////////////
    // printf("%d\n", data.num_philos);
    // printf("%ld\n", data.time_to_die);
    // printf("%ld\n", data.time_to_eat);
    // printf("%ld\n", data.time_to_sleep);
    // printf("%d\n", data.meals_required);
    ////////////////////////////////////////

    if (init_data(&data))
    {
        printf("Initialization failed\n");
        return (1);
    }
    // printf("%d\n", data.num_philos);
    // printf("%ld\n", data.time_to_die);
    // printf("%ld\n", data.time_to_eat);
    // printf("%ld\n", data.time_to_sleep);
    // printf("%d\n", data.meals_required);
    // printf("ID : %d\n", philo.id);
    // printf("last_meal : %ld\n", philo.last_meal);
    // printf("meals_eaten : %d\n", philo.meals_eaten);

    // i = 0;
    // while(i < data.num_philos)
    // {
    //     pthread_create(&data.philos[i].thread, NULL, philo_routine, &data.philos[i]);
    // }
    // pthread_create(&monitor_thread, NULL, (void *)monitor, &data);
    // i = 0;
    // while (i < data.num_philos)
    // {
    //     pthread_join(data.philos[i].thread, NULL);
    // }
    // pthread_join(monitor_thread, NULL);
    cleanup(&data);
    return (0);
}

// ./philo 5 800 200 200 7

// 5 philosophers
// Philosophers die if they don't eat for 800ms
// Each philosopher takes 200ms to eat
// Each philosopher sleeps for 200ms after eating
// The simulation continues until a philosopher dies