/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:20:29 by salhali           #+#    #+#             */
/*   Updated: 2025/05/18 12:49:27 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define SUCCESS 0
# define FAILURE 1

# include <limits.h>   // for INT_MAX / INT_MIN
# include <pthread.h>  // For thread management
# include <stdio.h>    // For standard input/output
# include <stdlib.h>   // memory allocation
# include <sys/time.h> // For timing functions
# include <unistd.h>   // For POSIX operating system API access

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				id;
	long			last_meal; // l waqt li akher mara kla fiha
	int				meals_eaten; // Ch7al mn marra kla
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				num_philos; // number dyal phhilo
	long			time_to_die;
	// W9t ila m'aklach philosopher ghatmout mn jowa
	long			time_to_eat; // Ch7al khas philosopher bash yakol
	long			time_to_sleep; // Ch7al khas yna3s philosopher ba3d l makan
	int				meals_required; // re ch7aal mn mera i3awd routine
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	// Bash y9der ghira wahed philosopher yprinti f stdout
	pthread_mutex_t	death_mutex;
	//  Bash ykon l'accès l t_philo mtznin (thread-safe).
	int				someone_died;
	long			start_time;
}					t_data;

int					check_args_validity(int argc, char **argv);
int					convert_args_to_data(int argc, char **argv, t_data *data);
int					parse_args(int argc, char **argv, t_data *data);
int					is_valid_number(const char *str);
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
void				eat_sleeping(t_philo *philo);
void				thinking(t_philo *philo);
int					ft_strcmp(const char *dest, const char *src);
void				*ft_memset(void *s, int c, size_t n);

#endif