/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:01:18 by salhali           #+#    #+#             */
/*   Updated: 2025/04/21 13:25:37 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_valid_number(const char *str)
{
	int i = 0;

	if (!str || str[0] == '\0')
		return (SUCCESS);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}
void print_data(t_data *data)
{
    printf(RED "Spam : Run Function Print_data\n\n" RESET_COLOR);
    printf(GREEN_TXT "Philos: %d\n" RESET_COLOR, data->num_philos);
    printf(GREEN_TXT  "Die:    %ld\n" RESET_COLOR, data->time_to_die);
    printf(GREEN_TXT "Eat:    %ld\n" RESET_COLOR, data->time_to_eat);
    printf(GREEN_TXT  "Sleep:  %ld\n" RESET_COLOR, data->time_to_sleep);
    printf(GREEN_TXT "Meals:  %d\n\n" RESET_COLOR, data->meals_required);
    printf(RED "Spam : Close Function Print_data\n" RESET_COLOR);
}

int	ft_atoi_safe(const char *str, long *out)
{
	int		i = 0;
	long	result = 0;

	if (!str || str[0] == '\0')
		return (SUCCESS);
	// if(str[i] == '+')
	// 	i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (SUCCESS);
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647)
			return (SUCCESS);
		i++;
	}
	*out = result;
	return (FAILURE);
}
