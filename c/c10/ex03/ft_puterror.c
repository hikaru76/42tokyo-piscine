/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:16:40 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/09 21:16:46 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libgen.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	print_error(char *msg, char *file_path, char *file_name)
{
	ft_putstr(basename(file_name));
	ft_putstr(": ");
	ft_putstr(file_path);
	ft_putstr(": ");
	ft_putstr(msg);
	ft_putstr("\n");
}

void	ft_put_main(char *bufs, int c_flag, int until)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	while (i < until)
	{
		ft_putchar(base[(unsigned)bufs[i] / 16]);
		ft_putchar(base[(unsigned)bufs[i] % 16]);
		if (i % 16 == 7 && c_flag)
			ft_putchar(' ');
		if (i % 16 != 15)
			ft_putchar(' ');
		else if (!c_flag)
			ft_putchar('\n');
		i++;
	}
}
