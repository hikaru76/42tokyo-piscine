/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 01:04:51 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 18:30:14 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int					g_dict;
int					g_txt;
unsigned int		g_num;
char				g_buf[100000];

int		main(int argc, char **argv)
{
	char	**key;
	char	**value;
	int		i;

	if (argc < 2 || argc > 3)
		return (write_error());
	if (argc == 2)
		if (!get_dict("numbers.dict", argv[1]))
			return (write_error());
	if (argc == 3)
		if (!get_dict(argv[1], argv[2]))
			return (write_error());
	key = 0;
	value = 0;
	i = argc == 2 ? 1 : 2;
	ft_fgets(key, value, argv[i]);
	return (0);
}
