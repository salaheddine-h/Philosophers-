/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:01:18 by salhali           #+#    #+#             */
/*   Updated: 2025/04/19 12:07:49 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_valid_number(const char *str)
{
	int i = 0;

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
void print_data(t_data *data)
{
    printf("Spam : Run Function Print_data\n");
	printf("Philos: %d\n", data->num_philos);
	printf("Die: %ld\n", data->time_to_die);
	printf("Eat: %ld\n", data->time_to_eat);
	printf("Sleep: %ld\n", data->time_to_sleep);
	printf("Meals: %d\n", data->meals_required);
}