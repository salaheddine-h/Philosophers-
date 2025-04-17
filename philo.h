/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:20:29 by salhali           #+#    #+#             */
/*   Updated: 2025/04/17 17:42:16 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include "./libft/libft.h" // library ibft all my function
#include <pthread.h> // For thread management
#include <stdio.h> // For standard input/output
#include <stdlib.h> // memory allocation
#include <sys/time.h> // For timing functions
#include <unistd.h> // For POSIX operating system API access
#include <limits.h>

typedef struct s_philo
{
	int id; // Philosopher's identifier
	pthread_t thread; // Thread representing the philosopher
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	long last_meal;
	int meals_eaten;
	struct s_data *data;
} t_philo;

typedef struct s_data
{
	int num_philos; // 5 == argv[1]
	long time_to_die; // Maximum time a philosopher can go without eating before they die
	long time_to_eat; // time it takes for a philosopher to eat
	long time_to_sleep; // time  a philosopher spends sleeping


	int meals_required;

	t_philo *philos;
	pthread_mutex_t *forks;

	
	pthread_mutex_t print_mutex;
	pthread_mutex_t death_mutex;
	int someone_died;
	long start_time;
} t_data;

// Function prototypes

int parse_args(int argc, char **argv, t_data *data);
int init_data(t_data *data);
void *philo_routine(void *arg);
void monitor(t_data *data);
long get_time(void);
void print_state(t_philo *philo, char *state);
void cleanup(t_data *data);
int is_valid_number(char *str);

#endif
