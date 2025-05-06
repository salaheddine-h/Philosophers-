/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:20:29 by salhali           #+#    #+#             */
/*   Updated: 2025/05/06 13:07:14 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define SUCCESS 0
# define FAILURE 1

// Setup colors
# define RED "\033[1;37;41m"
# define GREEN_TXT "\033[1;32m"
# define RESET_COLOR "\033[0m"

# include "./libft/libft.h" // library ibft all my function
# include <limits.h>        // for INT_MAX / INT_MIN
# include <pthread.h>       // For thread management
# include <stdio.h>         // For standard input/output
# include <stdlib.h>        // memory allocation
# include <sys/time.h>      // For timing functions
# include <unistd.h>        // For POSIX operating system API access

typedef struct s_philo
{
	int				id;
	pthread_t		thread; // Thread representing the philosopher
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal;
	int				meals_eaten;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				num_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				meals_required;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	int				someone_died;
	long			start_time;
}					t_data;

int					check_args_validity(int argc, char **argv);
int					convert_args_to_data(int argc, char **argv, t_data *data);
int					parse_args(int argc, char **argv, t_data *data);
int					is_valid_number(const char *str);
// void				print_data(t_data *data);
void				print_state(t_philo *philo, char *state);
void				cleanup(t_data *data);
int					init_data(t_data *data);
void				*philo_routine(void *arg);
void				monitor(t_data *data);
int					check_death(t_data *data, int i);
int					check_all_ate(t_data *data);
long				get_time(void);
int					ft_atoi_safe(const char *str, long *out);
void				precise_sleep(long ms);
int					check_death_or_meal(t_philo *philo);
void				take_forks(t_philo *philo);
void				eat(t_philo *philo);
void				sleep_and_think(t_philo *philo);

#endif
