/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:01:18 by salhali           #+#    #+#             */
/*   Updated: 2025/04/25 21:07:35 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_valid_number(const char *str)
{
	int i = 0;

	if (!str || str[0] == '\0')
		return (FAILURE);
	// if(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	// 	return(FAILURE);
	if(str[i] == '+')
		i++;
	while (str[i])
	{
		// printf("string : %d\n", str[i]);
		if (str[i] < '0' || str[i] > '9')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
void print_data(t_data *data)
{
    printf(RED "Spam  : Run Function Print_data\n\n" RESET_COLOR);
    printf(GREEN_TXT "Philos: %d\n" RESET_COLOR, data->num_philos);
    printf(GREEN_TXT  "Die:    %ld\n" RESET_COLOR, data->time_to_die);
    printf(GREEN_TXT "Eat:    %ld\n" RESET_COLOR, data->time_to_eat);
    printf(GREEN_TXT  "Sleep:  %ld\n" RESET_COLOR, data->time_to_sleep);
    if (data->meals_required != -1)
        printf(GREEN_TXT "Meals:  %d\n\n" RESET_COLOR, data->meals_required);
    printf(RED "Spam : Close Function Print_data\n" RESET_COLOR);
}

int	ft_atoi_safe(const char *str, long *out)
{
	int		i = 0;
	long	result = 0;

	if (!str || str[0] == '\0')
		return (FAILURE);
	if(str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FAILURE);
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647)
			return (FAILURE);
		i++;
	}
	*out = result;
	return (SUCCESS);
}
