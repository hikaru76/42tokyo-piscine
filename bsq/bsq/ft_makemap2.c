/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makemap2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:25:58 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/10 15:41:52 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	init(t_map *t)
{
	g_x = 0;
	g_y = 0;
	t->elems[0] = ' ';
	t->elems[1] = ' ';
	t->elems[2] = ' ';
	t->ans = 0;
	t->ans_x = 0;
	t->ans_y = 0;
}

int		write_error(void)
{
	write(2, "map error\n", 10);
	return (0);
}

int		input_map(char *filename, char buf[100000])
{
	int fd;
	int txt;

	g_x = 0;
	g_y = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (write_error());
	txt = read(fd, buf, 100000);
	buf[txt] = '\0';
	return (1);
}

void	std_input_map(char buf[100000])
{
	int		i;
	int		txt;
	char	tmpbuf[10000];

	txt = 0;
	while ((i = read(0, tmpbuf, 10000)))
	{
		txt += i;
		ft_strncat(buf, tmpbuf, i);
	}
	buf[txt] = '\0';
}

int		chars_check(char buf[100000], int cf)
{
	if (!(ft_char_is_printable(buf[cf - 1]) &&
		ft_char_is_printable(buf[cf - 2]) &&
		ft_char_is_printable(buf[cf - 3])))
		return (1);
	if (!(buf[cf - 1] != buf[cf - 2] && buf[cf - 2] != buf[cf - 3] &&
			buf[cf - 3] != buf[cf - 1]))
		return (1);
	cf -= 3;
	while (--cf >= 0)
		if (!ft_char_is_numeric(buf[cf]))
			return (1);
	return (0);
}
