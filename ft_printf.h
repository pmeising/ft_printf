/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:47:08 by pmeising          #+#    #+#             */
/*   Updated: 2022/05/26 13:06:42 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa_hxd(unsigned long n, char a);
int		ft_hex_func_p(unsigned long n);
int		ft_hex(unsigned int n, int c);
char	*ft_itoa_u(unsigned int n);
int		ft_putperc(void);

#endif
