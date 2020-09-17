#include "operators.h"
#include "output.h"

void sum(int n1, int n2)
{
	ft_putnbr(n1 + n2);\
	ft_putchar('\n');
}

void sub(int n1, int n2)
{
	ft_putnbr(n1 - n2);
	ft_putchar('\n');
}

void mul(int n1, int n2)
{
	ft_putnbr(n1 * n2);
	ft_putchar('\n');
}

void div(int n1, int n2)
{
	if (n2 == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(n1 / n2);
	ft_putchar('\n');
}

void mod(int n1, int n2)
{
	if (n2 == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(n1 % n2);
	ft_putchar('\n');
}
