/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:29:08 by mnohara           #+#    #+#             */
/*   Updated: 2021/03/09 21:14:33 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#include "ft_tail.h"

int		count_file(char *file_path)
{
	char	buf;
	int		cnt;
	int		fd;

	cnt = 0;
	fd = open(file_path, O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, &buf, 1) > 0)
			cnt++;
	}
	return (cnt);
}

void	tail_from_file(char *file_path, int out_cnt, char *exec, int *first)
{
	int		fd;
	int		cnt;
	char	buf;

	errno = 0;
	cnt = count_file(file_path);
	if (errno != 0)
		print_error(strerror(errno), file_path, exec);
	else
	{
		print_prefix(first, file_path);
		if (first != 0)
			*first = 0;
		fd = open(file_path, O_RDONLY);
		while (cnt > out_cnt && read(fd, &buf, 1) > 0)
			cnt--;
		while (read(fd, &buf, 1))
			write(1, &buf, 1);
		close(fd);
	}
}

void	tail_from_stdin(int output_cnt)
{
	int		cnt;
	char	buf;
	char	bufs[1000000];
	int		i;

	cnt = 0;
	while (read(0, &buf, 1))
		bufs[cnt++] = buf;
	i = (cnt - output_cnt >= 0) ? cnt - output_cnt : 0;
	while (i < cnt)
	{
		write(1, &bufs[i], 1);
		i++;
	}
}

int		ft_atoi(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret);
}

int		main(int argc, char **argv)
{
	int i;
	int cnt;
	int first;

	cnt = 10;
	first = 1;
	if (argc < 3)
		return (0);
	cnt = ft_atoi(argv[2]);
	if (argc == 4)
		tail_from_file(argv[argc - 1], cnt, argv[0], 0);
	else if (argc == 3)
		tail_from_stdin(cnt);
	else
	{
		i = 2;
		while (++i < argc)
		{
			tail_from_file(argv[i], cnt, argv[0], &first);
		}
	}
}
