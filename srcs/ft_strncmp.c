#include "../include/pipex.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	size_t			i;

	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	i = 0;
	if (!n)
		return (0);
	while (cs2[i] && cs1[i] && i < n)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (cs1[i] - cs2[i]);
}