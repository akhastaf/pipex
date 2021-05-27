#include "../include/pipex.h"

static		int		ft_wordscount(const char *str, char c)
{
	int		i;
	int		wc;
	char	*s;

	s = (char*)str;
	i = 0;
	wc = 0;
	if (s[i] != c)
		wc++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			wc++;
		i++;
	}
	return (wc);
}

static	size_t		ft_wordlen(char *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i] != c && s[i])
	{
		j++;
		i++;
	}
	return (j);
}

static	void		*ft_dealocate(char ***tab, int i)
{
	while (i >= 0)
	{
		free((*tab)[i]);
		i--;
	}
	free(**tab);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;
	int		wc;
	size_t	len;

	i = 0;
	j = 0;
	if (!((char*)s))
		return (NULL);
	wc = ft_wordscount((char*)s, c);
	if (!(words = malloc((wc + 1) * sizeof(char*))))
		return (NULL);
	while (j < wc && ((char*)s)[i])
	{
		while (((char*)s)[i] == c && ((char*)s)[i])
			i++;
		len = ft_wordlen((char*)s, c, i);
		if (!(words[j] = ft_substr((char*)s, i, len)))
			return (ft_dealocate(&words, j));
		j++;
		i = i + len;
	}
	words[j] = NULL;
	return (words);
}