/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makemap1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:25:29 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/09 13:33:44 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	get_elems(t_map *t, char buf[100000])
{
	int cnt;
	int i;

	cnt = 0;
	i = -1;
	while (buf[++i] != '\n')
		cnt++;
	t->elems[0] = buf[cnt - 3];
	t->elems[1] = buf[cnt - 2];
	t->elems[2] = buf[cnt - 1];
}

int		cnt_new_lines(char buf[100000])
{
	int cnt;
	int i;

	cnt = 0;
	i = -1;
	while (buf[++i] != '\0')
		if (buf[i] == '\n')
			cnt++;
	return (cnt);
}

int		check_lines(char buf[100000])
{
	int		i;
	int		cnt_firstline;
	char	*number;

	i = -1;
	cnt_firstline = 0;
	while (buf[++i] != '\n')
		cnt_firstline++;
	if (cnt_firstline < 4)
		return (1);
	if (chars_check(buf, cnt_firstline))
		return (1);
	number = (char *)malloc(sizeof(char) * (cnt_firstline - 2));
	ft_strncpy(number, buf, cnt_firstline - 3);
	g_y = ft_atoi(number);
	return (0);
}

int		check_map_elements(char **map_elements, t_map *t)
{
	int i;
	int j;

	i = 0;
	while (map_elements[1][i] != '\0')
		i++;
	g_x = i;
	i = 0;
	while (map_elements[++i])
	{
		j = -1;
		while (map_elements[i][++j] != '\0')
		{
			if (map_elements[i][j] != t->elems[0] &&
				map_elements[i][j] != t->elems[1])
				return (1);
		}
		if (j != g_x)
			return (1);
	}
	if (i - 1 != g_y)
		return (1);
	return (0);
}

int		buf_to_map(t_map *t, char buf[100000])
{
	char	**map_elements;
	int		i;

	if (ft_strlen(buf) < 6)
		return (write_error());
	if (check_lines(buf))
		return (write_error());
	get_elems(t, buf);
	map_elements = ft_split(buf, "\n");
	if (check_map_elements(map_elements, t))
		return (write_error());
	i = -1;
	t->map = (char **)malloc(sizeof(char *) * g_y);
	while (++i < g_y)
	{
		t->map[i] = (char *)malloc(sizeof(char) * (g_x + 1));
		ft_strcpy(t->map[i], map_elements[i + 1]);
	}
	sub_main(t);
	free(map_elements);
	return (0);
}
