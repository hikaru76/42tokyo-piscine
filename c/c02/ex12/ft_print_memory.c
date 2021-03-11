/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 11:54:46 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/04 18:38:22 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

void			ft_print_nbr(uintmax_t n)
{
	char	buf[17];
	char	*p;
	int		i;

	p = buf;
	i = -1;
	*p++ = '\0';
	while (1)
	{
		*p = "0123456789abcdef"[(n % 16)];
		n /= 16;
		if (!n)
			break ;
		p++;
	}
	if (!*(p - 1))
		*++p = '0';
	if (*(p - 2))
		while (++i < 7)
			*++p = '0';
	while (*p)
		write(1, p--, 1);
}

int				call_write(unsigned char *s1)
{
	ft_print_nbr((uintmax_t)s1);
	write(1, ": ", 2);
	return (-1);
}

unsigned char	*write_right(unsigned char *s2)
{
	if (' ' <= *s2 && *s2 <= '~')
		write(1, s2, 1);
	else
		write(1, ".", 1);
	return (++s2);
}

void			*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				i;

	size = 0;
	if (!addr)
		return (NULL);
	s1 = (unsigned char *)addr;
	s2 = s1;
	while (*s1)
	{
		i = call_write(s1);
		while (++i < 16)
		{
			*s1 ? ft_print_nbr(*s1++) : write(1, "  ", 2);
			if (i % 2)
				write(1, " ", 1);
		}
		while (--i > -1)
			if (*s2)
				s2 = write_right(s2);
		write(1, "\n", 1);
	}
	return (addr);
}
