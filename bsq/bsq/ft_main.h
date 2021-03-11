/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 01:32:06 by dainoue           #+#    #+#             */
/*   Updated: 2021/03/09 01:59:49 by dainoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <stdio.h>

int		g_x;
int		g_y;
typedef struct		s_map
{
	char	elems[3];
	char	**map;
	int		ans;
	int		ans_x;
	int		ans_y;
}					t_map;

void				ft_putstr(char *str);
void				init(t_map *t);
void				output(t_map *t);
void				fill_map(t_map *t);
char				*ft_strcat(char *dest, char *src);
int					ft_char_is_numeric(char c);
int					ft_char_is_printable(char c);
int					ft_strlen(char *str);
int					ft_atoi(char *str);
char				*ft_strncpy(char *dest, char *src, int n);
char				*ft_strcpy(char *dest, char *src);
char				**ft_split(char *str, char *charset);
void				dp(int numap[g_y][g_x], t_map *t);
int					buf_to_map(t_map *t, char buf[100000]);
void				std_input_map(char buf[100000]);
int					input_map(char *filename, char buf[100000]);

#endif
