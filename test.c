/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 08:27:52 by pmeising          #+#    #+#             */
/*   Updated: 2022/05/24 19:12:47 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
		return ((char *)(&s[i]));
	return (NULL);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	count = 0;
	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		s_len;

	i = 0;
	s_len = ft_strlen(s);
	dest = malloc(1 * s_len + 1);
	if (dest == 0)
		return (NULL);
	while (i < s_len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	total_len;
	size_t	i;

	if (!s)
		return (NULL);
	if (!len || start >= (ft_strlen(s)))
		return (ft_strdup(""));
	substr = malloc(len * sizeof(char) + 1);
	if (substr == 0)
		return (NULL);
	total_len = start + len;
	i = 0;
	while (start < total_len)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = 0;
	return (substr);
}

static char	*ft_zero_case(int n)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[n] = 48;
	str[1] = '\0';
	return (str);
}

static int	ft_alen(int n)
{
	int	j;

	j = 0;
	while (n != 0)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

static int	ft_alen_u(unsigned int n)
{
	int	j;

	j = 0;
	while (n != 0)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

static char	*ft_logic(char *str, int m, int j, int i)
{
	if (m == -2147483648)
	{
		m = -214748364;
		str[j] = (8 + 48);
		j--;
	}
	if (m > -2147483648 && m < 0)
		m = i * m;
	while (m != 0 && j >= 0)
	{
		str[j] = ((char )((m % 10)) + 48);
		m = m / 10;
		j--;
	}
	if (i < 0)
		str[0] = '-';
	return (str);
}

static char	*ft_logic_u(char *str, unsigned int m, int j, int i)
{
	while (j >= 0)
	{
		str[j] = ((char )((m % 10)) + 48);
		m = m / 10;
		j--;
	}
	if (i < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;
	int		m;

	i = 0;
	j = 0;
	m = n;
	if (n == 0)
		return (ft_zero_case(n));
	j = ft_alen(n);
	if (m < 0)
	{
		j++;
		i = -1;
	}
	str = malloc(1 * (j + 1));
	if (!str)
		return (NULL);
	str[j] = '\0';
	j--;
	str = ft_logic(str, m, j, i);
	return (str);
}

char	*ft_itoa_u(unsigned int n)
{
	char			*str;
	int				i;
	int				j;
	unsigned int	m;

	i = 0;
	j = 0;
	m = n;
	if (n == 0)
		return (ft_zero_case(n));
	j = ft_alen_u(n);
	str = malloc(1 * (j + 1));
	if (!str)
		return (NULL);
	str[j] = '\0';
	j--;
	str = ft_logic_u(str, m, j, i);
	return (str);
}

void	ft_write_hxd(int nbr, int c)
{
	int	upper;
	int	lower;

	upper = nbr + 55;
	lower = nbr + 87;
	if (c == 'x' || c == 'p')
		write(1, &lower, 1);
	else if (c == 'X')
		write(1, &upper, 1);
}

int	ft_putnbr_hxd(unsigned long n, int c)
{
	int	nbr;
	int	count;
	int	ch;

	count = 0;
	nbr = n % 16;
	if (n >= 16)
	{
		n = n / 16;
		if (n > 0)
			ft_putnbr_hxd(n, c);
	}
	if (nbr >= 10 && (c == 'x' || c == 'X' || c == 'p'))
	{
		ft_write_hxd(nbr, c);
	}
	else
	{
		ch = nbr + 48;
		write(1, &ch, 1);
	}
	count++;
	return (count);
}

int	ft_count(unsigned long n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_hex_functions(unsigned long n, int c)
{
	unsigned long	count;

	count = 0;
	if (c == 'p')
	{
		write(1, "0x", 2);
		count = 2;
	}
	count += ft_count(n);
	ft_putnbr_hxd(n, c);
	return (count);
}

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
			substr = ft_itoa_u((unsigned int)va_arg(args, unsigned int));
			count = count + ft_putstr(substr);
			free (substr);
			s1++;
		}	
		else if (s1[1] == 'x')
		{
			count = count + ft_hex_functions(va_arg(args, unsigned int), 'x');
			s1++;
		}
		else if (s1[1] == 'X')
		{
			count = count + ft_hex_functions((unsigned long)va_arg(args, unsigned long), 'X');
			s1++;
		}
		else if (s1[1] == 'p')
		{
			count = count + ft_hex_functions((unsigned long)va_arg(args, unsigned long), 'p');
			s1++;
		}
		str = s1 + 1;
	}
	return (count);
}

int	main(void)
{
	int	length;
	unsigned long	x;
	unsigned long	*ptr;

	x = 23983;
	ptr = &x;
	// length = ft_printf("Let's %s of %d, which is: %X. This %c is stored at %p.\n", "try hexadecimal", x, x, 86, ptr);
	length = ft_printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", 65, "is first", ptr, x, x, -21474836488, x, x);
	printf("%d\n", length);
}

// // found issue that it doesn't count the Newline character in "count".