#include "libft.h"

int word_count(char *str, char sep)
{
	int count = 0;
	int flag = 0;

	while(*str)
	{
		if(*str != sep && flag == 0)
		{
			count++;
			flag++;
		}
		if(*str == sep)
			flag = 0;
		str++;
	}
	return(count);
}

char	*getstr(char *s, char sep)
{
	char	*str;
	int	lim = 0;
	int i = 0;

	while (s[lim] && s[lim] != sep)
		lim++;
	str = (char *) malloc(lim + 1);
	if (str)
	{
		while (lim--)
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

char **free_all(char **ret)
{
	char **buff  = ret;

	while (*ret)
	{
		free(*ret);
		*ret = NULL;
		ret++;
	}
	free(buff);
	buff = NULL;
	return(buff);
}

char **ft_split(const char *s, char c)
{
	char *str = (char *)s;
	int count = word_count(str, c);
	char **ret;
	char *buff;

	if(count)
		ret = (char **)malloc((count + 1) * sizeof(char *));
	else
		return(NULL);
	ret[count] = NULL;
	count = 0;
	while(ret[count] != NULL)
	{
		while (*str == c)
			str++;
		buff = getstr(str, c);
		if (!buff)
			return (free_all(ret));
		ret[count] = buff;
		while(*str != c && *str)
			str++;
		count++;
	}
	return (ret);
}

