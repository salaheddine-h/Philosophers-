/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salhali <salhali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:01:18 by salhali           #+#    #+#             */
/*   Updated: 2025/05/13 15:06:24 by salhali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (FAILURE);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

// void	print_data(t_data *data)
// {
// 	printf(RED "Spam  : Run Function Print_data\n\n" RESET_COLOR);
// 	printf(GREEN_TXT "Philos: %d\n" RESET_COLOR, data->num_philos);
// 	printf(GREEN_TXT "Die:    %ld\n" RESET_COLOR, data->time_to_die);
// 	printf(GREEN_TXT "Eat:    %ld\n" RESET_COLOR, data->time_to_eat);
// 	printf(GREEN_TXT "Sleep:  %ld\n\n" RESET_COLOR, data->time_to_sleep);
// 	if (data->meals_required != -1)
// 		printf(GREEN_TXT "Meals:  %d\n\n" RESET_COLOR, data->meals_required);
// 	printf(RED "Spam : Close Function Print_data\n" RESET_COLOR);
// }

int	ft_atoi_safe(const char *str, long *out)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (!str || str[0] == '\0')
		return (FAILURE);
	if (str[i] == '+')
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

int	ft_strcmp(const char *dest, const char *src)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (src[i] != '\0' && dest[i] != '\0')
	{
		if (src[i] != dest[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (ptr1[i] - ptr2[i]);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
