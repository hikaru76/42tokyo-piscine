/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:28:48 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 18:29:00 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	trim(char *s)
{
	int i;
	int count;

	count = 0;
	if (s == NULL)
		return ;
	i = ft_strlen(s);
	while (--i >= 0 && s[i] == ' ')
		count++;
	s[i + 1] = '\0';
	i = 0;
	while (s[i] != '\0' && s[i] == ' ')
		i++;
	ft_strcpy(s, &s[i]);
}
