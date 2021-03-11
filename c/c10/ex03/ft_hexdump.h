/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:16:53 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/09 21:16:57 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	print_error(char *msg, char *file_path, char *file_name);
void	ft_put_main(char *bufs, int c_flag, int until);

#endif
