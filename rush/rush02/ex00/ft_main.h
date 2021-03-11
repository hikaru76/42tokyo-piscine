/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:54:11 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 18:31:16 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_putstr(char *str);
int		ft_str_is_numeric(char *str);
int		ft_strlen(char *str);
long	from_input_to_long(char *input_num);
int		input_num_error_check(char *input_num);
int		get_dict(char *input_dict, char *input_num);
int		write_error(void);
void	ft_fgets(char **buf_k, char **buf_v, char *num);
char	**ft_split(void);
int		value_error_check(char **key, char **value, int size);

#endif
