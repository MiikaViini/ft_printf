#include  "libft.h"
#include <stdio.h>

static size_t	ft_lenint(long long int n)
{
	unsigned char	len;

	len = 1;
	// if (n < 0 )
	// {
	// 	if (n == -2147483648)
	// 		n = n + 1;
	// 	n = n * -1;
	// }
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

// static	int	ft_isminus(long long int n)
// {
// 	if (n >= 0)
// 		return (0);
// 	else
// 		return (1);
// }

// static	int	ft_remsign(long long int n)
// {
// 	if (n <= 0)
// 		return (n * -1);
// 	return (n);
// }

// static	int	ft_ismin(long long int n)
// {
// 	if (n == -2147483648)
// 		n = n + 1;
// 	return (n);
// }

char	*ft_ltoa(long long int n)
{
	char			*num;
	size_t			i;
	long long int	t;

	t = n;
	//printf("%lld", n);
	//n = ft_ismin(n);
	//n = ft_remsign(n);
	i = 0;
	num = (char *)malloc(sizeof(char) * (ft_lenint(t) + 1));
	if (!num)
		return (NULL);
	if (n == 0)
		num[i++] = '0';
	while (n > 0)
	{
		num[i++] = (n % 10) + '0';
		n = n / 10;
	}
	// if (t == -2147483648)
	// 	*num = *num + 1;
	// if (ft_isminus(t) == 1)
	// 	num[i++] = '-';
	num[i] = '\0';
	return (ft_strrev(num));
}
