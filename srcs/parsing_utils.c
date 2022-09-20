#include "../cub3D.h"
#include "so_long/so_long.h"

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

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		nset;
	int		nsetend;
	char	*fdest;

	nset = 0;
	nsetend = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (verifset(s1[i++], set) == 1)
		nset++;
	i = ft_strlen(s1);
	while ((int)ft_strlen(s1) > nset && verifset(s1[--i], set) == 1)
		nsetend++;
	fdest = ft_substr(s1, nset, (ft_strlen(s1) - nset - nsetend));
	return (fdest);
}

int count_char(char *str, char c)
{
    int nb;
    int i;

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
