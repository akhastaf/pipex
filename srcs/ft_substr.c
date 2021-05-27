#include "../include/pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!(str = malloc(len + 1)))
		return (NULL);
	i = 0;
	j = len;
	while (s[start] != '\0' && i <= j - 1 && ft_strlen(s) >= start)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}