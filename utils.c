/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:01:18 by salhali           #+#    #+#             */
/*   Updated: 2025/04/19 18:27:08 by salah            ###   ########.fr       */
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
    printf("Spam : Run Function Print_data\n\n");
	printf("Philos: %d\n", data->num_philos);
	printf("Die: %ld\n", data->time_to_die);
	printf("Eat: %ld\n", data->time_to_eat);
	printf("Sleep: %ld\n", data->time_to_sleep);
	printf("Meals: %d\n\n", data->meals_required);
    printf("Spam : CLose Function Print_data\n");
}

int	ft_atoi_safe(const char *str, long *out)
{
	int		i = 0;
	long	result = 0;

	if (!str || str[0] == '\0')
		return (SUCCESS);

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

