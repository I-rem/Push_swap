#include "push_swap.h"

int	ft_atoi(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
		if (result * sign > 2147483647) // We need a way to handle these errors
			return (-1);
		else if (result * sign < -2147483648)
			return (0);
	}
	return (result * sign);
}

int	arg_check(char *argv)
{
	int	i;
	int	sign;
	
	i = 0;
	sign = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '-' || argv[i] == '+')
		{
			sign++;
			if (sign > 1)
				return (0);
		}
		if (argv[i] < '0' || argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	order_check(char **argv)
{
	int	i;
	
	i = 2;
    while (argv[i] != NULL)
    {
        if (ft_atoi(argv[i]) < ft_atoi(argv[i - 1]))
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	
	if (argc > 2)
		if (arg_check(argv[1]))
		{
            if (!order_check(argv))
			{
                a = ft_lstnew(ft_atoi(argv[1]));
                argv += 2;
                while (*argv != NULL)
                {
                    ft_lstadd_back(&a, ft_lstnew(ft_atoi(*argv)));
                    argv++;
                }
                b = (t_list *)malloc(sizeof(t_list));
                if (argc <= 6)
                    little_sort(a, &b, argc);
                //else
                    //big_sort(a, argc);
                return (0);	
			}
		}
	return (0);
}

