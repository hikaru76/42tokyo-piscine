/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:55:13 by hsakamot          #+#    #+#             */
/*   Updated: 2021/02/22 19:38:15 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int ans;

	if (nb < 0)
		return (0);
	i = 0;
	ans = 1;
	while (i < nb)
	{
		ans *= nb;
		nb -= 1;
	}
	return (ans);
}
