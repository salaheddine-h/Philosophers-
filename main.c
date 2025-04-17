/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:16:01 by salhali           #+#    #+#             */
/*   Updated: 2025/04/17 11:57:47 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <pthread.h>
// #include <stdio.h>


// void *routine(void *arg)
// {
//     printf("Thread is running!\n");
//     return NULL;
// }

// int main() 
// {
//     pthread_t i;
//     pthread_create(&i, NULL, routine, NULL);
//     pthread_join(i, NULL);
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #include <pthread.h>

// // Global variable:
// int i = 2;

// void* foo(void* p)
// {
//   // Print value received as argument:
//   printf("Value recevied as argument in starting routine: ");
//   printf("%i\n", * (int*)p);

//   // Return reference to global variable:
//   pthread_exit(&i);
// }


// // Kol philosopher kaymchi 3la forma dyal thread f C (e.g. pthread_create()).


// int main(void)
// {
// 	int	j;
// 	pthread_t id;

//   j = 1;
//   pthread_create(&id, NULL, foo, &j);
    
//   int* ptr;

//   // Wait for foo() and retrieve value in ptr;
//   pthread_join(id, (void**)&ptr);
//   printf("Value recevied by parent from child: ");
//   printf("%i\n", *ptr);
// }

#include "philo.h"

int main(int argc, char **argv)
{
    t_data data;
    pthread_t monitor_thread;
    int i;

    if(argc != 5)
        return(0);
    if (parse_args(argc, argv, &data))
    {
        printf("Invalid arguments\n");
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