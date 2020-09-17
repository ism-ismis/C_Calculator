#include <unistd.h>
#include "output.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void print_nbr(unsigned int nb2)
{
    if (nb2 / 10 == 0)
        ft_putchar(nb2 + '0');
    else
    {
        print_nbr(nb2 / 10);
        ft_putchar(nb2 % 10 + '0');
    }
}

void ft_putnbr(int nb)
{
    unsigned int nb2;
    if (nb < 0)
    {
        ft_putchar('-');
        nb2 = -1 * nb;
    }
    else
        nb2 = nb;
    print_nbr(nb2);
}
