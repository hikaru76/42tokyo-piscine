/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:17:03 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/09 21:17:06 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#include "ft_hexdump.h"

void	ft_put_index(int i, int cnt, int c_flag, int last)
{
	char *base;

	base = "0123456789abcdef";
	if (cnt > 1)
		ft_put_index(i / 16, cnt - 1, c_flag, last);
	ft_putchar(base[i % 16]);
	if (cnt == 7 + c_flag && !last)
	{
		ft_putchar(' ');
		if (c_flag)
			ft_putchar(' ');
	}
}

void	ft_put_c_flag_part(char *bufs)
{
	int j;

	j = -1;
	ft_putstr("  |");
	while (++j < 16 && bufs[j])
	{
		if (!(bufs[j] >= ' ' && bufs[j] <= '~'))
			ft_putchar('.');
		else
			ft_putchar(bufs[j]);
	}
	ft_putstr("|\n");
}

void	put_last(int c_flag, char *bufs, int i)
{
	int j;

	j = i % 16;
	if (j != 0)
	{
		bufs[i % 16] = 0;
		ft_put_index(i / 16 * 16, 7 + c_flag, c_flag, 0);
		ft_put_main(bufs, c_flag, i % 16);
		while (j++ < 16)
		{
			ft_putstr("  ");
			if (c_flag && j == 8)
				ft_putstr(" ");
			if (j != 16)
				ft_putstr(" ");
		}
		if (c_flag)
			ft_put_c_flag_part(bufs);
		else
			ft_putchar('\n');
	}
	if (i == 0)
		return ;
	ft_put_index(i, 7 + c_flag, c_flag, 1);
	ft_putchar('\n');
}

int		ft_hexdump(int i, char *file_path, int c_flag, char *bufs)
{
	int		fd;
	char	buf;

	fd = (file_path == 0) ? 0 : open(file_path, O_RDONLY);
	if (fd == -1)
		return (i);
	while (read(fd, &buf, 1) > 0)
	{
		bufs[i % 16] = buf;
		if (i % 16 == 15)
		{
			ft_put_index(i - 15, 7 + c_flag, c_flag, 0);
			ft_put_main(bufs, c_flag, 16);
			if (c_flag)
				ft_put_c_flag_part(bufs);
		}
		i++;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	int		i;
	int		c_flag;
	int		cnt;
	char	bufs[16];

	c_flag = 0;
	if (argc != 1 && argv[1][0] == '-' && argv[1][1] == 'C')
		c_flag = 1;
	i = 1 + c_flag;
	cnt = 0;
	if (argc == i)
		cnt = ft_hexdump(0, 0, c_flag, bufs);
	while (i < argc)
	{
		errno = 0;
		cnt = ft_hexdump(cnt, argv[i], c_flag, bufs);
		if (errno != 0)
			print_error(strerror(errno), argv[i], argv[0]);
		i++;
	}
	put_last(c_flag, bufs, cnt);
	if (cnt == 0 && errno != 0 && errno != EISDIR)
		print_error("Bad file descriptor", argv[argc - 1], argv[0]);
}
