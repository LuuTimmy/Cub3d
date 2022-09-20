#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*fstr;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	fstr = (char *) malloc (sizeof(char) * (len + 1));
	if (!fstr)
		return (NULL);
	while (*s1)
	{
		fstr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		fstr[i] = *s2;
		i++;
		s2++;
	}
	fstr[i] = '\0';
	return (fstr);
}
