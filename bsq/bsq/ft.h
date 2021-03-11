/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakamot <hsakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 02:43:19 by hsakamot          #+#    #+#             */
/*   Updated: 2021/03/09 13:34:43 by hsakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <stdio.h>

typedef	struct	s_map
{
	char		elems[3];
	char		**map;
	int			ans;
	int			ans_x;
	int			ans_y;
}				t_map;

extern int		g_x;
extern int		g_y;

void			ft_putstr(char *str);
void			output(t_map *t);
char			*ft_strcat(char *dest, char *src);
int				ft_char_is_numeric(char c);
int				ft_char_is_printable(char c);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
char			*ft_strncpy(char *dest, char *src, int n);
char			*ft_strcpy(char *dest, char *src);
char			**ft_split(char *str, char *charset);
void			fill_map(t_map *t);
void			sub_main(t_map *t);
int				write_error(void);
int				input_map(char *filename, char buf[100000]);
void			std_input_map(char buf[100000]);
int				chars_check(char buf[100000], int cf);
char			*ft_strncat(char *dest, char *src, int nb);

#endif
