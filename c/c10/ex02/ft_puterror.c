/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:17:55 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/09 21:17:57 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libgen.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	print_error(char *msg, char *file_path, char *fn)
{
	ft_putstr(basename(fn));
	ft_putstr(": ");
	ft_putstr(file_path);
	ft_putstr(": ");
	ft_putstr(msg);
	ft_putstr("\n");
}

void	print_prefix(int *first, char *file_path)
{
	if (first != 0)
	{
		if (*first == 0)
			ft_putstr("\n");
		ft_putstr("==> ");
		ft_putstr(file_path);
		ft_putstr(" <==\n");
	}
}
