/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:02:40 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 18:29:53 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

long	from_input_to_long(char *input_num)
{
	long	num;
	int		i;

	i = -1;
	num = 0;
	while (input_num[++i] != '\0')
		num = num * 10 + (long)input_num[i] - '0';
	if (num > 4294967295)
		return (-1);
	return (num);
}

int		input_num_error_check(char *input_num)
{
	long num;

	if (!ft_str_is_numeric(input_num) || ft_strlen(input_num) > 10 ||
		ft_strlen(input_num) < 1)
		return (0);
	if (ft_strlen(input_num) > 1 && input_num[0] == '0')
		return (0);
	num = (unsigned int)from_input_to_long(input_num);
	if (num == -1)
		return (0);
	g_num = (unsigned int)num;
	return (1);
}

int		get_dict(char *input_dict, char *input_num)
{
	if (!input_num_error_check(input_num))
		return (0);
	g_dict = open(input_dict, O_RDONLY);
	if (g_dict == -1)
	{
		close(g_dict);
		return (0);
	}
	g_txt = read(g_dict, g_buf, 100000);
	return (1);
}

int		write_error(void)
{
	ft_putstr("Error\n");
	return (0);
}
