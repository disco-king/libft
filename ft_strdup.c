#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;
	int		count;

	len = ft_strlen(s1);
	str = (char *)malloc(len + 1);
	count = 0;
	if (str == NULL)
		return (str);
	while (count++ < len)
		*str++ = *s1++;
	*str = '\0';
	return (str - len);
}
