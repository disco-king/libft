#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		count;
	char		*dest;
	const char	*sorc;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = dst;
	sorc = src;
	count = 0;
	if (dest < sorc)
		return (ft_memcpy (dst, src, len));
	dest += len;
	sorc += len;
	while (len--)
		*--dest = *--sorc;
	return (dst);
}
