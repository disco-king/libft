#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	lim;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	lim = ft_strlen(&s[start]);
	if (len < lim)
		lim = len;
	str = (char *) malloc(lim + 1);
	if (str != NULL)
	{
		ft_memcpy(str, &(s[start]), lim);
		str[lim] = '\0';
	}
	return (str);
}
