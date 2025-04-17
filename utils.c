/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:01:18 by salhali           #+#    #+#             */
/*   Updated: 2025/04/17 12:01:28 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Function to check if string is a valid positive number
static int is_valid_number(char *str)
{
    int i;

    i = 0;
    if (!str || str[0] == '\0')
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

// Function to convert string to integer safely
static int ft_atoi(char *str)
{
    long result;
    int i;

    result = 0;
    i = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        if (result > INT_MAX)
            return (-1);
        i++;
    }
    return ((int)result);
}

// Parse command line arguments
int parse_args(int argc, char **argv, t_data *data)
{
    // Check if we have correct number of arguments
    if (argc < 5 || argc > 6)
        return (1);
    
    // Check if all arguments are valid positive numbers
    for (int i = 1; i < argc; i++)
    {
        if (!is_valid_number(argv[i]))
            return (1);
    }
    
    // Parse and store values
    data->num_philos = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    
    // Handle optional argument
    if (argc == 6)
        data->must_eat_count = ft_atoi(argv[5]);
    else
        data->must_eat_count = -1; // -1 indicates no limit
    
    // Validate values
    if (data->num_philos <= 0 || data->num_philos > 200 ||
        data->time_to_die <= 0 || data->time_to_eat <= 0 ||
        data->time_to_sleep <= 0 || 
        (argc == 6 && data->must_eat_count <= 0))
        return (1);
    
    // Initialize simulation status
    data->simulation_stop = 0;
    
    return (0);
}
