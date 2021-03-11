/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:47:39 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/02 13:24:34 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>

char	*g_programname;

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	write_error(int ernum, char *filename)
{
	write(2, g_programname, ft_strlen(g_programname));
	write(2, ": ", 2);
	write(2, filename, ft_strlen(filename));
	if (ernum == EISDIR)
		write(2, ": Is a directory\n", 17);
	else if (ernum == ENOENT)
		write(2, ": No such file or directory\n", 28);
}

void	std_input(void)
{
	char *c;

	while (read(0, &c, 1))
		write(1, &c, 1);
}

void	std_output(int argc, char **argv)
{
	int		file;
	int		i;
	int		txt;
	char	buf[10000];

	i = 0;
	g_programname = basename(argv[0]);
	while (++i < argc)
	{
		file = open(argv[i], O_RDONLY);
		if (file == -1)
		{
			write_error(errno, argv[i]);
			close(file);
			continue;
		}
		while ((txt = read(file, buf, 10000)))
		{
			buf[txt] = '\0';
			write(1, buf, txt);
		}
		close(file);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		std_input();
	else
		std_output(argc, argv);
	return (0);
}
