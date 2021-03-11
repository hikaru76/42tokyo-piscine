/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:54:11 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/07 23:08:48 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

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
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	**ft_split(void);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
void	trim(char *s);
int		value_error_check(char **key, char **value, int size);
int		ft_strcmp(char *s1, char *s2);
void	output_all(char *num_char, char **buf_k, char **buf_v);
void	ft_output(char **key, char **value, char *input_num);
void	output(char **num, int size);
int		decide_digit_set_two(char *input_num);
void	separate_num(char digit_set[4][3], char *input_num);
void	get_value(char **key, char **value, char *c);
void	select_value_ten(char **key, char **value, char d);
int		get_value_ten(char **key, char **value, char c, char d);
void	call_hundredset(char **key, char **value, char *c);
void	call_space(int i, int j);
void	call_space_two(int i, int j, int k);
void	hundred_space(char d_set[4][3], int i[3], char *c);
int		select_thousand(char **key, char **val, int i[3], char digit_set[4][3]);
void	hundred_put(char **key, char **value, char d_set[4][3], int i[3]);
void	ten_put(char **key, char **value, char d_set[4][3], int i[3]);
void	space_put_extra(char d_set[4][3], int i[3]);
void	do_extra(char d_set[4][3], int i[3]);
int		return_one(char **key, char **value, char *c);
int		get_value_ten(char **key, char **value, char c, char d);
void	hundred_space(char d_set[4][3], int i[3], char *c);
void	call_hundredset(char **key, char **value, char *c);
void	call_space(int i, int j);
void	call_space_two(int i, int j, int k);

extern int					g_dict;
extern int					g_txt;
extern unsigned int		g_num;
extern char				g_buf[100000];

#endif
