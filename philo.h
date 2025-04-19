/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:20:29 by salhali           #+#    #+#             */
/*   Updated: 2025/04/19 22:04:02 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#define SUCCESS 0
#define FAILURE 1


// Setup colors

#define RED_BG_WHITE_TXT "\033[1;37;41m"
#define GREEN_TXT "\033[1;32m"
#define RESET_COLOR "\033[0m"


#include "./libft/libft.h" // library ibft all my function
#include <pthread.h> // For thread management
#include <stdio.h> // For standard input/output
#include <stdlib.h> // memory allocation
#include <sys/time.h> // For timing functions
#include <unistd.h> // For POSIX operating system API access
#include <limits.h> // for INT_MAX / INT_MIN


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

//----------------------Parsing-------------------------------//
int	check_args_validity(int argc, char **argv);
int	convert_args_to_data(int argc, char **argv, t_data *data);
int	parse_args(int argc, char **argv, t_data *data);
int	is_valid_number(const char *str);
//-----------------Spam_data-----------------//
void print_data(t_data *data);
void print_state(t_philo *philo, char *state);
//----------------cleanup----------------//
void cleanup(t_data *data);
//----------------------------------------//
int init_data(t_data *data);
void *philo_routine(void *arg);
void monitor(t_data *data);
long get_time(void);
int	ft_atoi_safe(const char *str, long *out);

#endif
