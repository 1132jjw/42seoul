#include "do-op.h"

void	plus(int a, int b)
{
	print_nb(a + b);
}

void	minus(int a, int b)
{
	print_nb(a - b);
}

void	divide(int a, int b)
{
	if (b != 0)
		print_nb(a / b);
	else
		ft_putstr("Stop : division by zero");
}

void	multi(int a, int b)
{
	print_nb(a * b);
}

void	modulo(int a, int b)
{
	if (b != 0)
		print_nb(a % b);
	else
		ft_putstr("Stop : modulo by zero");
}
