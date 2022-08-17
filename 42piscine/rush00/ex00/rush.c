#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int rush(int b, int a)
{
	int i=0;
	int j=0;
	if(b<=2)
	{
		while(j < b)
		{
			ft_putchar('o');
			j++;
		}
		ft_putchar('\n');
	}
	else 
	{
		ft_putchar('o');
		while(j < b - 2)
		{
			ft_putchar('-');
			j++;
		}
		ft_putchar('o');
		ft_putchar('\n');
	}
	if(a == 1)
	{
		return (0);
	}
	else
	{
		while(i < a - 2)
		{
			if(b == 1)
			{
				ft_putchar('|');
				ft_putchar('\n');		
			}
			else
			{
				j = 0;
				ft_putchar('|');
				while(j < b-2)
				{
					ft_putchar(' ');
					j++;
				}
				ft_putchar('|');
				ft_putchar('\n');
			}
			i++;
		}
	}

	if(b <= 2)
	{
		j = 0;
		while(j < b)
		{
			ft_putchar('o');
			j++;
		}
	}
	else
	{
		j = 0;
		ft_putchar('o');
		while(j < b - 2)
		{
			ft_putchar('-');
			j++;
		}
		ft_putchar('o');
		ft_putchar('\n');
	}
	return (0);
}

int main(void)
{
	rush(5,3);
	return (0);
}
