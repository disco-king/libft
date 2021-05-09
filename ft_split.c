#include "libft.h"

static int	word_count(char const *str, char spl)
{
	int	count;
	int	i;
	int	len;

	count = 0;
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != spl)
			len++;
		if (str[i] == spl && len != 0)
		{
			len = 0;
			count++;
		}
		i++;
	}
	if (len != 0)
		count++;
	return (count);
}

static int	word_len(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str != '\0' && *str != c)
	{
		count++;
		str++;
	}
	return (count);
}

static char	**clean_mem(char **ptr)
{
	char	**buff;

	buff = ptr;
	while (*ptr)
	{
		free (*ptr);
		*ptr = NULL;
		ptr++;
	}
	free (buff);
	buff = NULL;
	return (buff);
}

static char	**all_mem(char const *s, char c, char **ptr, int word_c)
{
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	ptr = (char **)malloc((word_c + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	while (i[0] < word_c)
	{
		if (*s != c && i[1] == 0)
		{
			ptr[i[0]] = malloc(word_len(s, c) + 1);
			if (ptr[i[0]] == NULL)
				return (clean_mem(ptr));
			ft_memcpy(ptr[i[0]], s, word_len(s, c));
			ptr[i[0]][word_len(s, c)] = '\0';
			i[0]++;
			i[1]++;
		}
		if (*s == c)
			i[1] = 0;
		s++;
	}
	ptr[i[0]] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		word_c;

	if (s == NULL)
		return (NULL);
	ptr = NULL;
	word_c = word_count(s, c);
	ptr = all_mem(s, c, ptr, word_c);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}
