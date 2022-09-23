#include "../cub3D.h"

size_t	ft_strlcpy_cub(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (size < 1)
		return (j);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	return (j);
}

int	count_char(char *str, char c)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

int	ft_atoi_v(const char *str, int *is_false)
{
	int						i;
	unsigned long long int	nb;

	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	if (nb > 2147483647)
		*is_false = 1;
	else
		*is_false = 0;
	return (nb);
}

int	verif_is_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] < '0' || str[i][j] > '9') && str[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
