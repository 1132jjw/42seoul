#include "do-op.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_nb(int nb)
{
	if (nb > 9)
	{
		print_nb(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb % 10 + '0');
}

void	cal(char **argv)
{
	int a;
	int b;
	void(*f)(int, int);

	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	printf("%c\n", argv[2][0]);
	if (argv[2][0] == '+')
		f = plus;
	else if (argv[2][0] == '-')
		f = minus;
	else if (argv[2][0] == '/')
		f = divide;
	else if (argv[2][0] == '*')
		f = multi;
	else if (argv[2][0] == '%')
		f = modulo;
	f(a, b);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 4)
		cal(argv);
	else
		write(1, "0", 1);
	return (0);
}