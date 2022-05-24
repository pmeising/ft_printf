/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:59:16 by pmeising          #+#    #+#             */
/*   Updated: 2022/05/23 18:31:46 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*s1;
	char	*substr;
	int		count;

	va_start(args, str);
	count = 0;
	if (!str)
		return (0);
	s1 = (char *)str;
	while (str && s1)
	{
		s1 = ft_strchr(str, '%');
		if (s1 == NULL)
		{
			count = count + ft_putstr((char *)str);
			return (count);
		}
		else
		{
			substr = ft_substr(str, 0, (s1 - str));
			count = count + ft_putstr(substr);
			free (substr);
		}
		if (s1[1] == 'c')
		{
			ft_putchar_fd(va_arg(args, int), 1);
			s1++;
			count++;
		}
		else if (s1[1] == 's')
		{
			count = count + ft_putstr(va_arg(args, char *));
			s1++;
		}
		else if (s1[1] == '%')
		{
			write(1, "%", 1);
			count++;
			s1++;
		}
		else if (s1[1] == 'i' || s1[1] == 'd')
		{
			substr = ft_itoa(va_arg(args, int));
			count = count + ft_putstr(substr);
			free (substr);
			s1++;
		}
		else if (s1[1] == 'u')
		{
			substr = ft_itoa_hxd((unsigned long)va_arg(args, unsigned int)); // hxd can be prototyped as unsigned long as input.
			count = count + ft_putstr(substr);
			free (substr);
			s1++;
		}
		else if (s1[1] == 'p')
		{
			ft_itoa_hxd(unsigned long)va_arg(args, void *);
		}
		str = s1 + 1;
	}
	return (count);
}



// need to shorten function, outsource the if statements.

int	main(void)
{
	int	length;

	length = ft_printf("Let's %s\nTest number: %d", "try this", 5.5);
	ft_printf("%d\n", length);
}
