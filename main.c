#include <unistd.h>
#include "operators.h"
#include "output.h"

void (*g_cal[5]) (int x, int y);

int is_space(char c)
{
	return (c == ' ' || c == '\n' || c == 'r'
		|| c == '\f' || c == '\t' || c == '\v');
}

int	ft_atoi(char *str)
{
	int		sign;
	unsigned int	res;

	sign = 1;
	res = 0;
	while (*str && is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res)
			res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * sign);
}

void do_op(int n1, char ope, int n2)
{
	if (ope == '+')
		(*g_cal[0])(n1, n2);
	else if (ope == '-')
		(*g_cal[1])(n1, n2);
	else if (ope == '*')
		(*g_cal[2])(n1, n2);
	else if (ope == '/')
		(*g_cal[3])(n1, n2);
	else if (ope == '%')
		(*g_cal[4])(n1, n2);
}

char judge_ope(char *str)
{
	if ((str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/' || str[0] == '%') && str[1] == '\0')
		return str[0];
	return 'n';
}

int	main(int ac, char **av)
{
	int n1;
	int n2;
	char ope;

	if (ac != 4)
		return (0);
	n1 = ft_atoi(av[1]);
	n2 = ft_atoi(av[3]);
	ope = judge_ope(av[2]);
	g_cal[0] = sum;
	g_cal[1] = sub;
	g_cal[2] = mul;
	g_cal[3] = div;
	g_cal[4] = mod;
	if (ope != 'n')
		do_op(n1, ope, n2);
	else
		ft_putstr("0\n");
	return (0);
}
